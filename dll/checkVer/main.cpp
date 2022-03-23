#include <iostream>
#include <Windows.h>
#include <versionhelpers.h>

__declspec (dllexport) void checkVer() {
    if (!IsWindows8OrGreater())
    {
        MessageBox(NULL, "You need at least Windows 10.", "Version Not Supported", MB_OK);
    }
};