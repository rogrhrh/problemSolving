#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

typedef struct _ZERO_ONE_COUNT
{
	int zeroCount = 0;
	int oneCount = 0;
}zoCount;


//int fibonacci(int n)
//{
//	if (n == 0) {
//		zeroCount++;
//		return 0;
//	}
//	else if (n == 1) {
//		oneCount++;
//		return 1;
//	}
//	else {
//		return fibonacci(n - 1) + fibonacci(n - 2);
//	}
//}

int main()
{
	int T;
	int N;
	int nMax = 0;
	cin >> T;
	vector<int> nArr;

	while (T--)
	{
		cin >> N;
		nArr.push_back(N);
		
		for (int i = 0; i < N; i++)
		{
			if (N > nMax) nMax = N;
		}
	}

	vector<zoCount> dpTable(nMax + 1);
	dpTable[0].zeroCount = 1;
	dpTable[0].oneCount = 0;
	dpTable[1].zeroCount = 0;
	dpTable[1].oneCount = 1;

	for (int i = 2; i <= nMax; i++)
	{
		dpTable[i].zeroCount = dpTable[i - 2].zeroCount + dpTable[i - 1].zeroCount;
		dpTable[i].oneCount = dpTable[i - 2].oneCount + dpTable[i - 1].oneCount;
	}

	for (int i = 0; i < nArr.size(); i++)
	{
		cout << dpTable[nArr[i]].zeroCount << " " << dpTable[nArr[i]].oneCount << endl;
	}
	return 0;
}