#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int n;
bool winner = true;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x % 2 == 1)
		{
		}
		else
		{
			winner ^= 1;
		}
		cout << winner + 1 << endl;
	}

	return 0;
}