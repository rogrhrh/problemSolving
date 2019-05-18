// BOJ.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> vTable(N + 1, 0);

	vTable[1] = 0;
	vTable[2] = 1;
	vTable[3] = 1;

	for (int i = 4; i <= N; i++)
	{
		if (i % 3 == 0)
		{
			vTable[i] = min(vTable[i - 1], vTable[i / 3]);
			vTable[i]++;
		}
		else if(i % 2 == 0)
		{
			vTable[i] = min(vTable[i - 1], vTable[i / 2]);
			vTable[i]++;
		}
		else
		{
			vTable[i] = vTable[i - 1] + 1;
		}
	}

	cout << vTable.back() << endl;
    return 0;
}

