#pragma once

//#include <io.h>
//#include <fcntl.h> 
//
//#include <memory> 
//#include <string> 
//
//#include "NonCopyable.h"
//#include "StringUtils.h"
//#include "Utils.h"
//
//class Logger : NonCopyable
//{
//public:
//	struct TConsoleInit {
//		std::string title;
//		std::string notice;
//	};
//
//	struct TFileInit {
//		std::string filename;
//	};
//
//    Logger() 
//	: m_console(INVALID_HANDLE_VALUE)
//	, m_file(INVALID_HANDLE_VALUE)
//	, m_logLevel( 0 ){}
//
//    Logger::~Logger()
//    {
//        if (m_console)
//            FreeConsole();
//
//        if (m_file)
//            CloseHandle(m_file);
//    }
//
//	static void Initialize( const TConsoleInit *console, const TFileInit *file, int logLevel ) {
//		Logger &logger = GetInstance( );
//		
//		if( console )
//			logger.Console( console->title.c_str( ), console->notice.c_str( ) );
//
//		if( file )
//			logger.File( file->filename );
//
//		if( logLevel > 0 )
//			logger.m_logLevel = logLevel;
//	}
//
//    static const Logger& Logger::Get()
//    {
//        return GetInstance( );
//    };
//
//	static int Logger::GetLogLevel( ) {
//		return Get( ).m_logLevel;
//	}
//
//    void Print(const char* format, const std::string &level, ...) const
//    {
//        va_list args;
//        va_start(args, format);
//        Print(format, level, args);
//        va_end(args);
//    }
//
//    void Print(const char* format, const std::string &level, va_list args) const
//    {
//        bool to_console = m_console != INVALID_HANDLE_VALUE;
//        bool to_file = m_file != INVALID_HANDLE_VALUE;
//
//        if ((to_console || to_file) && format)
//        {
//            int outsize = _vscprintf(format, args) + 1;
//            std::unique_ptr<char[]> buffer(new char[outsize]);
//            CharArrayFormatV(buffer.get(), outsize, format, args);
//
//#ifdef LOGGER_DISABLE_TIME
//            std::string to_print(buffer.get(), outsize - 1);
//#else
//            std::string to_print;
//            GetTime(level, &to_print);
//            to_print.append(buffer.get(), outsize - 1);
//#endif
//
//            to_print.push_back('\r');
//            to_print.push_back('\n');
//
//            DWORD lenout = 0;
//            if (to_console) WriteConsoleA(m_console, to_print.c_str(), (DWORD)to_print.size(), &lenout, NULL);
//            if (to_file) WriteFile(m_file, to_print.c_str(), (DWORD)to_print.size(), &lenout, NULL);
//        }
//    }
//
//private:
//    void GetTime(const std::string &level, std::string* out) const
//    {
//        static bool write_stamp = true;
//        if (write_stamp)
//        {
//            static char stamp[] = "[LEVEL]\t\t[TIME]\t\t[THREAD]\t[LOG]\n";
//            DWORD lenout = 0;
//
//            bool to_console = m_console != INVALID_HANDLE_VALUE;
//            bool to_file = m_file != INVALID_HANDLE_VALUE;
//
//            if (to_console) WriteConsoleA(m_console, stamp, _countof(stamp) - 1, &lenout, NULL);
//            if (to_file) WriteFile(m_file, stamp, _countof(stamp) - 1, &lenout, NULL);
//            write_stamp = false;
//        }
//
//		SYSTEMTIME systime;
//        GetLocalTime(&systime);
//        *out = StringFormat("%s\t\t%02u:%02u:%02u.%03u\t%08u\t", level.c_str( ),systime.wHour, systime.wMinute,
//            systime.wSecond, systime.wMilliseconds, GetCurrentThreadId());
//
//    }
//
//	static Logger& Logger::GetInstance()
//    {
//        static Logger instance;
//        return instance;
//    };
//
//	bool File(const std::string& filename)
//    {
//        std::string logpath;
//        FullPathFromPath(&logpath, filename);
//
//        m_file = CreateFileA(logpath.c_str(), GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
//        return m_file != INVALID_HANDLE_VALUE;
//    }
//
//    bool Console(const char* title, const char* console_notice)
//    {
//        AllocConsole();
//
//        m_console = GetStdHandle(STD_OUTPUT_HANDLE);
//        if (m_console != INVALID_HANDLE_VALUE)
//        {
//            ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
//            if (title) SetConsoleTitleA(title);
//            if (console_notice)
//            {
//                size_t len = strlen(console_notice);
//                DWORD lenout = 0;
//                WriteConsoleA(m_console, console_notice, (DWORD)len, &lenout, NULL);
//            }
//        }
//        return m_console != INVALID_HANDLE_VALUE;
//    }
//
//    HANDLE m_console;
//    HANDLE m_file;
//	int m_logLevel;
//};
//
//inline void PrintDebug(const char* format, ...)
//{
//	const Logger &logger = Logger::Get( );
//
//	if( logger.GetLogLevel( ) < 3 ) 
//		return;
//
//    va_list args;
//    va_start(args, format);
//    logger.Print(format, "[DEBUG]", args);
//    va_end(args);
//}
//
//inline void PrintInfo(const char* format, ...)
//{
//	const Logger &logger = Logger::Get( );
//
//	if( logger.GetLogLevel( ) < 2 ) 
//		return;
//
//    va_list args;
//    va_start(args, format);
//	logger.Print(format, "[INFO]", args);
//    va_end(args);
//}
//
//inline void PrintWarning(const char* format, ...)
//{
//	const Logger &logger = Logger::Get( );
//
//	if( logger.GetLogLevel( ) < 1 ) 
//		return;
//
//    va_list args;
//    va_start(args, format);
//    logger.Print(format, "[WARN]", args);
//    va_end(args);
//}
//
//inline void PrintError(const char* format, ...)
//{
//	const Logger &logger = Logger::Get( );
//
//    va_list args;
//    va_start(args, format);
//    logger.Print(format, "[ERROR]", args);
//    va_end(args);
//}