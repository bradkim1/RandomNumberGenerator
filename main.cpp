
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

/*********************************************************************************** 
	Random number generator
*	1 - 50%
*	2 - 25%
*	3 - 15%
*	4 - 5%
*	5 - 5%
************************************************************************************/
void randNumGen(int n)
{
	int number;
	srand(time(0));
	for (int i = 1; i <= n; i++)
	{
		number = rand() % 100;
		if (number < 50) // 0-49
			cout << "1" << endl;
		else if (number <75) // 50-74
			cout << "2" << endl;
		else if (number < 90) // 74-89
			cout << "3" << endl;
		else if (number < 95) // 90-94
			cout << "4" << endl;
		else // 95-99
			cout << "5" << endl;
	}
}

int main()
{
	randNumGen(100);
	return 0;
}

