#include "DXUT.h"
#include "Header.h"

LPD3DXSPRITE gSprite = NULL;
CScene* gScene = NULL;

bool changeScene = false;
int changeSceneNum = 0;

void ChangeScene(int sceneNum)
{
	changeScene = true;
	changeSceneNum = sceneNum;
}

void _ChangeScene(int sceneNum)
{
	if (gScene)
	{
		delete gScene;
		gScene = NULL;
	}

	switch (sceneNum)
	{
	case 0:
		gScene = new CTitleScene();
		break;
	case 1:
		gScene = new CGameScene();
		break;
	case 2:
		gScene = new CEndingScene(true);
		break;
	case 3:
		gScene = new CEndingScene(false);
		break;
	}
}

void Init()
{
	D3DXCreateSprite(DXUTGetD3D9Device(), &gSprite);

	gAssetManager = new AssetManager();
	gAssetManager->LoadAssets();

	ChangeScene(0);
}

void Term()
{
	gAssetManager->ReleaseAssets();
	delete gAssetManager;

	gSprite->Release();

	if (gScene)
	{
		delete gScene;
		gScene = NULL;
	}
}

void Lost()
{
	gSprite->OnLostDevice();
}

void Reset()
{
	gSprite->OnResetDevice();
}

void Update(float deltaTime)
{
	if (gScene)
		gScene->Update(deltaTime);

	if (changeScene)
	{
		_ChangeScene(changeSceneNum);
		changeScene = false;
	}
}

void Render()
{
	gSprite->Begin(D3DXSPRITE_ALPHABLEND);

	if (gScene)
		gScene->Render(gSprite);

	gSprite->End();
}

void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (gScene)
		gScene->MsgProc(uMsg, wParam, lParam);
}