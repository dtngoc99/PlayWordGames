#include<iostream>
using namespace std;
#include<string.h>
#include"myLib.h"
#include<string>
#pragma comment (lib,"winmm.lib") //cung cap ma thuc thi cho cac ham choi am thanh

void Hinh_Nen1();
void Switch(int n);
bool Lua_Chon();
void Khung();
void Roi_Chu();


int main()
{
	Hinh_Nen1();
	Khung();
	Roi_Chu();

	getch();
	return 0;
}
void Hinh_Nen1()
{
	char X[19][82] =
	{
		"   gggggggg    ggggg  aaaaaaaaaaaaa     mmmmmmm    mmmmmmm      eeeeeeeeeeee",
		"  g:::::::::ggg::::g a::::::::::::a   mm:::::::m  m:::::::mm   ee:::::::::::ee",
		"g:::::::::::::::::g aaaaaaaaa:::::a m::::::::::mm::::::::::m  e::::::eeeee::::ee",
		"g::::::ggggg::::::g           a::::a m::::::::::::::::::::::me::::::e     e:::::e",
		"g:::::g     g:::::g    aaaaaaa:::::a m:::::mmm::::::mmm:::::me:::::::eeeee::::::e",
		"g:::::g     g:::::g  aa::::::::::::a m::::m   m::::m   m::::me::::::::::::::::::e",
		"g:::::g     g:::::g a::::aaaa::::::a m::::m   m::::m   m::::me::::::eeeeeeeeeee",
		"g::::::g    g:::::ga::::a    a:::::a m::::m   m::::m   m::::me:::::::e",
		"g:::::::ggggg:::::ga::::a    a:::::a m::::m   m::::m   m::::me::::::::e",
		" g::::::::::::::::ga:::::aaaa::::::a m::::m   m::::m   m::::me:::::::::eeeeeeee",
		"  gg::::::::::::::g a::::::::::aa:::am::::m   m::::m   m::::mee:::::::::::::::e",
		"    gggggggg::::::g  aaaaaaaaaa  aaaammmmmm   mmmmmm   mmmmmm  eeeeeeeeeeeeeeee",
		"            g:::::g",
		"gggggg      g:::::g",
		"g:::::gg   gg:::::g",
		"g::::::ggg:::::::g",
		" gg:::::::::::::g",
		"  ggg::::::ggg",
		"     gggggg"
	};
	ShowCur(false);//an con tro nhap nhay
	int i = 0;
	int j = 0;
	int x = 30;
	int y = 1;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 82; j++)
		{
			gotoXY(x + j, y);
			cout << X[i][j];
		}
		Sleep(200);
		cout << endl;
		y++;
	}
	clrscr();
	int solan = 0;
	while (solan<10)
	{
		x = 30; y = 1;
		SetColor(solan + 1);
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 82; j++)
			{
				gotoXY(x + j, y);
				cout << X[i][j];
			}
			cout << endl;
			y++;
		}
		Sleep(100);
		clrscr();
		solan++;
	}
}

//tao khung game
void Khung()
{
	char S = 1;
	for (int i = 1; i <60; i++)
	{
		//lam cot ngang
		gotoXY(i, 1);
		cout << S;
		gotoXY(i, 40);
		cout << S;
	}
	for (int i = 1; i < 40; i++)
	{
		//lam cot doc
		gotoXY(1, i);
		cout << S;
		gotoXY(60, i);
		cout << S;
	}
}
//cho chu roi
void Roi_Chu()
{
	int x;
	int diem = 0;
	int sai = 0;
	int dem = 0;
	char kitu;
	while (sai<3)
	{
		SetColor(10);
		gotoXY(75, 10);
		cout << "DIEM: " << diem;
		int mau = rand() % 14 + 2;
		SetColor(mau);
		kitu = rand() % 26 + 97;
		x = rand() % 55 + 2;
		int i = 2;


		while (i < 40 && !kbhit()) //kbhit ham kiem tra bo dem ban phim
		{

			ShowCur(false);//an con tro nhap nhay
			gotoXY(x, i);
			cout << kitu;
			int time = 400 - dem * 3;
			Sleep(time);
			gotoXY(x, i);
			cout << "  ";

			i++;

		}
		if (kbhit())
		{
			char w = getch();
			if (w == kitu)
			{
				kitu = ' ';
				diem++;

			}
			else
			{
				sai++;
			}
		}
		else
		{

			sai++;
		}

		dem++;

	}
	gotoXY(18, 10);
	cout << "GAME OVER";
}
