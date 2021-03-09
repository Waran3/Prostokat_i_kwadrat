//prostok¹t i kwadrat ver 1.0

#include <stdio.h>
//#include <stdlib.h>
#include <conio.h >
#include <Windows.h>
#include <locale.h>


int x;
int y;
int kody =0;
int n=0;
int licznik = 0;
int ramka_pionowa = 186;
int ramka_pozioma = 205;
int naroznik_lewy_gorny = 201;
int naroznik_prawy_gorny = 187;
int naroznik_lewy_dolny = 200;
int naroznik_prawy_dolny = 188;
int spacja = 32;
int ilosc_znakow;
int false;

char key;
int run_prostokat = 0;
int run_kwadrat = 0;

int xx = 0;
int yy = 0;

int xx_kwadrat = 0;
int yy_kwadrat = 0;

int k = 1;

int main(void)
{
	HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE); // uchwyt konsoli
	COORD pos; // zmienna zawierajaca X,Y
	pos.X = xx; // gdzie x to konkretna liczba lub zmienna z konkretna wartoscia
	pos.Y = yy; // gdzie y to konkretna liczba lub zmienna z konkretna wartoscia
	
	// lista kodów ACII-----------------------------------
	/*while (n++, kody++, n< 255)
	{
		licznik++;
		char c = kody;
		printf("%d ", licznik);
		printf("%c\n ", c);
		printf("\n");
		
		
	}
	*/

	
	
	setlocale(LC_ALL, "polish"); // w³aczenie polskich znaków
	printf("Podaj iloœæ znaków = ");
	scanf("%d", &ilosc_znakow);

	// ukrywanie kursora poczatek========================
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ccur;
	ccur.dwSize = sizeof(CONSOLE_CURSOR_INFO);
	ccur.bVisible = false;
	SetConsoleCursorInfo(hStdOut, &ccur);
	// ukrywanie kursora koniec==========================

	setlocale(LC_ALL, ".852"); // wy³aczenie polskich znaków
	system("cls");
	
		
	while (k++, k>0) // pêtla nieskoñczona, poczatek
	{
		if (k == 2)
			run_prostokat = 1, run_kwadrat = 1;
		
		if (_kbhit())   // kontrola klawiszy - pocz¹tek
		{
			
			//printf("wejscie do petli xx = %d\n", xx);

			key = _getch(); //w prawo dla prostok¹ta
			if (key == 'l')
			{
				run_prostokat++;
				xx = run_prostokat;
				
				//printf("run_prostokat= %d xx= %d\n",run_prostokat,xx);
			}

			//w prawo dla kwadratu*****************************************************
			if (key == 'd')
			{
				run_kwadrat++;
				xx_kwadrat = run_kwadrat;
				
				//printf("run_kwadrat_d= %d\n",run_kwadrat);
			}

			 // w lewo dla prostok¹ta
			if (key == 'j') 
			{
				//printf("%c\n", key);
				run_prostokat--;
				xx = run_prostokat;
				
			}
			
			 // w lewo dla kwadratu****************************************************
			if (key == 'a') 
			{
				run_kwadrat--;
				xx_kwadrat = run_kwadrat;
				//printf("run_kwadrat_a= %d\n", run_kwadrat);
			}
			
			
			if (key == 'r') //reset - zerowanie systemu 
			{
				xx = 1, yy = 1;
				xx_kwadrat = 1, yy_kwadrat = 1;
				system("cls");
				
				run_prostokat = 1;
				run_kwadrat = 1;
				// ukrywanie kursora poczatek========================
				HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
				CONSOLE_CURSOR_INFO ccur;
				ccur.dwSize = sizeof(CONSOLE_CURSOR_INFO);
				ccur.bVisible = false;
				SetConsoleCursorInfo(hStdOut, &ccur);
				// ukrywanie kursora koniec==========================

			}
			
			 // quit - wyjœcie
			if (key == 'q') 
			{
				system("cls");
				setlocale(LC_ALL, "polish"); // w³aczenie polskich znaków
				printf("Program zokoñczy³ dzia³anie\n");
				break;
			}
		}//kontrola klawiszy koniec
		
		
		SetConsoleCursorPosition(cons, pos); // ustawiamy kursor na wybrana pozycje
		
		
		printf("posX= %d posY= %d\n", pos.X, pos.Y);
		printf("run_prostokat= %3d\n", run_prostokat);
		printf("run_kwadrat= %3d\n", run_kwadrat);
	
			
	
		setlocale(LC_ALL, "polish"); // w³aczenie polskich znaków
		printf("Prostok¹t J - w lewo, L - w prawo\n" );
		printf("Kwadrat A - w lewo, D - w prawo\n");
		printf("Q - wyjœcie z programu, R - reset\n");
		setlocale(LC_ALL, ".852"); // wy³aczenie polskich znaków

		// rysowanie prostok¹ta - pocz¹tek
		printf("%*c",xx, naroznik_lewy_gorny);

		n = 0;
		while (n++, n < ilosc_znakow)
		{
			printf("%c", ramka_pozioma);
		}
	
		printf("%c %*c\n", naroznik_prawy_gorny, ilosc_znakow * 2 + 1, spacja);
		
		
		
		n = 0;
		while (n++, n < ilosc_znakow)
		{
			printf("%*c",xx, ramka_pionowa);
			printf("%*c %*c\n",ilosc_znakow, ramka_pionowa, ilosc_znakow * 2 + 1, spacja);
		}

		
		printf("%*c",xx, naroznik_lewy_dolny);

		n = 0;
		while (n++, n < ilosc_znakow)
		{
			printf("%c", ramka_pozioma);
		}
		printf("%c %*c\n",  naroznik_prawy_dolny, ilosc_znakow * 2 + 1, spacja);
	

		// Rysowanie kwadratu--------------------------------
		//printf("Podaj ilosc znakow dla kwadratu = ");
		//scanf("%d", &ilosc_znakow);

		printf("%*c", xx_kwadrat, naroznik_lewy_gorny);

		n = 0;
		int  ilosc_znakow_poziom = ilosc_znakow * 2;
		while (n++, n < ilosc_znakow_poziom)
		{
			printf("%c", ramka_pozioma);
		}

		printf("%c %*c\n", naroznik_prawy_gorny, ilosc_znakow * 2 + 1, spacja);



		n = 0;
		while (n++, n < ilosc_znakow)
		{
			printf("%*c",xx_kwadrat, ramka_pionowa );
			printf("%*c %*c\n", ilosc_znakow*2, ramka_pionowa, ilosc_znakow * 2 + 1, spacja);

			
			//printf("%*c", ilosc_znakow * 2 +1, spacja);
		}


		printf("%*c", xx_kwadrat, naroznik_lewy_dolny);

		n = 0;
		while (n++, n < ilosc_znakow_poziom)
		{
			printf("%c", ramka_pozioma );
		}
		//printf("%c\n", naroznik_prawy_dolny);
		printf("%c %*c\n", naroznik_prawy_dolny, ilosc_znakow * 2 + 1, spacja);
		
		
		

	}// pêtla nieskoñczona, koniec

	return 0;
}