#include "DXUT.h"
#include "Header.h"

AssetManager* gAssetManager;

void AssetManager::LoadAssets()
{
	howToTexture = new CTexture(L"images/Main/TitleScene/HowTo00", L"png", 1);
	rankingTexture = new CTexture(L"images/Main/TitleScene/Ranking00", L"png", 1);
	titleTexture = new CTexture(L"images/Main/TitleScene/Title00", L"png", 4);

	victoryTexture = new CTexture(L"images/Main/EndingScene/Victory00", L"png", 1);
	loseTexture = new CTexture(L"images/Main/EndingScene/Lose00", L"png", 1);
}

void AssetManager::ReleaseAssets()
{
	delete howToTexture;
	delete rankingTexture;
	delete titleTexture;

	delete victoryTexture;
	delete loseTexture;
}