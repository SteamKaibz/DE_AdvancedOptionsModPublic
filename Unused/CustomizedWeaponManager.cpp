#include "CustomizedWeaponManager.h"


void CustomizedWeaponManager::initWeapons() {

    acquireDefaultCustomizedWeapons();

    if (!loadCustomWeaponsFromFile()) {
        logWarn("initWeapons: could not load custom weapons from file, using default weapons...");
        m_customizedWeaponVec = m_defaultCustomizedWeaponVec;
    }
    //! saving everytime, so that if the structure has changed user has latest file version.
    saveCustomWeaponsToFile();
}

//! make sure to trigger that once game is init obviously...and then everytime a level launch as it will not overwrite any existing default weapons(?)...........
void CustomizedWeaponManager::acquireDefaultCustomizedWeapons()
{
    int addedCounter = 0;

    //! get currated list
    std::vector<idDeclWeapon*> customizableDeclWeaponPtrVec = idResourceListManager::getCustomizableDeclWeaponsPtrsVec();

   //! we don't clear the m_defaultCustomizedWeaponVec here cause there may be weapons which are not yet acquired when this function triggers and we want to make sure we don't acquire the same decl with same name twice which is why we have a check for that

    for (size_t i = 0; i < customizableDeclWeaponPtrVec.size(); i++)
    {
        idDeclWeapon* declWeap = customizableDeclWeaponPtrVec[i];
        idDeclInventory* declInv = (idDeclInventory*)declWeap;

        std::string declName = declWeap->getNameStr();

        if (isInDefaultWeaponVec(declName)) {
            continue;
        }
       

        customizedWeapon customWeapon = customizedWeapon(declName);      

        //? only this value in the base player weapon (like weapon/player/shotgun) modify the actual 'weapon fov'
        customWeapon.handsFovScale = declInv->handsFovScale;

        customWeapon.zoomedHandsFOV = declWeap->ironSightZoom.zoomedHandsFOV;
        customWeapon.zoomedFOV = declWeap->ironSightZoom.zoomedFOV;

        customWeapon.mouseADSSensScale = declWeap->ironSightZoom.sensitivity_scale_mouse;
        customWeapon.controllerADSSensSclae = declWeap->ironSightZoom.sensitivity_scale_controller;
      
       
        m_defaultCustomizedWeaponVec.push_back(customWeapon);

        addedCounter++;

        logInfo("acquireDefaultCustomizedWeapons: adding custom weapon: %s", customWeapon.name.c_str());

    }

    logInfo("acquireDefaultCustomizedWeapons: debug: %d custom weapons have been added to m_defaultCustomizedWeaponVec", addedCounter);

}



//! is the decl name already added to m_defaultCustomizedWeaponVec 
bool CustomizedWeaponManager::isInDefaultWeaponVec(std::string declName) {
    
    for (size_t i = 0; i < m_defaultCustomizedWeaponVec.size(); i++)
    {
        if (m_defaultCustomizedWeaponVec[i].name == declName) return true;
    }
    return false;
}


void CustomizedWeaponManager::applySettingsToDeclWeapons() {

    std::vector<idDeclWeapon*> customizableDeclWeaponPtrVec = idResourceListManager::getCustomizableDeclWeaponsPtrsVec();
    int debugCounter = 0;

    for (size_t i = 0; i < customizableDeclWeaponPtrVec.size(); i++)
    {
        idDeclWeapon* declWeap = customizableDeclWeaponPtrVec[i];
        if (applyToDecl(declWeap)) {
            debugCounter++;
        }      
    }

    logInfo("applySettingsToDeclWeapons: applied settings to: %d decl weapons", debugCounter);
}


