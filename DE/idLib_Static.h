#pragma once

#include <windows.h>
#include <string>
#include "enumsCustom.h"
#include "../Config.h"



/// 2/9/24 this file is a collection of classes from the idLib but they are considered very unlikely to change in a future update and their data is (currently) common to Doom Eternal Vanilla and Sandbox. 

//struct idStr {
//	char pad_K_000;
//	//Offset 8,	 size 8
//	char* data;
//	//Offset 16,	 size 4
//	int len;
//	//Offset 20,	 size 4
//	//top bit is used to store a flag that indicates if the string data is static or not
//	int allocedAndFlag;
//	//Offset 24,	 size 20
//	char baseBuffer[20] ;
//};

//struct idStrId {
//    //Offset 0,	 size 4	
//    unsigned int id;
//};

//! this is a basic version of the list you will have to take into account the list element size, as it could be list of  pointers or it could be list of 23412 size structs
struct idList
{
    unsigned __int64* list;
    int num;
    int size;
    __int16 granularity;
    unsigned __int8 memTag;
    unsigned __int8 listStatic;
};


struct idAtomicString {
    //Offset 0,	 size 8
    char* str;
};


//! EVENTS

struct idEventDef {
    //Offset 0x0 	Size 0x8 (8)
    char* name;
    //Offset 0x8 	Size 0x8 (8)
    char* formatspec;
    //Offset 0x10 	Size 0x8 (8)
    char* argTypes; // type is a eventArgType_t
    //Offset 0x18 	Size 0x8 (8)
    char* argNames;
    //Offset 0x20 	Size 0x8 (8)
    char* argDefaultValues;
    //Offset 0x28 	Size 0x4 (4)
    int returnType;
    //Offset 0x2C 	Size 0x4 (4)
    int numargs;
    //Offset 0x30 	Size 0x4 (4)
    int numstrings;
    //Offset 0x34 	Size 0x4 (4)
    int eventnum;
    //Offset 0x38 	Size 0x4 (4)	 see eventFlags_t for description of individual flags.
    int flags;
    //Offset 0x3C 	Size 0x4 (4)
    eventType_t type;  // enum in lib
    //Offset 0x40 	Size 0x8 (8)
    char* timelineEventGroup;
    //Offset 0x48 	Size 0x8 (8)
    char* comment;
    //Offset 0x50 	Size 0x8 (8)
    idEventDef* noticeEvent;
    //Offset 0x58 	Size 0x8 (8)
    idEventDef* next;
}; // Size: 0x60 (Size Dec: 96)


//! CMDS:

struct commandDef_s {
    //Offset 0x0 	Size 0x8 (8)
    char* name;
    //Offset 0x8 	Size 0x8 (8) void(const idCmdArgs& args)* function;
    void* function;
    //Offset 0x10 	Size 0x8 (8)  void(idAutoComplete& autoComplete)* argCompletion
    void* argCompletion;
    //Offset 0x18 	Size 0x8 (8)
    char* description;
    //Offset 0x20 	Size 0x4 (4)
    int flags;
}; // Size: 0x28 (Size Dec: 40)



//! CVARS:
struct __declspec(align(8)) idCVar
{
    struct cvarCallback_t
    {
        struct idCallback* callback;
        idCVar::cvarCallback_t* next;
    };

    struct __declspec(align(8)) cvarData_t
    {
        char* valueString;
        int valueInteger;
        float valueFloat;
        long long valueGameTime;
        __declspec(align(8)) float valueSeconds;
        int valueMilliseconds;
        long long valueMicroseconds;
        char* name;
        char* resetString;
        char* description;
        int flags;
        float valueMin;
        float valueMax;
        char** valueStrings;
        void* valueCompletion;
        idCVar::cvarCallback_t* onChange;
        //void call_onchange_functions();
    };


    idCVar::cvarData_t* data;
    idCVar::cvarData_t dataStorage;
    //Offset 0x70 	Size 0x8 (8)
    idCVar* next;


    /*static idCVar* Find(const char* name);

    static idCVar** GetList(unsigned& out_n);


    static void generate_name_table();

    static void get_cvardata_rvas();*/

};



