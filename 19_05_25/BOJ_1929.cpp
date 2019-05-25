#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	
	int N, M;
	scanf("%d %d", &M, &N);
//	cin >> M >> N;

	vector<bool> sieveOfEratosthenes(N + 1, true);
	sieveOfEratosthenes[1] = false;

	for (int i = 2; i <= N; i++)
	{
		if (sieveOfEratosthenes[i]) {
			//if (pow(i, 2) > N) break;
			/*for (int j = pow(i, 2); j <= N; j += i)
			{
				sieveOfEratosthenes[j] = false;
			}*/
			for (int j = 2; j * i <= N; j++)
			{
				sieveOfEratosthenes[j*i] = false;
			}
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (sieveOfEratosthenes[i] == true)
		{
			//cout << i << endl;
			printf("%d\n", i);
		}
	}
}