bool CustomizedWeaponManager::applyToDecl(idDeclWeapon* declWeap) {
    
    idDeclInventory* declInv = (idDeclInventory*)declWeap;

    std::string declName = declWeap->getNameStr();

    customizedWeapon* customWeapon = getCustomWeaponPtrByName(declName);
    customizedWeapon* defaultWeapon = getDefaultCustomWeaponPtrByName(declName);

    if (!customWeapon) {
        logWarn("applyToDecl found null customWeapon for declName: %s skipping", declName.c_str());
        return false;
    }
    if (!defaultWeapon) {
        logWarn("applyToDecl found null defaultWeapon for declName: %s skipping", declName.c_str());
        return false;
    }

    //! only the decl weapon which is has syntax like weapon/player/shotgun has influence on the weapon FOV
    if (customWeapon->order == 0) {
        declInv->handsFovScale = customWeapon->handsFovScale;
    }

    //todo even if this is done in ui we should check here that the weap is allowed to remove zoom just in case user manually changes the json file and crashes the game potentially.
    if (customWeapon->isRemoveZoom) {
        declWeap->ironSightZoom.zoomedHandsFOV = m_noZoom_zoomedHandsFovValue;
        declWeap->ironSightZoom.zoomedFOV = m_noZoom_zoomedFovvalue;
    }
    else {

        declWeap->ironSightZoom.zoomedHandsFOV = defaultWeapon->zoomedHandsFOV;
        declWeap->ironSightZoom.zoomedFOV = defaultWeapon->zoomedFOV;
    }

    declWeap->ironSightZoom.sensitivity_scale_mouse = customWeapon->mouseADSSensScale;
    declWeap->ironSightZoom.sensitivity_scale_controller = customWeapon->controllerADSSensSclae;

    //! this should be a tick box on the ui for is crosshair
   /* if (declWeap->reticle) {
        if (!customWeapon->reticleStyleInt) {
            declWeap->reticle->style = idDeclWeaponReticle_reticleStyle_t::RETICLE_STYLE_NONE;
        }
        else {
            declWeap->reticle->style = (idDeclWeaponReticle_reticleStyle_t)defaultWeapon->reticleStyleInt;
        }

        declWeap->reticle->reticleModelScale = customWeapon->reticleScale;
    }*/
    
    //if (declWeap->reticleWhenZoomed) {
    //    //! this should be a tick box on the ui for is crosshair in ADS
    //    if (!customWeapon->reticleStyleADSInt) {
    //        declWeap->reticleWhenZoomed->style = idDeclWeaponReticle_reticleStyle_t::RETICLE_STYLE_NONE;
    //    }
    //    else {
    //        declWeap->reticleWhenZoomed->style = (idDeclWeaponReticle_reticleStyle_t)defaultWeapon->reticleStyleADSInt;
    //    }

    //    declWeap->reticleWhenZoomed->reticleModelScale = customWeapon->reticleSecondaryScale;
    //}   
    

    return true;
}


void CustomizedWeaponManager::resetWeapon(std::string weaponName) {

    customizedWeapon* defaultWeaponPtr = getDefaultCustomWeaponPtrByName(weaponName);
    customizedWeapon* weaponPtr = getCustomWeaponPtrByName(weaponName);

    if (!defaultWeaponPtr) {
        logErr("resetWeapon: failed to find default weapon with name: %s", weaponName.c_str());
        return;
    }
    if (!weaponPtr) {
        logWarn("resetWeapon: failed to find weapon with name: %s", weaponName.c_str());
        return;
    }

    //! copies the value of defaultWeaponPtr in weaponPtr so both keep their addr. Even though this looks dangerous...
    *weaponPtr = *defaultWeaponPtr;
}


customizedWeapon* CustomizedWeaponManager::getDefaultCustomWeaponPtrByName(std::string declName) {

    for (size_t i = 0; i < m_defaultCustomizedWeaponVec.size(); i++)
    {
        if (m_defaultCustomizedWeaponVec[i].name == declName) return &m_defaultCustomizedWeaponVec[i];
    }
    return nullptr;
}


customizedWeapon* CustomizedWeaponManager::getCustomWeaponPtrByName(std::string declName) {

    for (size_t i = 0; i < m_customizedWeaponVec.size(); i++)
    {
        if (m_customizedWeaponVec[i].name == declName) return &m_customizedWeaponVec[i];
    }
    return nullptr;
}



//std::vector<customizedWeapon>  CustomizedWeaponManager::getCustomWeaponVecCpy() {
//
//    return m_customizedWeaponVec;
//}
//
//void CustomizedWeaponManager::setCustomWeaponVecCpy(std::vector<customizedWeapon> custWeaponsVec)
//{
//    m_customizedWeaponVec = custWeaponsVec;
//}
//
//std::vector<customizedWeapon>  CustomizedWeaponManager::getDefaultCustomWeaponVecCpy() {
//
//    return m_defaultCustomizedWeaponVec;
//}




