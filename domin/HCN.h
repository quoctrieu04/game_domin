#pragma once
class HCN
{
public:
	int x1, y1, x2, y2;
	HCN();
	HCN(int mx1, int my1, int mx2, int my2);
	void vehinh(CClientDC* pdc);
	int kiemtratronghinh(CPoint p);
};

