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

long long int n, q, a [1000100], l, r;
long long int xor_to [1000100], prog [1000100];
bool visited [1000100];


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a [i];
		if (!visited [a [i]])
		{
			visited [a [i]] = true;
			prog [i] = prog [i - 1] ^ a [i];
		}
		else
			prog [i] = prog [i - 1];
		
		xor_to [i] = xor_to [i - 1] ^ a [i];
	}

	cin >> q;
	while (q--)
	{
		cin >> l >> r;
		long long reset = prog [l - 1] ^ prog [r];
		long long range = xor_to [r] ^ xor_to [l - 1];

		long long x = reset ^ range;

		cout << "reset: " << reset << " range: " << range << " result: " << x << endl;
	}


	return 0;
}