#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int n, m, columns [10010], total, rows [1010];
char matrix [1010] [1010];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> matrix [i];
		for (int j = 0; j < m; j++)
			total += (matrix [i] [j] == '*');
	}

	for (int i = 0; i < n ; i++)
		for (int j = 0; j < m; j++)
			rows [i] += (matrix [i] [j] == '*');

	for (int i = 0; i < m ; i++)
		for (int j = 0; j < n; j++)
			columns [i] += (matrix [j] [i] == '*');

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (rows [i] + columns [j] - (matrix [i] [j] == '*') == total)
			{
				cout << "YES\n" << i + 1 << ' ' << j + 1 << '\n';
				return 0;
			}
		}
	}

	cout << "NO\n";

	return 0;
}