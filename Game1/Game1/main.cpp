#include<d3d9.h>
#include "Game.h"

#define FRAME_RATE 30

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstace,
	LPSTR lpStrCmdLine,
	int nShowCmd)
{
	DWORD frame_start = GetTickCount();
	DWORD count_per_frame = 1000 / FRAME_RATE;

	Game mygame(WIDTH, HEIGHT, false);
	mygame.GameInit();

	int done = 0;
	MSG msg;
	while (!done) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT)
				done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount();
		if (now - frame_start >= count_per_frame)
		{
			frame_start = now;
			mygame.GameRun();
		}

	}





	mygame.GameExit();
	return 0;
}