std::vector<customizedWeapon*>  CustomizedWeaponManager::getSortedCustomWeaponRefsForGroup(customizedWeaponGroupID groupID) {

    std::vector<customizedWeapon*> resultVec;

    for (size_t i = 0; i < m_customizedWeaponVec.size(); i++)
    {
        if (&m_customizedWeaponVec[i] && m_customizedWeaponVec[i].groupId == groupID) {
            resultVec.push_back(&m_customizedWeaponVec[i]);
        }
    }
    //! sort by order
    std::sort(resultVec.begin(), resultVec.end(), [](const customizedWeapon* a, const customizedWeapon* b) {
        return a->order < b->order;
        });

    return resultVec;
}



//std::vector<customizedWeapon> CustomizedWeaponManager::getSortedWeaponsInGroupIdCategoryVec(customizedWeaponGroupID groupId) {
//    std::vector<customizedWeapon> result;
//
//    for (size_t i = 0; i < m_customizedWeaponVec.size(); i++)
//    {
//        if (m_customizedWeaponVec[i].groupId == groupId) {
//            result.push_back(m_customizedWeaponVec[i]);
//        }
//    }
//
//}

//customizedWeaponGroupID CustomizedWeaponManager::getCustomizedWeaponGroupID(std::string declWeaponNameStr) {
//
//    if (declWeaponNameStr == "weapon/player/shotgun") {
//        
//    }
//}



bool CustomizedWeaponManager::loadCustomWeaponsFromFile() {   
    
    std::string filePath = FileOp::getMainModSettingsFilePath();
    // Open the file for reading
    std::ifstream file(filePath);

    if (!file.is_open()) {
        // Handle error: file not found or unable to open
        logWarn("loadCustomWeaponsFromFile: file not found or unable to open %s may be first time mod launch, returning...", filePath.c_str());
        return false;      
    }

    // Parse JSON from the file
    nlohmann::json j;
    file >> j;

    // Close the file
    file.close();

    // Deserialize the JSON data
    if (j.contains("customizedWeapons")) {
        const auto& weaponsArray = j["customizedWeapons"];
        if (weaponsArray.is_array()) {
            m_customizedWeaponVec.clear(); // Clear existing data

            for (const auto& weaponObject : weaponsArray) {
                customizedWeapon weapon;

                // Deserialize weapon member variables from JSON object
               
                weapon.name = weaponObject["name"];   
                weapon.groupId = weaponObject["groupId"];
                weapon.order = weaponObject["order"];
                weapon.handsFovScale = weaponObject["handsFovScale"];
                weapon.isRemoveZoom = weaponObject["isRemoveZoom"];
                weapon.zoomedHandsFOV = weaponObject["zoomedHandsFOV"];
                weapon.zoomedFOV = weaponObject["zoomedFOV"];
                weapon.mouseADSSensScale = weaponObject["mouseADSSensScale"];
                weapon.controllerADSSensSclae = weaponObject["controllerADSSensSclae"];
                weapon.isDotReticleShowCoolDown = weaponObject["isDotReticleShowCoolDown"];
               /* weapon.reticleStyleInt = weaponObject["reticleStyleInt"];
                weapon.reticleStyleADSInt = weaponObject["reticleStyleADSInt"];
                weapon.reticleScale = weaponObject["reticleScale"];
                weapon.reticleSecondaryScale = weaponObject["reticleSecondaryScale"];*/
              /*  weapon.reticleDotColorPacked = weaponObject["reticleDotColorPacked"];
                weapon.reticleDotCoolDownColorPacked = weaponObject["reticleDotCoolDownColorPacked"];*/

                // Add the deserialized weapon to the vector
                m_customizedWeaponVec.push_back(weapon);

            }
        }
        else {
            // Handle error: customizedWeapons is not an array
            logErr("loadCustomWeaponsFromFile: customizedWeapons is not an array in JSON file: %s", filePath.c_str());
            return false;
        }
    }
    else {
        // Handle error: JSON does not contain customizedWeapons key
        logErr("loadCustomWeaponsFromFile: JSON file does not contain customizedWeapons key:");
        return false;
    }

    logInfo("loadCustomWeaponsFromFile: %zu customized weapons have been loaded from file: %s", m_customizedWeaponVec.size(), filePath.c_str());
    return true;
}



