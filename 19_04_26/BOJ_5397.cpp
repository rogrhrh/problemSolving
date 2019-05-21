// BOJ.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

int main()
{
	string sOrigin;
	list<char> arrList;
	
	int N;
	cin >> N;
	while (N--)
	{
		cin >> sOrigin;
		arrList.clear();
		auto iter = arrList.end();
		for (int i = 0; i < sOrigin.length(); i++)
		{
			switch (sOrigin[i])
			{
			case '<':
				if (iter != arrList.begin())
				{
					iter--;
				}
				break;
			case '>':
				if (iter != arrList.end())
				{
					iter++;
				}
				break;
			case '-':
				if (iter != arrList.begin())
				{
					auto temp = iter;
					--temp;
					iter = arrList.erase(temp);
				}
				break;
			default :
				iter = arrList.insert(iter, sOrigin[i]);
				iter++;
				break;
			}
		}

		for (auto i : arrList)
		{
			cout << i;
		}
		cout << "\n";

	}

	return 0;
}

