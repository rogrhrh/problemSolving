#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int **buildMagicSquare(int n, int start) {
	int **arr = new int *[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	int x = 0, y = n / 2;
	for (int i = start, j = 0; j < n * n; i++, j++) {
		arr[x--][y++] = i;
		if (x < 0 && y >= n) {
			x += 2;
			y--;
		}
		else if (x < 0) {
			x = n - 1;
		}
		else if (y >= n) {
			y = 0;
		}
		if (arr[x][y] > 0) {
			x += 2;
			y--;
		}
	}
	return arr;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
	int n = s.size(), start = 1;
	int cost[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int **magicSquare = buildMagicSquare(n, start);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n && n == s[i].size(); j++) {
			if (s[i][j] >= 1 && s[i][j] <= n * n) {
				cost[0] += abs(s[i][j] - magicSquare[i][j]);
				cost[1] += abs(s[i][j] - magicSquare[i][n - 1 - j]);
				cost[2] += abs(s[i][j] - magicSquare[j][i]);
				cost[3] += abs(s[i][j] - magicSquare[j][n - 1 - i]);
				cost[4] += abs(s[i][j] - magicSquare[n - 1 - i][j]);
				cost[5] += abs(s[i][j] - magicSquare[n - 1 - i][n - 1 - j]);
				cost[6] += abs(s[i][j] - magicSquare[n - 1 - j][i]);
				cost[7] += abs(s[i][j] - magicSquare[n - 1 - j][n - 1 - i]);
			}
		}
	}

	int min = 82;
	for (int i = 0; i < 8; i++) {
		if (cost[i] < min)
			min = cost[i];
	}

	return min;
}

int main()
{
	vector<vector<int>> s(3);
	for (int i = 0; i < 3; i++) {
		s[i].resize(3);

		for (int j = 0; j < 3; j++) {
			cin >> s[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int result = formingMagicSquare(s);

	cout << result << "\n";


	return 0;
}
