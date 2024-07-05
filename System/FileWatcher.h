#pragma once

#include <filesystem>
#include <string>
#include "../Config/Config.h"

class FileWatcher {
private:
    static std::string m_filepath;
    static std::filesystem::file_time_type m_lastModifiedTime;

public:
    static void Initialize(const std::string& filepath) {
        m_filepath = filepath;
        UpdateLastModifiedTime();
        logInfo("FileWatcher Initialization: inifile path initialized to: %s", m_filepath.c_str());
    }

    static bool IsFileModified() {
        try {
            std::filesystem::file_time_type current_time = std::filesystem::last_write_time(m_filepath);
            if (current_time != m_lastModifiedTime) {
                m_lastModifiedTime = current_time;
                logInfo("FileWatcher: Inifile has been modified...");
                return true;
            }
        }
        catch (const std::exception& ex) {
            // Handle the exception here, e.g., log the error
            logErr("FileWatcher: Exception while checking file modification: %s", ex.what());
        }
        return false;
    }

    static void UpdateLastModifiedTime() {
        try {
            m_lastModifiedTime = std::filesystem::last_write_time(m_filepath);
        }
        catch (const std::exception& ex) {
            // Handle the exception here, e.g., log the error
            logErr("FileWatcher: Exception while updating last modified time: %s", ex.what());
        }
    }


   
};

std::string FileWatcher::m_filepath = "";
std::filesystem::file_time_type FileWatcher::m_lastModifiedTime;