void CustomizedWeaponManager::saveCustomWeaponsToFile() {

    logInfo("saveCustomWeaponsToFile()");

    std::string filePath = FileOp::getWeaponsSettingsFilePath();

    nlohmann::json j;

    // Serialize the customizedWeaponsVec
    nlohmann::json weaponsArray = nlohmann::json::array();
    for (const customizedWeapon& weapon : m_customizedWeaponVec) {
        nlohmann::json weaponObject;    
       
        weaponObject["name"] = weapon.name;
        weaponObject["groupId"] = weapon.groupId;
        weaponObject["order"] = weapon.order;
        weaponObject["handsFovScale"] = weapon.handsFovScale;
        weaponObject["isRemoveZoom"] = weapon.isRemoveZoom;
        weaponObject["zoomedHandsFOV"] = weapon.zoomedHandsFOV;
        weaponObject["zoomedFOV"] = weapon.zoomedFOV;
        weaponObject["mouseADSSensScale"] = weapon.mouseADSSensScale;
        weaponObject["controllerADSSensSclae"] = weapon.controllerADSSensSclae;
        weaponObject["isDotReticleShowCoolDown"] = weapon.isDotReticleShowCoolDown;
      /*  weaponObject["reticleStyleInt"] = weapon.reticleStyleInt;
        weaponObject["reticleStyleADSInt"] = weapon.reticleStyleADSInt;
        weaponObject["reticleScale"] = weapon.reticleScale;
        weaponObject["reticleSecondaryScale"] = weapon.reticleSecondaryScale;*/
     /*   weaponObject["reticleDotColorPacked"] = weapon.reticleDotColorPacked;
        weaponObject["reticleDotCoolDownColorPacked"] = weapon.reticleDotCoolDownColorPacked;*/


        weaponsArray.push_back(weaponObject);
    }
    j["customizedWeapons"] = weaponsArray;


    std::string serializedData = j.dump(4);

    // Write JSON to file
    std::ofstream file(filePath);
    if (file.is_open()) {
        file << j.dump(4);
        file.close();
    }

}


//void CustomizedWeaponManager::debugLogCustomizedWeaponsVec(std::vector<customizedWeapon> customizedWeaponVec) {
//
//
//}


//bool CustomizedWeaponManager::isDefaultSaved(idDeclWeapon* declWeapon)
//{
//    for (size_t i = 0; i < m_defaultCustomizedWeaponVec.size(); i++)
//    {
//        if (m_defaultCustomizedWeaponVec[i].name == declWeapon->getNameStr()) return true;
//    }
//    return false;
//}
//
//void CustomizedWeaponManager::saveDefault(idDeclWeapon* declWeapon)
//{
//    customizedWeapon defaultCustomWeap;
//
//    defaultCustomWeap.name = declWeapon->getNameStr();
//
//    defaultCustomWeap.zoomedHandsFOV = declWeapon->ironSightZoom.zoomedHandsFOV;
//    defaultCustomWeap.zoomedFOV = declWeapon->ironSightZoom.zoomedFOV;
//
//    defaultCustomWeap.reticleStyleInt = declWeapon->reticle->style;
//    defaultCustomWeap.reticleStyleADSInt = declWeapon->reticleWhenZoomed->style;
//
//}

void CustomizedWeaponManager::debugLogWeaponsVals()
{
    //std::vector<std::string> resultStrs;
    std::string resultStr;
    std::vector<idDeclWeapon*> declWeaponPtrVec = idResourceListManager::getDeclWeaponsStartingWith("weapon/player/");

    logInfo("debugLogAllDefautlDeclWeaponsVals:");
    for (size_t i = 0; i < declWeaponPtrVec.size(); i++)
    {
        idDeclWeapon* declWeap = declWeaponPtrVec[i];
        idDeclInventory* declInv = (idDeclInventory *)declWeaponPtrVec[i];

        std::string result = "\n";

        result += "name: " + declWeap->getNameStr() + "\n";

        result += "\tweaponCategory: " + getWeaponCategoryString(declWeap->weaponCategory) +  "\n";
        result += "\tweaponSelectionGroup: " + std::to_string(declWeap->weaponSelectionGroup) +  "\n";
        result += "\tweaponSelectionGroupSlot: " + std::to_string(declWeap->weaponSelectionGroupSlot) +  "\n";
        //? it will crash if not check as equipement weapon have no reticle ptr
        if (declWeap->reticle) {
            result += "\treticle Style: " + idDeclWeaponReticleManager::getReticleStyleString(declWeap->reticle->style) + "\n";
            result += "\treticleModel Scale: " + std::to_string(declWeap->reticle->reticleModelScale) + "\n";
           
        }    
        if (declWeap->reticleWhenZoomed) {
            result += "\treticleWhenZoomed Style: " + idDeclWeaponReticleManager::getReticleStyleString(declWeap->reticleWhenZoomed->style) + "\n";
            result += "\treticleWhenZoomed ModelScale: " + std::to_string(declWeap->reticleWhenZoomed->reticleModelScale) + "\n";
        }

        result += "\thandsFovScale: " + std::to_string(declInv->handsFovScale) + "\n";

        result += "\tzoomedHandsFOV: " + std::to_string(declWeap->ironSightZoom.zoomedHandsFOV) + "\n";
        result += "\tzoomedFOV: " + std::to_string(declWeap->ironSightZoom.zoomedFOV) + "\n";
        result += "\tmouseADSSens: " + std::to_string(declWeap->ironSightZoom.sensitivity_scale_mouse) + "\n";
        result += "\tcontrollerADSSens: " + std::to_string(declWeap->ironSightZoom.sensitivity_scale_controller) + "\n";

        resultStr += result + "\n";
        
    }

    logInfo("%s", resultStr.c_str());
   
}


