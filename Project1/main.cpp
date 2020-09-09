#include <windows.h>
#include <stdio.h>
#include<iostream>	
using namespace std;
int main() {

    ///////////////////////
    // Variable declaration
    ///////////////////////


    HANDLE hProcess, hThread;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD dwProcessID = 0, dwThreadId = 0;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    BOOL bCreateProcess = NULL;

    ///////////////////////
    // .exe
    ///////////////////////
    WCHAR cmdArgs_ccx[] = L"D:\\1.PhD\\Calculix\\pinchedcyl\\inp_main.inp";


    // For vlc 1 space and every space is another link
    WCHAR cmdArgs_vlc[] = L" D:\\youtube\\1.mp3\\video1.mp3";


    WCHAR pathvlc[] = L"C:\\Program Files (x86)\\VideoLAN\\VLC\\vlc.exe";
    WCHAR pathccx[] = L"D:\\1.PhD\\Calculix\\CL34-win64\\bin\\ccx\\ccx216.exe";
    WCHAR pathccxcpp[] = L"D:\\1.PhD\\Calculix\\CL34-win64\\scr\\CalculiX\\ccx\\CalculiX\\ccx_2.16\\src\\ccx_2.16.c";
    WCHAR pathlauncher[] = L"D:\\1.PhD\\Calculix\\CL34-win64\\Launcher.exe";

    WCHAR pathnotepp[] = L"C:\\Program Files (x86)\\Notepad++\\notepad++.exe";
    WCHAR pathwmplayer[] = L"C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe";

    //all cmd
    WCHAR cmdall_ccx[] = L"D:\\1.PhD\\Calculix\\CL34-win64\\bin\\ccx\\ccx216.exe D:\\1.PhD\\Calculix\\pinchedcyl\\inp_main";

    bCreateProcess = CreateProcess(
        NULL,
        cmdall_ccx,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi);

    if (bCreateProcess == FALSE) {
        cout << "Create Process Failed & Error No - " << GetLastError() << endl;
    };
    cout << "Create Process Success " << endl;

    //cout << "Create ID " << pi.dwProcessId() << endl;
    //cout << "Thread ID " << pi.dwThreadId() << endl;
    cout << "GetProcess ID " << GetProcessId(pi.hProcess) << endl;
    cout << "GetThreat ID " << GetThreadId(pi.hThread) << endl;

    // Wait until child process exits.

    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles. 

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    system("PAUSE");
    return 0;

}
///////////////
// FUNCTIONS
//////////////
