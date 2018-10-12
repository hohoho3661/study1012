#pragma once
#include "GameNode.h"

class FontTest;

class RenderTextTest : public GameNode
{
	FontTest* pTest;

public:
	RenderTextTest();
	~RenderTextTest();

	//HRESULT init();
	bool	Init();
	void	Release();
	void	Update();
	void	Render(HDC hdc);
};

