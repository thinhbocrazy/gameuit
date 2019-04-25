#include "DemoScene.h"

DemoScene::DemoScene()
{
    LoadContent();
}

void DemoScene::LoadContent()
{
    //set mau backcolor cho scene o day la mau xanh
    mBackColor = 0x54acd2;

    mMap = new GameMap("Resources/ninja31test.tmx");

    mCamera = new Camera(GameGlobal::GetWidth(), GameGlobal::GetHeight());
    mCamera->SetPosition(GameGlobal::GetWidth() / 2, 
                            mMap->GetHeight() - mCamera->GetHeight());


    mMap->SetCamera(mCamera);

	mPlayer = new Player();
	//mPlayer->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2);
	mPlayer->SetPosition(110, 110);
	mPlayer->SetCamera(mCamera);
}

void DemoScene::Update(float dt)
{

	mPlayer->HandleKeyboard(keys);
	mPlayer->Update(dt);
	CheckCameraAndWorldMap();
}

void DemoScene::Draw()
{
    mMap->Draw();
	mPlayer->Draw();
	//mCamera->SetPosition(mPlayer->GetPosition());
}

void DemoScene::OnKeyDown(int keyCode)
{
    
	keys[keyCode] = true;

	mPlayer->OnKeyPressed(keyCode);

	
}

void DemoScene::OnKeyUp(int keyCode)
{
	keys[keyCode] = false;
}

void DemoScene::OnMouseDown(float x, float y)
{
}

void DemoScene::CheckCameraAndWorldMap()
{
	mCamera->SetPosition(mPlayer->GetPosition());

	if (mCamera->GetBound().left < 0)
	{
		//vi position cua camera ma chinh giua camera
		//luc nay o vi tri goc ben trai cua the gioi thuc
		mCamera->SetPosition(mCamera->GetWidth() / 2, mCamera->GetPosition().y);
	}

	if (mCamera->GetBound().right > mMap->GetWidth())
	{
		//luc nay cham goc ben phai cua the gioi thuc
		mCamera->SetPosition(mMap->GetWidth() - mCamera->GetWidth() / 2,
			mCamera->GetPosition().y);
	}

	if (mCamera->GetBound().top < 0)
	{
		//luc nay cham goc tren the gioi thuc
		mCamera->SetPosition(mCamera->GetPosition().x, mCamera->GetHeight() / 2);
	}

	if (mCamera->GetBound().bottom > mMap->GetHeight())
	{
		//luc nay cham day cua the gioi thuc
		mCamera->SetPosition(mCamera->GetPosition().x,
			mMap->GetHeight() - mCamera->GetHeight() / 2);
	}
}
