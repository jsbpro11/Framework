#pragma once

class CTitleScene : public CScene
{
public:
	CMatrix* titleImage;
	CMatrix* howToImage;
	CMatrix* rankImage;
	bool isHowTo;
	bool isRank;

public:
	CTitleScene();
	virtual ~CTitleScene();
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprtie);
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};