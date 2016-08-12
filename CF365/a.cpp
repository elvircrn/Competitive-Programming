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

int x [3];

int res(int a, int b)
{
	if (a < b)
		return 1;
	else if (a > b)
		return 2;
	else
		return 0;
}

int main()
{
	int n, a, b;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		x [res(a, b)]++;
	}

	if (x [1] > x [2])
		cout << "Chris" << endl;
	else if (x [1] < x [2])
		cout << "Mishka" << endl;
	else
		cout << "Friendship is magic!^^" << endl;

	return 0;
}