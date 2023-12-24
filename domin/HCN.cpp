#include "pch.h"
#include "HCN.h"

HCN::HCN()
{
	x1 = 0;
	y1 = 0;
	
	y2 = 0;x2 = 0;
}

HCN::HCN(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

void HCN::vehinh(CClientDC* pdc)
{
	pdc->Rectangle(x1, y1, x2, y2);
}

int HCN::kiemtratronghinh(CPoint p)
{
	if (p.x > x1 && p.x < x2 && p.y > y1 && p.y < y2)// người chơi bấm trong hình
		return 1;
	else
		return 0;
	
}
