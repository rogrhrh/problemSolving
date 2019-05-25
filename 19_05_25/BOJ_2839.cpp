// 19_05_25.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int ThreeKg = 3;
const int FiveKg = 5;

int main()
{
	int N;
	int packageNum = 2000;
	int noAnswerFlag = 0;

	cin >> N;
	int temp;
	for (int  i = 0; FiveKg * i <= N; i++)
	{
		temp = N - (FiveKg * i);
		if (temp == 0 && i < packageNum)
		{
			packageNum = i;
			if(!noAnswerFlag) noAnswerFlag = 1;
		}

		if (temp % ThreeKg == 0 && (temp / ThreeKg) + i < packageNum)
		{
			packageNum = (temp / ThreeKg) + i;
			if (!noAnswerFlag) noAnswerFlag = 1;
		}
	}

	if (noAnswerFlag)
		cout << packageNum << endl;
	else
		cout << "-1" << endl;
    return 0;
}

