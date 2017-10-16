

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAX_INSTANCE 100
#define NUM_OF_VAL 5
using namespace std;

class randNo
{
public:
	void randNumGen(int n);
	double *randNumFreq(int n); 
	randNo()
	{
		for(int i=0;i<NUM_OF_VAL;i++) freq[i] = 0;
	}
private:
	int history[MAX_INSTANCE];
	int freq[NUM_OF_VAL];

};

/*********************************************************************************** 
*  Description:	
*	Random number generator
*	1 - 50%
*	2 - 25%
*	3 - 15%
*	4 - 5%
*	5 - 5%
************************************************************************************/
void randNo::randNumGen(int n)
{
	int number;
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		number = rand() % 100;

		if (number < 50) // 0-49
		{
			cout << "1" << endl;
			history[i] = 1;
		}
		else if (number < 75) // 50-74
		{
			cout << "2" << endl;
			history[i] = 2;
		}
		else if (number < 90) // 74-89
		{
			cout << "3" << endl;
			history[i] = 3;
		}
		else if (number < 95) // 90-94
		{
			cout << "4" << endl;
			history[i] = 4;
		}
		else // 95-99
		{
			cout << "5" << endl;
			history[i] = 5;
		}
	}
}
/***********************************************************************************
* Description:
* Count generated random number frequency and return
************************************************************************************/
double *randNo::randNumFreq(int n)
{
	int i;
	double *freq_percentage = new double[5];
	for (i = 0; i < n; i++)
	{
		switch (history[i])
		{
		case 1:
			freq[0]++;
			break;
		case 2:
			freq[1]++;
			break;
		case 3:
			freq[2]++;
			break;
		case 4:
			freq[3]++;
			break;
		case 5:
			freq[4]++;
			break;
		}
	}
	for (i = 0; i < NUM_OF_VAL; i++)
	{
		freq_percentage[i] = (double)freq[i] / (double)n;
	}
	return freq_percentage;
}

int main()
{
	randNo RN;
	int iteration = 100;
	// Generate random number 100 times
	RN.randNumGen(iteration);
	// Count frequencies of generated numbers
	double *random_no_freq = RN.randNumFreq(iteration);
	return 0;
}

