#include  <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int comCount, N, result = 0;
	cin >> comCount;
	cin >> N;

	vector<vector<int>> arrComputerList(comCount + 1, vector<int>());

	int a, b;
	while (N--)
	{
		cin >> a >> b;
		arrComputerList[a].push_back(b);
		arrComputerList[b].push_back(a);
	}

	queue<int> visitQueue;
	for (int i = 0; i < arrComputerList[1].size(); i++)
	{
		visitQueue.push(arrComputerList[1][i]);
	}
	//arrComputerList[0]에서 visit 중복체크
	arrComputerList[0].resize(comCount+1, 0);
	arrComputerList[0][1] = 1;

	int toNum = 0;
	while (!visitQueue.empty())
	{
		toNum = visitQueue.front();
		visitQueue.pop();

		if (arrComputerList[0][toNum] != 1)
		{
			if (toNum != 0)
			{
				arrComputerList[0][toNum] = 1;

				result++;
				for (int i = 0; i < arrComputerList[toNum].size(); i++)
				{
					visitQueue.push(arrComputerList[toNum][i]);
				}
			}
		}
	}

	cout << result;


	return 0;
}
