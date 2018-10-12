#include "stdafx.h"
#include "RenderTextTest.h"
#include "FontTest.h"


RenderTextTest::RenderTextTest()
{
}


RenderTextTest::~RenderTextTest()
{
}
//
//HRESULT RenderTextTest::init()
//{
//
//}

bool RenderTextTest::Init()
{
	pTest = new FontTest;
	assert(pTest != NULL);

	pTest->Init();

	return true;
}

void RenderTextTest::Release()
{
	pTest->Release();
	SAFE_DELETE(pTest);
}

void RenderTextTest::Update()
{
	pTest->Update();
}

void RenderTextTest::Render(HDC hdc)
{
	string str = std::to_string(123);

	pTest->RenderTest(hdc, TEXT("Adobe"), TEXT("Hello Font!!!"),
		&pTest->GetPosition(), RGB(0, 125, 255));

	POINT pos = { 200, 200 };
	pTest->RenderTest(hdc, TEXT("Adobe"), TEXT("하이 폰트 헬로우!!!"),
		&pos, RGB(0, 20, 255));

	pTest->RenderNumber(hdc, 200, 300);
}
