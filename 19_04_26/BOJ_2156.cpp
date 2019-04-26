#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int arrCoin[101] = { 0 };
	int arrDp[10001] = { 0 };
	for (size_t  i = 0; i < n; i++)
	{
		cin >> arrCoin[i];
	}

	arrDp[0] = 1;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = arrCoin[i]; j <= k; j++)
		{
			arrDp[j] += arrDp[j - arrCoin[i]];
		}
	}
	
	cout << arrDp[k];
	
	return 0;
}