//types def from meathook: 
#pragma pack(push, 1)
struct enumValueInfo_t {
    //offset 0 , size 8
    char* name;
    //offset 8 , size 4
    long long value;

};
struct enumTypeInfo_t {
    //offset 0 , size 8
    char* name;
    //offset 8 , size 4
    unsigned long long flags;
    int type;
    int valueIndexLength;

    //offset 16 , size 8
    enumValueInfo_t* values;
    int* valueIndex;
};
struct typedefInfo_t {
    char* name;
    char* type;
    char* ops;
    int size;
    int padding;
};
struct classMetaDataInfo_t
{
    char* metaData;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct classVariableInfo_t
{
    char* type;
    char* ops;
    char* name;
    int offset;
    int size;
    int flags;
    //char pad36[4];
    int m_mh_added_delta2type; //delta to FindClassInfo(type)
    char* comment;//i dont think anything in the engine actually uses comment, so i might be able to pack it into a delta and put more data here if i ever need it
    int (*get)(void* ptr);
    //offset 56 , size 8
    void (*set)(void* ptr, int value);
    //offset 64 , size 8
    void* (*reallocate)(void* ptr, const int oldNum, const int newNum, const int tag, const bool zeroBuffer);

};

#pragma pack(pop)
struct idClass;
struct idRenderModel;
struct idDeclModelAsset;

#pragma pack(push, 1)

/*
    we replace all classes metaData pointers with pointers to the one in here.
    then we just recast to be able to search for a fields index. when you have the index you can just look it up in variables
*/
struct mh_classtypeextra_t {

    classMetaDataInfo_t m_metadata;

    //
    unsigned m_num_fields;

    unsigned m_offset2fields; //add to this to get base of field props
};

struct classTypeInfo_t
{
    char* name;
    char* superType;
    int size;

    //char pad20[4];
    //this is padding in the engine originally, but we co-opt it to store the byte delta from the start of this class to
    //the start of its super class, allowing us to traverse the inheritance chain without having to go through findclassinfo's hashing and searching
    //this could be made to be fewer bits if i need other stuff in here in the future
    //also, it could be shifted to the right by 3 to make room for more bits since it should always be 8 byte aligned
    int m_mh_added_delta2super;
    classVariableInfo_t* templateParms;
    classVariableInfo_t* variables;
    unsigned long long* variableNameHashes;

