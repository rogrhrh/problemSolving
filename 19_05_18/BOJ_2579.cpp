// BOJ_2579.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>
#define START_STAIR 3
using namespace std;

int main()
{
	int N;	
	cin >> N;
	vector<int> vecData(N + START_STAIR, 0);
	vector<int> vecTable(N + START_STAIR, 0);

	for (int i = START_STAIR; i < N + START_STAIR; i++)
	{
		cin >> vecData[i];
	}

	for (int i = START_STAIR; i < vecTable.size(); i++)
	{
		vecTable[i] = max(vecData[i] + vecData[i - 1] + vecTable[i - 3], vecData[i] + vecTable[i - 2]);
	}
	
	cout << vecTable.back() << endl;

    return 0;
}

