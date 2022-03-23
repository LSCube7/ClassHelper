#include <iostream>
#include <Windows.h>

int cx = GetSystemMetrics(SM_CXFULLSCREEN);
int cy = GetSystemMetrics(SM_CYFULLSCREEN) + GetSystemMetrics(SM_CYCAPTION);

__declspec (dllexport) void minimize() {
	HWND hwnd = GetForegroundWindow();
	SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, cx, cy, SWP_NOSENDCHANGING);
};