#include <fstream>
using namespace std;
// fisiere citire/scriere
ifstream fin("bonus.in");
ofstream fout("bonus.out");
// variabile globale
int n;
// functii ajutatoare
void submultimeaUrmatoare(int &);
void submultime(int);
void afiseazaSubmultime(int);
void afiseazaBiti(int, int);
void seteazaBit(int &, int, bool);
int nrOrdine(int);
int pozitiaCeluiMaiSemnificativBit(int, int);
bool bit(int, int);
// functia principala
int main()
{
	int m, i, tip, lg, x, j, k;
	fin >> n >> m;
	for (i = 0; i < m; i++)
	{
		fin >> tip;
		if (tip == 1)
		{
			fin >> lg;
			for (x = j = 0; j < lg; j++)
			{
				fin >> k;
				seteazaBit(x, k-1, 1);
			}
			fout << nrOrdine(x) << '\n';
		}
		else
		{
			fin >> k;
			submultime(k);
		}
	}
	fin.close();
	fout.close();
	return 0;
}
int nrOrdine(int y)
{
	// data fiind o submultime reprezentata binar, sa se determine numarul ei de ordine
	int nr, x, k;
	nr = x = 1;
	while (x != y)
	{
		submultimeaUrmatoare(x);
		nr++;
	}
	return nr;
}
void submultime(int nro)
{
	// dat fiind un numar de ordine, sa se determine submultimea corespunzatoare
	int nr, x, k;
	nr = x = 1;
	while (nr < nro)
	{
		submultimeaUrmatoare(x);
		nr++;
	}
	afiseazaSubmultime(x);
}
void submultimeaUrmatoare(int & x)
{
	if (x != (1 << (n-1)))
	{
		int k;
		if (bit(x, n-1))
		{
			seteazaBit(x, n-1, 0);
			k = pozitiaCeluiMaiSemnificativBit(x, n);
			seteazaBit(x, k, 0);
			seteazaBit(x, k+1, 1);
		}
		else
		{
			k = pozitiaCeluiMaiSemnificativBit(x, n);
			seteazaBit(x, k+1, 1);
		}
	}
}
void afiseazaSubmultime(int x)
{
	// descifreaza reprezentarea binara a lui x si afiseaza submultimea corespunzatoare
	for (int i = 0; i < n; i++)
	{
		bool bit = x & (1 << i);
		if (bit)
		{
			fout << i+1 << ' ';
		}
	}
	fout << '\n';
}
void afiseazaBiti(int x, int nrb)
{
	// afiseaza reprezentarea binara a lui x folosind nrb biti
	bool bit;
	for (int i = nrb-1; i >= 0; i--)
	{
		bit = x & (1 << i);
		fout << bit << ' ';
	}
	fout << '\n';
}
int pozitiaCeluiMaiSemnificativBit(int x, int nrb)
{
	// returneaza pozitia celui mai semnificativ bit 1 din reprezentarea binara a lui x
	// x este reprezentat folosind nrb biti
	int k;
	for (k = nrb-1; (x & (1 << k)) == 0; k--);
	return k;
}
void seteazaBit(int & x, int k, bool bit)
{
	// seteaza bitul k din reprezentarea binara a lui x
	// daca bit = 1, atunci bitul k devine 1
	// daca bit = 0, atunci bitul k devine 0
	if (bit)
	{
		x = x | (1 << k);
	}
	else
	{
		x = x & (255 - (1 << k));
	}
}
bool bit(int x, int k)
{
	// returneaza bitul k din reprezentarea binara a lui x
	return x & (1 << k);
}
