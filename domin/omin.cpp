#include "pch.h"
#include "omin.h"

omin::omin()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	giatri = 0;
	mo = 0;
}

omin::omin(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
	giatri = 0;
	mo = 0;// ch mo

}

void omin::vehinh(CClientDC* pdc)
{
	if (mo == 0) //  ô mìn chưa mở  
	{
		CBrush* brush2 = new CBrush(RGB(153, 153, 153)); //màu xám
		CBrush* oldbrush;
		oldbrush = pdc->SelectObject(brush2);
		pdc->Rectangle(x1, y1, x2, y2);
		pdc->SelectObject(oldbrush);
	}
	else
	{
		pdc->Rectangle(x1, y1, x2, y2);
		CString  strso;
		if (giatri > 0)
		{
			strso.Format(_T(" %d"), giatri);
			pdc->TextOutW((x1 + x2) / 2 - 8, (y1 + y2) / 2 - 8, strso);

		}
		else
		{
			if (giatri == - 1) // bom
			{
				CBrush* br2 = new CBrush(RGB(255, 51, 51));
				CBrush* obr;
				obr = pdc->SelectObject(br2);
				pdc->Rectangle(x1, y1, x2, y2);
				pdc->SelectObject(obr);
				CPen* pen;
				pen = new CPen(PS_SOLID, 3, RGB(255, 255, 0));
				CPen* oldpen = pdc->SelectObject(pen);
				pdc->MoveTo(x1 + 5, y1 + 5);
				pdc->LineTo((x1+5 + x2-5) / 2, (y1 + y2-5) / 2);
				pdc->SelectObject(oldpen);
				CBrush* brush2 = new CBrush(RGB(0, 0, 0));
				CBrush* oldbrush;
				oldbrush = pdc->SelectObject(brush2);
				pdc->Ellipse((x1 + x2) / 2-10, (y1 + y2) / 2 -10, (x1 + x2) / 2 + 10, (y1 + y2) / 2 + 10);
				pdc->SelectObject(oldbrush);
				
			}
		}
	}
	
	

}

int omin::bamomin(CClientDC* pdc, CPoint p)
{
	if (kiemtratronghinh(p) == 1 && mo == 0)
	{
		mo = 1; // mở ô mìn
		vehinh(pdc);
		return 1;
	}
	else
		return 0;
}

int omin::Bamchonco(CClientDC* pdc, CPoint p)
{
	if (kiemtratronghinh(p) == 1 && mo == 0)
	{
		// tạo cờ

		int x = (x1 + x2) / 2;
		int y = (y1 + y2) / 2;
		CBrush* brush2 = new CBrush(RGB(0, 0, 0));
		CBrush* oldbrush;
		oldbrush = pdc->SelectObject(brush2);
		pdc->Rectangle(x - 4, y - 10, x - 7, y + 10);
		pdc->SelectObject(oldbrush);
		brush2 = new CBrush(RGB(51, 255, 255));
		oldbrush = pdc->SelectObject(brush2);
		pdc->Rectangle(x - 7, y - 10, x + 8, y);
		return 1;
	}
	if (kiemtratronghinh(p) == 1 && mo == 2) 
	{
		// trả lại ô cờ như ban đầu nếu như đặt cờ sai
		CBrush* brush2 = new CBrush(RGB(153, 153, 153));
		CBrush* oldbrush;
		oldbrush = pdc->SelectObject(brush2);
		pdc->Rectangle(x1, y1, x2, y2);
		pdc->SelectObject(oldbrush);
		mo = 0;
		return 0;
	}

	else
	   return 0;
}
