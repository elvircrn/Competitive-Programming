
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

string parts [2] = { "hate", "love" };

int main()
{
	int n;
	cin >> n;

	cout << "I ";
	for (int i = 0; i < n; i++)
	{
		cout << parts [i % 2];
		if (i != n - 1)
			cout << " that I ";
	}
	cout << " it" << endl;

	return 0;
}
