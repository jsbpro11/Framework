#include "DXUT.h"
#include "Header.h"

CTitleScene::CTitleScene()
	:CScene(), isHowTo(false), isRank(false), titleImage(new CMatrix), howToImage(new CMatrix), rankImage(new CMatrix)
{

}

CTitleScene::~CTitleScene()
{
	delete titleImage;
	delete howToImage;
	delete rankImage;
}

void CTitleScene::Update(float deltaTime)
{
	CScene::Update(deltaTime);

	if (isHowTo)
		howToImage->Update(deltaTime);
	else if (isRank)
		rankImage->Update(deltaTime);
	else
		titleImage->Update(deltaTime);
}

void CTitleScene::Render(LPD3DXSPRITE sprite)
{
	CScene::Render(sprite);

	if (isHowTo)
		howToImage->Draw(sprite, gAssetManager->howToTexture);
	else if (isRank)
		rankImage->Draw(sprite, gAssetManager->rankingTexture);
	else
		titleImage->Draw(sprite, gAssetManager->titleTexture);
}

void CTitleScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_UP:
			if (!isHowTo && titleImage->currentScene > 0)
				titleImage->currentScene--;
			break;

		case VK_DOWN:
			if (!isHowTo && titleImage->currentScene < 3)
				titleImage->currentScene++;
			break;

		case VK_RETURN:
			switch (titleImage->currentScene)
			{
			case 0:
				ChangeScene(1);
				break;
			case 1:
				isHowTo = !isHowTo;
				break;
			case 2:
				isRank = !isRank;
				break;
			case 3:
				PostQuitMessage(0);
				break;
			}
			break;
		}
		break;
	}
}