#include "stdafx.h"
#include "FontTest.h"

FontTest::FontTest()
{
}

FontTest::~FontTest()
{
}

bool FontTest::Init()
{
	pt = { 100, 100 };
	count = 0;

	// font를 만드는 방법
	// 1. CreateFont() API 사용
	// 2. CreateFontIndirect() ,,, 이걸 쓰려면 LOGFONT 구조체에 Font정보를 설정해 줘야됨
	// 3. 외부 폰트 사용 : AddFontResource()로 OS에 등록해줘야됨
	//					  RemoveFontResource()를 사용해서 제거

	HFONT font = CreateFont(50, 0, 0, 0, 100, true, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HY견고딕"));
	fontMap.insert({ TEXT("견고딕"), font });

	font = CreateFont(40, 0, 0, 0, 300, 0, 0, 0, DEFAULT_CHARSET, OUT_STRING_PRECIS, CLIP_CHARACTER_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS,
		TEXT("Adobe Caslon Pro Bold"));
	
	fontMap.insert({ TEXT("Adobe"), font });


	image = IMAGEMANAGER->AddFrameImage(TEXT("Font"), TEXT("Image/Number.bmp"),
		490, 50, 10, 1, true, COLOR_M);

	SetNumber(1234567890);
	
	//HFONT CreateFontA(
	//	int    cHeight, // 높이
	//	int    cWidth,	// 넓이 ,,, 0 이면 높이에맞춰서 자동으로 설정됨
	//	int    cEscapement, // 기울기 degree
	//	int    cOrientation, // 방향
	//	int    cWeight,	// 굵기, FW_NOMAL이 기본값.
	//	DWORD  bItalic, // 이태릭체를 쓸지말지
	//	DWORD  bUnderline, // 언더라인 할지말지
	//	DWORD  bStrikeOut, // 취소선 ( 가운데 그어지는 선 )
	//	DWORD  iCharSet, // 문자셋
	//	// 인쇄 퀄리티 ,,, 모르겟으면 0,0,0 디폴트값으로
	//	DWORD  iOutPrecision, // 출력정확도
	//	DWORD  iClipPrecision, // 클립 정확도
	//	DWORD  iQuality, // 출력 퀄리티
	//	DWORD  iPitchAndFamily, // 자간
	//	LPCSTR pszFaceName // 폰트
	//);

	return true;
}

void FontTest::Update()
{
	count++;
	if (count % 10 == 0)
	{
		pt.x += 3;
		if (pt.x >= 400)
		{
			pt.x = 100;
			count = 0;
		}
	}
}

void FontTest::Release()
{
	it = fontMap.begin();
	for (; it != fontMap.end(); it++)
	{
		DeleteObject((HFONT)(it->second));
	}
	fontMap.clear();
}

void FontTest::RenderTest(HDC hdc, const string frontName, const string strText, POINT * pos, COLORREF color)
{
	TCHAR szStr[256] = { 0, };
	HFONT oldFont;

	it = fontMap.find(frontName);
	if (it != fontMap.end())
	{
		HFONT font = (HFONT)(it->second);
		oldFont = (HFONT)SelectObject(hdc, font);
		COLORREF oldColor = SetTextColor(hdc, color);

		TextOut(hdc, pos->x, pos->y, strText.c_str(), strText.size());

		SelectObject(hdc, oldFont);
		SetTextColor(hdc, oldColor);
	}
}

void FontTest::SetNumber(int num)
{
	number = num;
}

void FontTest::RenderNumber(HDC hdc, int destX, int destY)
{
	str = std::to_string(number);

	for (int i = 0; i < str.size(); i++)
	{
		int n = (int)str[i];
		n -= (int)'0';

		image->FrameRender(hdc, destX + image->GetFrameWidth()*i, destY, n, 0);
	}
}

void FontTest::DrawFont(HDC hdc)
{
}
