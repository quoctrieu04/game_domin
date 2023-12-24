#include "pch.h"
#include "Banco.h"


Banco::Banco()
{
	
	int i = 0, j = 0;
	 dk = 1; // có thể chơi
	 thang = 0;
	 demso = 0;
	for (i = 0; i <COT; i++) // khởi tạo tọa độ bàn cờ
	{
		for (j = 0; j <COT; j++)
		{
			ds[i][j] = omin(XDAU + DAI * j, YDAU + DAI * i, XDAU + DAI * (j+1), YDAU + DAI * (i+1));
		}
	}
	
	int dem = 0;
	srand(time(NULL));
	while (dem < SOLUONG)// khởi tạo giá trị mìn
	{
		// hàm radom mìn
		i = ((double)rand() / RAND_MAX) * (COT) + 0;
		j = ((double)rand() / RAND_MAX) * (COT) + 0;
		if (ds[i][j].giatri != -1)
		{
			ds[i][j].giatri = -1;
			//ds[i][j].mo = -1;
			dem++;
		}
	}

	// đếm ô xung quanh ô mìn
	for (i = 0; i < COT; i++)
	{
		for (j = 0; j < COT; j++)
		{
			if (ds[i][j].giatri != -1)
			{
				ds[i][j].giatri = demominxungquanh(i, j);
				//ds[i][j].mo = -1;
			}

		}
	}
}
	

void Banco::vehinh(CClientDC* pdc)
{
	int i = 0, j = 0;
	for (i = 0; i < COT; i++)
	{
	    for (j = 0; j < COT; j++)
	    {
		    ds[i][j].vehinh(pdc);
	    }
	}
}


int Banco::demominxungquanh(int mi, int mj)
{
	int dem = 0;
	int inho = mi - 1;// đếm lên trên
	int ilon = mi + 1;// đếm xuống dưới
	int jnho = mj - 1;// đếm sang trái
	int jlon = mj + 1;// đếm sang phải
	//loại bỏ các trường hợp ra ngoài biên
	if (inho < 0)
		inho = 0;
	if (jnho < 0)
		jnho = 0;
	if (ilon > COT - 1)//19
		ilon = COT - 1;
	if (jlon > COT - 1)
		jlon = COT - 1;
	int i = 0, j = 0;
	for (i = inho; i <= ilon; i++)
	{
		for (j = jnho; j <= jlon; j++)
		{
			if (ds[i][j].giatri == -1)
				dem++;
		}
	}
	return dem;
}

void Banco::thongbaoketqua(CClientDC* pdc)
{
	
	CString strthang, strthua,strdemso,strdem;
	strthang.Format(_T(" Ban da thang"));
	strthua.Format(_T(" Ban da thua"));
	strdemso.Format(_T(" So o da mo = %d"), demso);
	strdem.Format(_T(" So o chua mo = %d"), (COT*COT)-demso);
	if (thang == 1 )
		pdc->TextOutW(50, 20, strthang);
	if (thang == -1)
		pdc->TextOutW(50, 30, strthua);
	pdc->TextOutW(50, 70, strdemso);
	pdc->TextOutW(50, 90, strdem);
}

void Banco::Bambanco(CClientDC* pdc, CPoint p)
{
	int dem = 0;
	if (dk == 0)
		return;
	int i = 0, j = 0;
	for (i = 0; i < COT; i++)
	{
		for (j = 0; j < COT; j++)
		{
			if (ds[i][j].bamomin(pdc, p) == 1)// tức ô mìn ở vị trí i j được bấm
			{
				demso++;
				if (ds[i][j].giatri == -1) // người chơi bấm trúng mìn -> thua
				{
					
					thang = -1;
					dk = 0;
					PlaySound(TEXT("sound.wav"), NULL, SND_SYNC);
					thongbaoketqua(pdc);
					
				
				}
				if (ds[i][j].giatri == 0)
				{
					// mở tiếp các ô có giá trị lân cận
					
					mo4oxungquanh(i, j, pdc);
				}
				// kiểm tra thắng
				if (ktthang() == 1)
				{
					PlaySound(TEXT("chienthang.wav"), NULL, SND_SYNC);
					thongbaoketqua(pdc);
					
				
				}
					
				
			}
		}
	}
}

void Banco::mo4oxungquanh(int mi, int mj, CClientDC* pdc)
{
	int i = 0, j = 0;
	i = mi - 1; //th1 đi lên trên
	if (i < 0)
		i = 0;
	j = mj;
	if(ds[i][j].giatri == 0 && ds[i][j].mo == 0)
	{
		ds[i][j].mo = 1;
		demso++;
		
		ds[i][j].vehinh(pdc);
		// nếu bằng 0 luôn thì gọi mo4oxungquanh
		mo4oxungquanh(i, j, pdc);
	} 
	i = mi + 1; //th2 đi xuống dưới
	if (i > COT - 1)
		i = COT - 1;
	j = mj;
	if (ds[i][j].giatri == 0 && ds[i][j].mo == 0)
	{
		ds[i][j].mo = 1;
		demso++;
		
		ds[i][j].vehinh(pdc);

		mo4oxungquanh(i, j, pdc);
	}
	i = mi ; 
	j = mj - 1;  //th3 đi sang trái
	if (j < 0)
	    j = 0;
	if (ds[i][j].giatri == 0 && ds[i][j].mo == 0)
	{
		ds[i][j].mo = 1;
		demso++;
		
		ds[i][j].vehinh(pdc);
		
		mo4oxungquanh(i, j, pdc);
	}
	i = mi ; 
	j = mj + 1; //th4 di sang phải
	if (j > COT - 1)
		j = COT - 1;
	if (ds[i][j].giatri == 0 && ds[i][j].mo == 0)
	{
		ds[i][j].mo = 1;
		demso++;
		
		ds[i][j].vehinh(pdc);
		
		mo4oxungquanh(i, j, pdc);
	}
}

int Banco::ktthang()
{
	int i = 0, j = 0;
	int dem = 0;
	for (i = 0; i < COT; i++)
		for (j = 0; j < COT; j++)
		{
			if (ds[i][j].mo == 0)
				dem++; // đếm số ô chưa mở
		}
	if ( dem ==SOLUONG && thang == 0)// ban đầu là if(dem == SOLUONG && thang == 0)
	{
		thang = 1;
		return 1;
	}
	else
	  return 0;
}

void Banco::Camco(CClientDC* pdc, CPoint p)
{

	for (int i = 0; i < COT; i++)
	{
		for (int j = 0; j < COT; j++)
		{
			if (ds[i][j].Bamchonco(pdc, p) == 1) // có thể cắm cờ
			{
				ds[i][j].mo = 2;
				
			}
		}
	}
}