    idClass* (*createInstance)();
    idRenderModel* (*createModel)(const idDeclModelAsset* modelAsset, const unsigned int createFlags);
    classMetaDataInfo_t* metaData;
};
#pragma pack(pop)

struct idClass;
template<typename T>
struct  idHierarchy
{
    idHierarchy<T>* parent;
    idHierarchy<T>* sibling;
    idHierarchy<T>* child;
    T* owner;
};

struct __declspec(align(8)) idTypeInfo
{
    char* classname;
    char* superclass;
    void* Spawn;
    char gap18[16];
    idClass** CreateInstance;
    idClass*** CreateCloneInstance;
    idClass*** PlacementCreateInstance;
    void** Destruct;
    void* VerifyPrototypeMacro;
    idTypeInfo* super;
    idTypeInfo* next;
    bool isAbstract;
    bool initialized;
    int size;
    int typeNum;
    int lastChild;
    idHierarchy<idTypeInfo> node;
};


//! this is at **m_typeInfoToolsPtrAddr
struct typeInfoGenerated_t {
    //Offset 0,	 size 8
    enumTypeInfo_t* enums;
    //Offset 8,	 size 4
    int numEnums;
    //Offset 0x10,	 size 8
    classTypeInfo_t* classes;
    //Offset 0x18,	 size 4
    int numClasses;
    //Offset 0x20,	 size 8
    typedefInfo_t* typedefs;
    //Offset 0x28,	 size 4
    int numTypedefs;
}; // size 0x48 (because 8 bytes aligned)


//? the size of this struct will not be write as i can not find any info about it, however it should be ok as it should not be part of any other struct or at least IT MUST NOT BE.
//! created by me as no def in idlib.
struct idTypeInfoTools {
    //Offset 0x0,	 size 8
    typeInfoGenerated_t* typeInfoGenerated;
};


//class idStr {
//public:
//    char pad_0[8]; // offset: 0h (0d) size: 8
//    char* data; // offset: 8h (8d)  size: 8
//    int len; // offset: 10h (16d)  size: 4
//    int allocedAndFlag; // offset: 14h (20d)  size: 4
//    char baseBuffer[20]; // offset: 18h (24d)  size: 20
//    char pad_End[4]; // offset: 2Ch (44d) size: 4
//}; // size: 48


struct idManagedClassPtr_idEntity {
	//Offset 0x0 	Size 0x4 (4)
	int spawnId;
	//Offset 0x4 	Size 0x4 (4)	 The spawnid that we just serialized into the client. It's held until PostSerializeRead, where it is then officially set.
	int serializedSpawnId;
	//Offset 0x8 	Size 0x8 (8) idEntity* ptr;
	void* entity_ptr;
	//Offset 0x10 	Size 0x8 (8)
	idManagedClassPtr_idEntity* next; //? this will be null for the ones in playerInventory
	//Offset 0x18 	Size 0x8 (8)
	idManagedClassPtr_idEntity* prev; //? this will be null for the ones in playerInventory
}; // Size: 0x20 (Size Dec: 32)



//! 1/8/24 keeping manual def of idResource and idResourceList cause not everything is documented and we have defined custom vars as well. Will have to check them in case of update but very unlikely those get changed.
class idResource {
public:
    char pad_0[8]; // offset: 0h (0d) size: 8
    idAtomicString name; // offset: 8h (8d)  size: 8   
    void* resourceListPtr; // offset: 10h (16d)  size: 8  // resourceList_t
    char pad_24[32]; // offset: 18h (24d) size: 32
    unsigned long long resourceID; // offset: 38h (56d)  size: 8
    char pad_End[24]; // offset: 40h (64d) size: 24
}; // size: 88



//? it's not documented cause it's a something you get with getResourceFromidResourceList_t_MB_A511B0
//! using this only for a specific function that i'm too tired to rewrite,  otherwise we use m_getResourceFp from idResourceListManager
struct resourceList_t_K {
    //Offset 0x0
    char* typeName;
    //Offset 0x8
    char* className;
    //Offset 0x10
    char pad1[24];
    //Offset 0x28
    idList unknownList;
    //Offset 0x40
    idList declList; //? i suppose it could other than decls here (?)
    //! this struct is surely longer but there is no way to know how long for sure.

};


struct idResourceList {
    char pad0[8];
    //Offset 0x8 	Size 0x8 (8)
    resourceList_t_K* resourceList; //resourceList_t* resourceList;
    //Offset 0x10 	Size 0x8 (8)
    char* typeName;
    //Offset 0x18 	Size 0x8 (8)
    char* className;
    //Offset 0x20 	Size 0x8 (8)
    idResourceList* next;
    //Offset 0x28 	Size 0x8 (8)
    void* callBack; //void(idResourceList* const resourceList)* postInitCallback;
}; // Size: 0x30 (Size Dec: 48)



struct swfRect_t;


struct idVec3 {
	float x = 0;
	float y = 0;
	float z = 0;

	float Distance(idVec3& other) {

		float xx = x - other.x;
		float yy = y - other.y;
		float zz = z - other.z;
		xx *= xx;
		yy *= yy;
		zz *= zz;

		return sqrtf(xx + yy + zz);

	}

	void Set(float val) {
		x = val;
		y = val;
		z = val;
	}
};
struct idVec2 {
	float x = 0;
	float y = 0;

	void set(float _x, float _y) {
		x = _x;
		y = _y;
	}

};


struct idMat3 {
	//Offset 0x0 	Size 0x24 (36)	 matrix
	idVec3 mat[3];
}; // Size: 0x24 (Size Dec: 36)

//struct swfRect_t {
//	//Offset 0,	 size 8
//	idVec2 tl;
//	//Offset 8,	 size 8
//	idVec2 br;
//
//	swfRect_t() {}
//
//	swfRect_t(float x, float y, float w, float h)
//	{
//		tl.x = x;
//		tl.y = y;
//		br.x = x + w;
//		br.y = y + h;
//	}
//	float getWidth() {
//		return br.x - tl.x;
//	}
//	float getHeight() {
//		return br.y - tl.y;
//	}
//};


struct swfRect_t {
	//Offset 0,	 size 8
	idVec2 tl;
	//Offset 8,	 size 8
	idVec2 br;

