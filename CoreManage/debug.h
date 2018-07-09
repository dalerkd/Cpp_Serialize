//////debug.h
#include "EXCEP.h"

#ifndef _DEBUG_H
#define _DEBUG_H

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define LogError(format, ...)\
        {\
            OutputDebug("Error:");\
            OutputDebug(format, __VA_ARGS__);\
            OutputDebug(" at %s:%s<line:%d>\r\n", __FILE__ ,__FUNCTION__, __LINE__);\
			char s[256]={0};\
			sprintf_s(s,256,format,__VA_ARGS__);\
			throw(EXCEP(s));\
        }
#define LogTips(format, ...)\
        {\
            OutputDebug("Tips:");\
            OutputDebug(format, __VA_ARGS__);\
            OutputDebug(" at %s:%s<line:%d>\r\n", __FILE__ ,__FUNCTION__, __LINE__);\
        }
#define LogInfo(format, ...)\
        {\
            OutputDebug("Info:");\
            OutputDebug(format, __VA_ARGS__);\
            OutputDebug(" at %s:%s<line:%d>\r\n", __FILE__ ,__FUNCTION__, __LINE__);\
        }


VOID OutputDebug(LPWSTR strFormat, ...);

VOID OutputDebug(LPSTR strFormat, ...);

VOID HexDump(WCHAR *desc, VOID *addr, UINT len);
VOID HexDumpPrintf(WCHAR *desc, VOID *addr, UINT len);

#endif // _DEBUG_H