std::string CustomizedWeaponManager::getWeaponCategoryString(idDeclWeapon_weaponCategory_t weaponCategory) {
    switch (weaponCategory) {
    case WEAPON_CATEGORY_MELEE: return "WEAPON_CATEGORY_MELEE";
    case WEAPON_CATEGORY_SIDE_ARMS: return "WEAPON_CATEGORY_SIDE_ARMS";
    case WEAPON_CATEGORY_SMG: return "WEAPON_CATEGORY_SMG";
    case WEAPON_CATEGORY_RIFLE: return "WEAPON_CATEGORY_RIFLE";
    case WEAPON_CATEGORY_MACHINE_GUN: return "WEAPON_CATEGORY_MACHINE_GUN";
    case WEAPON_CATEGORY_SHOTGUN: return "WEAPON_CATEGORY_SHOTGUN";
    case WEAPON_CATEGORY_SNIPER: return "WEAPON_CATEGORY_SNIPER";
    case WEAPON_CATEGORY_THROWN: return "WEAPON_CATEGORY_THROWN";
    case WEAPON_CATEGORY_LAUNCHER: return "WEAPON_CATEGORY_LAUNCHER";
    case WEAPON_CATEGORY_SPECIAL: return "WEAPON_CATEGORY_SPECIAL";
    case WEAPON_CATEGORY_LAUNCHER_PARABOLIC: return "WEAPON_CATEGORY_LAUNCHER_PARABOLIC";
    case WEAPON_CATEGORY_DBL_BARREL_SHOTGUN: return "WEAPON_CATEGORY_DBL_BARREL_SHOTGUN";
    case WEAPON_CATEGORY_PLASMA_RIFLE: return "WEAPON_CATEGORY_PLASMA_RIFLE";
    case WEAPON_CATEGORY_BEAM: return "WEAPON_CATEGORY_BEAM";
    case WEAPON_CATEGORY_AOE: return "WEAPON_CATEGORY_AOE";
    case WEAPON_CATEGORY_CURRENT: return "WEAPON_CATEGORY_CURRENT";
    case WEAPON_CATEGORY_MAX: return "WEAPON_CATEGORY_MAX";
    default: return "Unknown";
    }
}

//customizedWeapon CustomizedWeaponManager::getDefaultShotgun()
//{
//    return customizedWeapon();
//}
//
//customizedWeapon CustomizedWeaponManager::getDefaultHeavyCannon()
//{
//    return customizedWeapon();
//}
//
//customizedWeapon CustomizedWeaponManager::getDefaultPlasma()
//{
//    return customizedWeapon();
//}
//
//customizedWeapon CustomizedWeaponManager::getDefaultRL()
//{
//    return customizedWeapon();
//}
//
//customizedWeapon CustomizedWeaponManager::getDefaultSuperShotgun()
//{
//    return customizedWeapon();
//}
//
//customizedWeapon CustomizedWeaponManager::getDefaultBalista()
//{
//    return customizedWeapon();
//}
//
//customizedWeapon CustomizedWeaponManager::getDefaultChaingun()
//{
//    return customizedWeapon();
//}
//
//customizedWeapon CustomizedWeaponManager::getDefaultUnmayKr()
//{
//    return customizedWeapon();
//}
//
//customizedWeapon CustomizedWeaponManager::getDefaultCrucible()
//{
//    return customizedWeapon();
//}
//
//customizedWeapon CustomizedWeaponManager::getDefaultHammer()
//{
//    return customizedWeapon();
//}
