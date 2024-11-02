#include "../../../include/Window/Windows/WindowsWindow.h"

#if defined WINDOWS || defined DEBUG

#include <windows.h>
#include <string>

WindowsWindow::WindowsWindow(int width, int height, int x, int y, const std::string* title) : CustomWindow(width, height, x, y, title)
{
    // Constructor
}

WindowsWindow::~WindowsWindow() = default; // Destructor

// Window Procedure
LRESULT CALLBACK WindowsWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        break;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WindowsWindow::wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) const
{
    // Register the window class
    std::wstring className = std::wstring(title->begin(), title->end());

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = LPCSTR(className.c_str());

    RegisterClass(&wc);

    // Create the window
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        LPCSTR(className.c_str()),              // Window class
        title->c_str(),                 // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        nullptr,       // Parent window
        nullptr,       // Menu
        hInstance,  // Instance handle
        nullptr        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop
    MSG msg = { };
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

void WindowsWindow::show()
{
    // Show the window
    wWinMain(GetModuleHandle(NULL), NULL, reinterpret_cast<PWSTR>(GetCommandLine()), SW_SHOWNORMAL);
}

#endif //WINDOWS