#include <iostream>
#include <Windows.h>

int main()
{
	using namespace std;

	cout << "Apriori: ";

	for (int i = 0; i < 10; i++)
	{
		Sleep(250);
		cout << ".";
	}

	cout << "\nDone!" << endl;

	system("pause");
	return 0;
}