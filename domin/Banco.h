#pragma once
#include "omin.h"
#include"windows.h"
#include"MMSystem.h"
#define COT    20
#define DAI    30
#define XDAU   400
#define YDAU   20
#define SOLUONG 6 // số lượng bom trong game
class Banco
{
public:
	omin ds[COT][COT];
	int dk;
	int thang;
	int demso;
	Banco();
	void vehinh(CClientDC* pdc);
	int demominxungquanh(int mi, int mj);
	void thongbaoketqua(CClientDC* pdc);
	void Bambanco(CClientDC* pdc, CPoint p);
	void mo4oxungquanh(int mi, int mj, CClientDC* pdc);
	int ktthang();
	void Camco(CClientDC* pdc, CPoint p);

};

