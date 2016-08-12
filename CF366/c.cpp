#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <cstring>
#include <set>

using namespace std;

int read [300100];
int total, progress, count [300100];
vector <int> notifications;
set <int> Queue [300100];

int main()
{
	int n, q;
	cin >> n >> q;

	while (q--)
	{
		int t, x;
		cin >> t >> x;

		if (t == 1)
		{
			total++;
			notifications.push_back(x);
			Queue [x].insert(notifications.size() - 1);

		}
		else if (t == 3)
		{
			for (int i = progress; i < x; i++)
			{
				Queue [notifications [i]].erase(i);
				total -= (!read [i]);
				read [i] = true;
			}

			progress = max (progress, x);
		}
		else
		{
			for (int a : Queue [x])
			{
				total -= (!read [a]);
				read [a] = true;
			}
			Queue [x].clear();
		}

		cout << total << endl;
	}

	return 0;
}