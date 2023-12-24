#pragma once
#include "HCN.h"
class omin :
    public HCN
{
public:
    int giatri;
    int mo;
    omin();
    omin(int mx1, int my1, int mx2, int my2);
    void vehinh(CClientDC* pdc);
    int bamomin(CClientDC* pdc, CPoint p);
    int Bamchonco(CClientDC* pdc, CPoint p);
};

