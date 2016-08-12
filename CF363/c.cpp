#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

#define NOTHING 0
#define GYM 1
#define IT 2
#define MAXN 110

bool availabe(int when, int what)
{
	return ((what == IT && (when == 1 || when == 3)) || ((what == GYM && (when == 2 || when == 3))));
}

int n, x [MAXN], dp [MAXN] [3];


int main()
{
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < 3; j++)
			dp [i] [j] = 10 * MAXN;

	//memset (dp, 0, sizeof dp);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x [i];

	for (int i = 0; i < 3; i++)
		dp [0] [i] = 0;

	for (int i = 0; i < n; i++)
	{
		dp [i + 1] [NOTHING] = min ((dp [i + 1] [0], dp [i] [0] + 1), min (dp [i] [IT] + 1, dp [i] [GYM] + 1));
		if (availabe(x [i], IT))
			dp [i + 1] [IT] = min (dp [i + 1] [IT], min (dp [i] [NOTHING], dp [i] [GYM]));
		if (availabe(x [i], GYM))
			dp [i + 1] [GYM] = min (dp [i + 1] [GYM], min (dp [i] [NOTHING], dp [i] [IT]));
	}

	int solution = MAXN;
	for (int i = 0; i < 3; i++)
		solution = min (solution, dp [n] [i]);

	cout << solution << endl;

	return 0;
}