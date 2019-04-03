#pragma once
#ifndef __GAME_H__
#define __GAME_H__
#define TITLE "GAME"

#include <d3d9.h>
#include "CAnimationSprite.h"
#define SPRITE_TITLE_ALADDIN "resource/spriteSheet_aladdin_walk.bmp"
#define SPRITE_TITLE_ALADDIN_XML "resource/spriteSheet_aladdin_walk.xml"

#define WIDTH 800
#define HEIGHT 800


class Game
{
private:
	int					m_Width;
	int					m_Height;
	bool				m_IsWindow;
	int x, y;
	int iswalking;
	int lookright;


	HINSTANCE			m_HandleInstance;
	HWND				m_HandleWindow;
	LPDIRECT3D9			m_lpDirect3D;
	LPDIRECT3DDEVICE9 	m_lpDirect3DDevice;

	CAnimationSprite*	_AspAladdin;


	static LRESULT CALLBACK WndProceduce(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	Game(int scr_Width, int scr_Height, bool isWindow);
	~Game();

	bool initHandleWindow();
	bool initDirectX3DEnviroment();
	bool initDirect3DDevice();

	void GameInit();
	void GameRun();
	void GameExit();
};
#endif



