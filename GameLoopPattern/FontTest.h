#pragma once
class FontTest
{
	// std 쓸때는 typedef으로 쓰자.

	map<string, HFONT>				fontMap;
	map<string, HFONT>::iterator	it;

	POINT	pt;
	int		count;

	Image*	image;
	int		number;
	string	str;
	
public:
	FontTest();
	~FontTest();

	bool	Init();
	void	Update();
	void	Release();
	void	RenderTest(HDC hdc, const string frontName, const string strText, POINT* pos, COLORREF color);

	inline	POINT GetPosition() { return pt; }

	void	SetNumber(int num);
	void	RenderNumber(HDC hdc, int destX, int destY);

	void	DrawFont(HDC hdc);
};

