#include <fstream>
#include <iostream>
#define MAX_N 10
#define MAX_S (1<<MAX_N)
using namespace std;
int n, C[MAX_S][MAX_N];
void codGray(int);
void afiseazaRezultat();
int main()
{
	cout << "n = "; cin >> n;
	codGray(n);
	afiseazaRezultat();
	return 0;
}
void afiseazaRezultat()
{
	ofstream fout("codGray.out");
	int i, j;
	for (i = 0; i < (1<<n); i++) //(1<<n) = 2^n
	{
		for (j = 0; j < n; j++)
		{
			fout << C[i][j];
		}
		fout << '\n';
	}
	fout.close();
}
void codGray(int x)
{
	int i, j;
	if (x == 1)
	{
		C[1][0] = 1;
	}
	else
	{
		codGray(x-1);
		for (i = (1<<(x-1))-1; i >= 0; i--)
		{
			// oglindim C(x-1) si completam cu 1 coloana x-1
			for (j = 0; j < x-1; j++)
			{
				C[(1<<x)-i-1][j] = C[i][j];
			}
			C[(1<<x)-i-1][x-1]=1;
		}
	}
}
