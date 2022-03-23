#include <iostream>
#include <Windows.h>

int cx = GetSystemMetrics(SM_CXSCREEN);
int cy = GetSystemMetrics(SM_CYSCREEN);

__declspec (dllexport) void recover() {
	HWND hwnd = GetForegroundWindow();
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, cx, cy, SWP_SHOWWINDOW);
};