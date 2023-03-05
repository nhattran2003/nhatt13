#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
#define E(x, i) x.HeSo[i]
struct DonThuc
{
    float HeSo;
    int SoMu;
};
typedef struct DonThuc DONTHUC;
struct DaThuc
{
    float HeSo[MAX];
    int SoMu;
};
typedef struct DaThuc DATHUC;

void KhoiTaoDaThucRong(DATHUC &);
void NhapDaThuc(DATHUC &);
void XuatDaThuc(DATHUC, char[]);


DATHUC TinhHieu2DaThuc(DATHUC, DATHUC);
DATHUC TinhTong2DaThuc(DATHUC, DATHUC);
DATHUC TinhTich2DaThuc(DATHUC, DATHUC);
DATHUC TinhThuong2DaThuc(DATHUC, DATHUC);
DATHUC TinhDaThucDu(DATHUC, DATHUC);
DATHUC TinhDaoHamCap1(DATHUC);
DATHUC TinhDaoHamCapk(DATHUC);
float TinhGiaTri(DATHUC, float);
float TimNghiemDaThucTrongDoanAB(float, float);

DATHUC operator +(DATHUC, DATHUC);
DATHUC operator -(DATHUC, DATHUC);
DATHUC operator *(DATHUC, DATHUC);
DATHUC operator /(DATHUC, DATHUC);


DATHUC TinhDaoHamCap1(DATHUC);
DATHUC TinhDaoHamCapk(DATHUC, int);
float TinhDaoHamCapk(DATHUC, float);


void KhoiTaoDaThucRong(DATHUC &dt)
{
    dt.SoMu = 0;
    for (int i = 0; i < MAX; i++)
        dt.HeSo[i] = 0;
}
void NhapDaThuc(DATHUC &dt)
{
    KhoiTaoDaThucRong(dt);
    do
    {
        printf("\nNhap bac da thuc: ");
        scanf("%d", &dt.SoMu);
        if(dt.SoMu < 1)
        {
            printf("\nSo bac cua da thuc phai >= 1. Xin kiem tra lai !");
        }
    }while(dt.SoMu < 1);

    for(int i = dt.SoMu; i >= 0; i--)
    {
        float temp;
        printf("\nNhap he so: ");
        scanf("%f", &temp);
        dt.HeSo[i] = temp;
    }
}

void XuatDaThuc(DATHUC dt, char thongbao[])
{
    printf("%s", thongbao);
    for(int i = dt.SoMu; i > 0; i--)
    {
        if (dt.HeSo[i] != 0)
        {
            printf("%8.3fx^%d + " , dt.HeSo[i], i);
        }
    }
    printf("%8.3f\n", dt.HeSo[0]);
}



DATHUC TinhTong2DaThuc(DATHUC a, DATHUC b)
{
    DATHUC ketqua;
    KhoiTaoDaThucRong(ketqua);

    
    if(a.SoMu > b.SoMu)
    {
        ketqua.SoMu = a.SoMu;  // b?c da th?c k?t qu? là b?c da th?c a
    }
    else
    {
        ketqua.SoMu = b.SoMu;
    }
    
    for(int i = 0; i <= ketqua.SoMu; i++)
    {
        ketqua.HeSo[i] = a.HeSo[i] + b.HeSo[i];
    }
    return ketqua;
}


DATHUC TinhHieu2DaThuc(DATHUC a, DATHUC b)
{
    DATHUC ketqua;
    KhoiTaoDaThucRong(ketqua);

    
    if(a.SoMu > b.SoMu)
    {
        ketqua.SoMu = a.SoMu;  // b?c da th?c k?t qu? là b?c da th?c a
    }
    else
    {
        ketqua.SoMu = b.SoMu;
    }
    
    for(int i = 0; i <= ketqua.SoMu; i++)
    {
        ketqua.HeSo[i] = a.HeSo[i] - b.HeSo[i];
    }
    return ketqua;
}



DATHUC TinhTich2DaThuc(DATHUC a, DATHUC b)
{
    DATHUC ketqua;
    KhoiTaoDaThucRong(ketqua);

    
    ketqua.SoMu = a.SoMu + b.SoMu; 

    
    int i, j;
    for(i = 0; i <= a.SoMu; i++)
    {
        for(j = 0; j <= b.SoMu; j++)
        {
            ketqua.HeSo[i + j] += a.HeSo[i] * b.HeSo[j];
        }
    }
    return ketqua;
}






DATHUC TinhDaoHamCap1(DATHUC dt)
{
    DATHUC ketqua;
    KhoiTaoDaThucRong(ketqua);

   
    ketqua.SoMu = dt.SoMu - 1;

    
    for(int i = dt.SoMu; i >= 0; i--)
    {        
        ketqua.HeSo[i - 1] = dt.HeSo[i] * i;
    }
    return ketqua;
}



DATHUC TinhDaoHamCapk(DATHUC dt, int k)
{
    DATHUC ketqua = dt;
    for(int i = 0; i < k; i++)
    {
        ketqua = TinhDaoHamCap1(ketqua);
    }
    return ketqua;
}


float TinhGiaTri(DATHUC dt, float x0) 
{
    float kq = 0;

    for (int i=dt.SoMu; i>=0; i--)
        kq = kq + dt.HeSo[i] * pow(x0, i);

    return kq;
}
int main()
{
    DATHUC kq;
    DATHUC dt1, dt2;
    NhapDaThuc(dt1);
    XuatDaThuc(dt1, "Da thuc 1: ");

    NhapDaThuc(dt2);
    XuatDaThuc(dt2, "Da thuc 2: ");
    XuatDaThuc(TinhTong2DaThuc(dt1, dt2), "Da thuc 1 + Da thuc 2 = ");
    XuatDaThuc(TinhHieu2DaThuc(dt1, dt2), "Da thuc 1 - Da thuc 2 = ");
    XuatDaThuc(TinhTich2DaThuc(dt1, dt2), "Da thuc 1 * Da thuc 2 = ");
    
    
    XuatDaThuc(TinhDaoHamCap1(dt1), "Dao ham cap 1 = ");

    getch();
    return 0;
}