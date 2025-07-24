#include <windows.h>
#include "Test_2Q/Application/DemoGameApp.h"
#include "Test_Platformer/Application/TestPlatformerGameApp.h"

/// <summary>
/// 프로그램 winMain
/// </summary>
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    CoInitialize(nullptr);  // COM 초기화

    // 실행할 Appliaction를 상속받은 클래스의 내용 작성
    // Test_2QApp::DemoGameApp demoGameApp;
    // 
    // demoGameApp.Initialize();
    // demoGameApp.Run();
    // demoGameApp.Uninitialize();

    Test_PlatformerGame::TestPlatformerGameApp testPlatformerGameApp;
    testPlatformerGameApp.Initialize();
    testPlatformerGameApp.Run();
    testPlatformerGameApp.Uninitialize();

    CoUninitialize();        // COM 해제
    return (int)1;
}