#include <fstream>
using namespace std;
ifstream fin("bonus.in");
ofstream fout("bonus.out");
void afiseazaBiti(int, int);
int pozitiaCeluiMaiSemnificativBit(int, int);
void seteazaBit(int &, int, bool);
bool bit(int x, int k);
int main()
{
  // dat fiind un numar n, genereaza toate submultimile distincte nevide din multimea {1, 2, ..., n}
	int n, x, k; 
	fin >> n;
	fin.close();
	x = 1;
	while (1)
	{
		afiseazaBiti(x, n);
		if (x == (1 << (n-1)))
 		{
			break;
		}
		else
		{
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
	fout.close();
	return 0;
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