	swfRect_t() {}

	swfRect_t(float x, float y, float w, float h)
	{
		tl.x = x;
		tl.y = y;
		br.x = x + w;
		br.y = y + h;
	}
	float getWidth() {
		return br.x - tl.x;
	}
	float getHeight() {
		return br.y - tl.y;
	}

	float getLeft() {
		return tl.x;
	}

	float getRight() {
		return br.x;
	}

	float getTop() {
		return tl.y;
	}

	float getBottom() {
		return br.y;
	}


	// Setters for dimensions and positions
	void setWidth(float newWidth) {
		br.x = tl.x + newWidth; // Adjust the right edge based on the new width
	}

	void setHeight(float newHeight) {
		br.y = tl.y + newHeight; // Adjust the bottom edge based on the new height
	}

	void setLeft(float newLeft) {
		float width = getWidth();
		tl.x = newLeft;
		br.x = newLeft + width;
	}

	void setTop(float newTop) {
		float height = getHeight();
		tl.y = newTop;
		br.y = newTop + height;
	}

	void setPosition(float x, float y) {
		float width = getWidth();
		float height = getHeight();
		tl.x = x;
		tl.y = y;
		br.x = x + width;
		br.y = y + height;
	}

	void setPosition_Y(float y) {
		float height = getHeight();
		tl.y = y;
		br.y = y + height;
	}

	//? edu: this will not work, because you modify tl.Y so getHeight() is not right anymore....
	/*void setPosition_Y(float y) {
		tl.y = y;
		br.y = y + getHeight();
	}*/


	swfRect_t getRectScaled(float scale) {
		float newWidth = getWidth() * scale;
		float newHeight = getHeight() * scale;

		// Adjust x and y by half the difference in width and height
		float offsetX = (newWidth - getWidth()) / 2;
		float offsetY = (newHeight - getHeight()) / 2;

		float newX = tl.x - offsetX;
		float newY = tl.y - offsetY;

		return swfRect_t(newX, newY, newWidth, newHeight);
	}

	swfRect_t getRectScaledV2(float scale) {
		float absScale = std::abs(scale);
		float newWidth = getWidth() * absScale;
		float newHeight = getHeight() * absScale;

		// Adjust x and y by half the difference in width and height
		float offsetX = (getWidth() - newWidth) / 2;
		float offsetY = (getHeight() - newHeight) / 2;

		// Calculate new coordinates based on whether scale is positive or negative
		float newX = tl.x + offsetX;
		float newY = tl.y + offsetY;

		return swfRect_t(newX, newY, newWidth, newHeight);
	}


	//swfRect_t getRectScaledV2(float scale) {
	//	float newWidth = getWidth() * std::abs(scale);  // Ensures scaling works symmetrically
	//	float newHeight = getHeight() * std::abs(scale);

	//	// Adjust x and y by half the difference in width and height
	//	float offsetX = (newWidth - getWidth()) / 2.0f;
	//	float offsetY = (newHeight - getHeight()) / 2.0f;

	//	float newX = (scale >= 0) ? tl.x - offsetX : tl.x + offsetX;
	//	float newY = (scale >= 0) ? tl.y - offsetY : tl.y + offsetY;

	//	return swfRect_t(newX, newY, newWidth, newHeight);
	//}

	swfRect_t getRectOutlineBounds(float outlineThickness) {
		float newX = tl.x - outlineThickness;
		float newY = tl.y - outlineThickness;
		float newWidth = getWidth() + 2 * outlineThickness;
		float newHeight = getHeight() + 2 * outlineThickness;

		return swfRect_t(newX, newY, newWidth, newHeight);
	}

	//! just offseted on x/y
	swfRect_t getTextOutlineBounds(float outlineThickness) {
		float newX = tl.x - outlineThickness;
		float newY = tl.y - outlineThickness;

		return swfRect_t(newX, newY, getWidth(), getHeight());
	}

