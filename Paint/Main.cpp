#include<Windows.h>
#include"MainWindow.h"

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int show)
{
	#ifdef _DEBUG
		// _CrtSetBreakAlloc(157);
		_onexit(_CrtDumpMemoryLeaks);
	#endif
	MainWindow window(hInstance);

	return 0;
}