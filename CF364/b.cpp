#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct rook
{
	long long x, y;

	rook() { }
	rook(long long _x, long long _y) { x = _x; y = _y; }

	bool operator< (const rook &B) const
	{
		if (x != B.x)
			return x < B.x;
		else
			return y < B.y;
	}
};

long long n, m;
vector <rook> rooks;
bool vertical [100100], horizontal [100100];

int main()
{
	cin >> n >> m;
	long long ux = 0, uy = 0, effect = 0, x, y, area = n * n;
	for (long long i = 0; i < m; i++)
	{
		cin >> x >> y;
		rooks.emplace_back(x, y);


		if (!horizontal [x])
		{
			area -= n - uy;
			effect++;
			ux++;
		}

		if (!vertical [y])
		{
			area -= n - ux;
			effect++;
			uy++;
		}

		horizontal [x] = true;
		vertical   [y] = true;

		cout << area << endl;
	}

	return 0;
}
