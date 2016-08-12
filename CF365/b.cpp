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

int n, k, capitals [1000100];
long long int total_sum, capital_sum, c [100100];
bool capital [100100];

int get_next(int x)
{
	if (x != n)
		return x + 1;
	else
		return 1;
}

int get_prev(int x)
{
	if (x != 1)
		return x - 1;
	else
		return n;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> c [i];
		total_sum += c [i];
	}

	for (int i = 0; i < k; i++)
	{
		cin >> capitals [i + 1];
		capital [capitals [i + 1]] = true;
		capital_sum += c [capitals [i + 1]];
	}

	long long solution = 0LL;

	for (int i = 1; i <= n; i++)
	{
		if (capital [i])
			solution += c [i] * (total_sum - c [i]);
		else
		{
			int sum = capital_sum + c [get_prev(i)] + c [get_next(i)];
			if (capital [get_prev(i)])
				sum -= c [get_prev(i)];
			if (capital[get_next(i)])
				sum -= c [get_next(i)];

			solution += c [i] * sum;
		}
	}

	cout << solution / 2LL << endl;

	return 0;
}