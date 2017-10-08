#include <iostream>
using namespace std;
int main()
{
	float d,i;
	
	cout << "Inserisci la somma di denaro." <<endl;
	cin >> d;
	
	if(d>20000)
	{
		i=d*0.2;
	}
	else if(d>5000)
	{
		i=d*0.15;
	}
		else if(d>0)
		{
			i=d*0.10;
		}
		else
		{
			cout << "\033[31mIl valore inserito non è valido.\033[0m" <<endl;
			return 0;
		}
	cout << "L'imposta da pagare è di " << i << "€" <<endl;
	return 0;
}