	//std::string getDbgInfoStr() {
	//	std::string resultStr;
	//	resultStr += "tlx: " + K_Utils::toStringWithPrecision(tl.x, 2);
	//	resultStr += " tly: " + K_Utils::toStringWithPrecision(tl.y, 2);
	//	resultStr += " brx: " + K_Utils::toStringWithPrecision(br.x, 2);
	//	resultStr += " bry: " + K_Utils::toStringWithPrecision(br.y, 2);
	//	resultStr += " width: " + K_Utils::toStringWithPrecision(getWidth(), 2);
	//	resultStr += " height: " + K_Utils::toStringWithPrecision(getHeight(), 2);
	//	return resultStr;
	//}

};


struct idVec4 {
	float x = 0;
	float y = 0;
	float w = 0;
	float h = 0;


	idVec4(){}

	idVec4(float _x, float _y, float _w, float _h) {
		x = _x;
		y = _y;
		w = _w;
		h = _h;
	}

	idVec4(swfRect_t swfRect) {
		x = swfRect.tl.x;
		y = swfRect.tl.y;
		w = swfRect.br.x - swfRect.tl.x;
		h = swfRect.br.y - swfRect.tl.y;
	}

	void update(float _x, float _y, float _w, float _h) {
		x = _x;
		y = _y;
		w = _w;
		h = _h;
	}

	/*void print() {
		logInfo("print:  x: %.2f, y: %.2f, w: %.2f, h: %.2f,", x, y, w, h);
	}

	std::string getStrData() {
		return "x: " + std::to_string(x) + " y: " + std::to_string(y) + " w: " + std::to_string(w) + " h: " + std::to_string(h);
	}

	void printMsg(std::string str) {
		logInfo("printMsg: %s:  x: %.2f, y: %.2f, w: %.2f, h: %.2f,", str.c_str(), x, y, w, h);
	}*/
};

struct idVec4_Bounds {
	float tl_x = 0;
	float tl_y = 0;
	float br_x = 0;
	float br_y = 0;
};



struct  idQuat {
	//Offset 0,	 size 4
	//METASTATE|ALLOCATOR|SAVESKIP
	//x-component
	float x;
	//Offset 4,	 size 4
	//METASTATE|ALLOCATOR|SAVESKIP
	//y-component
	float y;
	//Offset 8,	 size 4
	//METASTATE|ALLOCATOR|SAVESKIP
	//z-component
	float z;
	//Offset 12,	 size 4
	//METASTATE|ALLOCATOR|SAVESKIP
	//w-component
	float w;
};



//! this is from the swfFillStyle_t.h file

struct  swfMatrix_t {
	//Offset 0,	 size 4
	float xx;
	//Offset 4,	 size 4
	float yy;
	//Offset 8,	 size 4
	float xy;
	//Offset 12,	 size 4
	float yx;
	//Offset 16,	 size 4
	float tx;
	//Offset 20,	 size 4
	float ty;
};


struct  swfColorRGB_t {
	//Offset 0,	 size 1
	unsigned char r;
	//Offset 1,	 size 1
	unsigned char g;
	//Offset 2,	 size 1
	unsigned char b;
};

struct  swfColorRGBA_t : public swfColorRGB_t {
	//Offset 3,	 size 1
	unsigned char a;
};


struct  swfGradientRecord_t {
	//Offset 0,	 size 1
	unsigned char startRatio;
	//Offset 1,	 size 1
	unsigned char endRatio;
	//Offset 2,	 size 4
	swfColorRGBA_t startColor;
	//Offset 6,	 size 4
	swfColorRGBA_t endColor;
};


struct swfGradient_t {
	//Offset 0,	 size 1
	unsigned char numGradients;
	//Offset 1,	 size 160
	swfGradientRecord_t gradientRecords[16];
};



struct  swfFillStyle_t {
	//Offset 0,	 size 1
	//0 = solid, 1 = gradient, 4 = bitmap
	unsigned char type;
	//Offset 1,	 size 1
	//0 = linear, 2 = radial, 3 = focal; 0 = repeat, 1 = clamp, 2 = near repeat, 3 = near clamp
	unsigned char subType;
	//Offset 2,	 size 4
	//if type = 0   <<<<<<<<<<<<<<<<<<<<------------
	swfColorRGBA_t startColor;
	//Offset 6,	 size 4
	//if type = 0 <<<<<<<<<<<<<<<<<<<<------------
	swfColorRGBA_t endColor;
	//Offset 12,	 size 24
	//if type > 0
	swfMatrix_t startMatrix;
	//Offset 36,	 size 24
	//if type > 0
	swfMatrix_t endMatrix;
	//Offset 60,	 size 161
	//if type = 1
	swfGradient_t gradient;
	//Offset 224,	 size 4
	//if type = 1 and subType = 3
	float focalPoint;
	//Offset 228, 0xE4	 size 2
	//if type = 4
	unsigned short bitmapID;


