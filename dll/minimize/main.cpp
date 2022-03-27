#include <iostream>
#include <Windows.h>
#include <set>
#include <vector>
using namespace std;

int cx = GetSystemMetrics(SM_CXFULLSCREEN);
int cy = GetSystemMetrics(SM_CYFULLSCREEN) + GetSystemMetrics(SM_CYCAPTION);

set<string>ss;
string se;

BOOL CALLBACK EnumChildProc(_In_ HWND   hwnd, _In_ LPARAM lParam) {
	char szTitle[MAX_PATH] = { 0 };
	char szClass[MAX_PATH] = { 0 };
	int nMaxCount = MAX_PATH;
	LPSTR lpClassName = szClass;
	LPSTR lpWindowName = szTitle;
	GetWindowTextA(hwnd, lpWindowName, nMaxCount);
	GetClassNameA(hwnd, lpClassName, nMaxCount);
	string l = lpWindowName, r = lpClassName;
	if (ss.count(l))return TRUE;
	ss.insert(l);
	if (l.size() == 0)return TRUE;
	return TRUE;
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
	char szTitle[MAX_PATH] = { 0 };
	char szClass[MAX_PATH] = { 0 };
	int nMaxCount = MAX_PATH;
	LPSTR lpClassName = szClass;
	LPSTR lpWindowName = szTitle;
	GetWindowTextA(hwnd, lpWindowName, nMaxCount);
	GetClassNameA(hwnd, lpClassName, nMaxCount);
	string l = lpWindowName, r = lpClassName;
	if (ss.count(l))return TRUE;
	ss.insert(l);
	if (l.size() == 0)return TRUE;
	EnumChildWindows(hwnd, EnumChildProc, lParam);
	return TRUE;
}

void search(string s) {
	se = s;
	ss.clear();
	EnumWindows(EnumWindowsProc, 0);
	HWND hwnd{};
	SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, cx, cy, SWP_NOSENDCHANGING);
}

__declspec (dllexport) void minimize() {
	search("Classroom_");
};