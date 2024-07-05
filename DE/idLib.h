#pragma once

#include <windows.h>
#include <string>
#include "../Config/Config.h"
#include "GeneratedEnums.h"


//? this file should be remaned to smth else like idLibBasics or somthing like that as it's now almost a duplicate with generatedClasses.h

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

struct idStrId {
    //Offset 0,	 size 4	
    unsigned int id;
};

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


// idMaterial2 : idDeclTypeInfo : idDecl : idResource
class idMaterial2 {
public:
    char pad_0[880]; // offset: 0h (0d) size: 880
    unsigned short MaterialIndex; // offset: 370h (880d)  size: 2
    char pad_End[38]; // offset: 372h (882d) size: 38
}; // size: 920




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


    //struct __declspec(align(8)) cvarData_t
    //{
    //    char* valueString;                   // Offset: 0x00
    //    int valueInteger;                    // Offset: 0x08
    //    float valueFloat;                    // Offset: 0x0C
    //    long long valueGameTime;             // Offset: 0x10
    //    __declspec(align(8)) float valueSeconds;  // Offset: 0x18
    //    int valueMilliseconds;              // Offset: 0x20
    //    long long valueMicroseconds;         // Offset: 0x24
    //    char* name;                          // Offset: 0x2C
    //    char* resetString;                   // Offset: 0x34
    //    char* description;                   // Offset: 0x3C
    //    int flags;                           // Offset: 0x44
    //    float valueMin;                      // Offset: 0x48
    //    float valueMax;                      // Offset: 0x4C
    //    char** valueStrings;                 // Offset: 0x50
    //    void* valueCompletion;               // Offset: 0x58
    //    idCVar::cvarCallback_t* onChange;    // Offset: 0x60
    //    //void call_onchange_functions();   // Offset: 0x68
    //};

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





class idStr {
public:
    char pad_0[8]; // offset: 0h (0d) size: 8
    char* data; // offset: 8h (8d)  size: 8
    int len; // offset: 10h (16d)  size: 4
    int allocedAndFlag; // offset: 14h (20d)  size: 4
    char baseBuffer[20]; // offset: 18h (24d)  size: 20
    char pad_End[4]; // offset: 2Ch (44d) size: 4
}; // size: 48


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

	void print() {
		logInfo("print:  x: %.2f, y: %.2f, w: %.2f, h: %.2f,", x, y, w, h);
	}

	std::string getStrData() {
		return "x: " + std::to_string(x) + " y: " + std::to_string(y) + " w: " + std::to_string(w) + " h: " + std::to_string(h);
	}

	void printMsg(std::string str) {
		logInfo("printMsg: %s:  x: %.2f, y: %.2f, w: %.2f, h: %.2f,", str.c_str(), x, y, w, h);
	}
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


	void print() {
		logInfo("swfFillStyle_t print: type: %u subType: %u  bitmapID: %hu startColor: r:%u g:%u b:%u a:%u endColor: r:%u g:%u b:%u a:%u", type, subType, bitmapID, startColor.r, startColor.g, startColor.b, startColor.a, endColor.r, endColor.g, endColor.b, endColor.a);
	}
};