	/*void print() {
		logInfo("swfFillStyle_t print: type: %u subType: %u  bitmapID: %hu startColor: r:%u g:%u b:%u a:%u endColor: r:%u g:%u b:%u a:%u", type, subType, bitmapID, startColor.r, startColor.g, startColor.b, startColor.a, endColor.r, endColor.g, endColor.b, endColor.a);
	}*/
};



struct idColor {
	float r, g, b, a;
	int PackColor() const
	{
		int v1; // edx
		unsigned __int8 v2; // al
		int v3; // er9
		int v4; // edx
		unsigned __int8 v5; // al
		int v6; // er8
		int v7; // edx
		unsigned __int8 v8; // al
		int v9; // edx
		int v10; // ecx
		unsigned __int8 v11; // al

		v1 = (int)(float)(this->r * 255.0);
		if (v1 >= 0)
		{
			v2 = (int)(float)(this->r * 255.0);
			if (v1 > 255)
				v2 = -1;
		}
		else
		{
			v2 = 0;
		}
		v3 = v2;
		v4 = (int)(float)(this->g * 255.0);
		if (v4 >= 0)
		{
			v5 = (int)(float)(this->g * 255.0);
			if (v4 > 255)
				v5 = -1;
		}
		else
		{
			v5 = 0;
		}
		v6 = v5;
		v7 = (int)(float)(this->b * 255.0);
		if (v7 >= 0)
		{
			v8 = (int)(float)(this->b * 255.0);
			if (v7 > 255)
				v8 = -1;
		}
		else
		{
			v8 = 0;
		}
		v9 = v8;
		v10 = (int)(float)(this->a * 255.0);
		if (v10 >= 0)
		{
			v11 = v10;
			if (v10 > 255)
				v11 = -1;
		}
		else
		{
			v11 = 0;
		}
		return v3 | ((v6 | ((v9 | (v11 << 8)) << 8)) << 8);
	}

	/*void set(float _r, float _g, float _b, float _a) {
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}*/
};


//! 3/11/24 putting idMaterial2 in static cause i need it there and it's the same in sand and van.
// idMaterial2 : idDeclTypeInfo : idDecl : idResource
struct idMaterial2 {
	// Offset: 0x0 (0d) Size: 0x370 (880d)
	char pad_0[880];
	// Offset: 0x370 (880d)  Size: 0x2 (2d)
	unsigned short MaterialIndex;
	// Offset: 0x372 (882d) Size: 0x26 (38d)
	char pad_End[38];
}; // size: 0x398 (Size Dec: 920)





//! because those are not listed in idLib we still have to declare them dynamically in this....idLib_Static file...

#ifdef GAME_VERSION_SANDBOX

//! unfortunately no definition of it in idLib. inspired by wolf2
struct idRenderModelGui {
	char pad_0[0x4E0];
	unsigned int currentVertexColor; //! sig: 8B 87 ? ? ? ? 4B 8D 0C 40 F3 0F 10 AD or check 622D11 in ida rev2.

}; // size: ????


#else

//? not using whiteMaterial in debug hud as it can be not null.
//struct idDebugHUDLocal {
//	char pad_0[0x60];
//	idMaterial2* whiteMaterial;
//};

//! unfortunately no definition of it in idLib. inspired by wolf2
struct idRenderModelGui {
	char pad_0[0x4D0];
	unsigned int currentVertexColor; //! sig: 8B 87 ? ? ? ? 4B 8D 0C 40 F3 0F 10 AD or check 622D11 in ida rev2.

}; // size: ????


#endif


//! 3/11/24 this is used for idFont* idResourceListManager::find_idFont(std::string fontNameStr) because the resource list of idFonts is not just font pointers and as i can't find this struct in idLib i have to create it here.
struct idFontResContainer {
	int unknown0;
	int unknown1;
	int unknown2;
	int unknown3;
	//idFont* font;
	void* fontVoidPtr; //! void* cause can not define idFont in static lib
};


