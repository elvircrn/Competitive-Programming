#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct card
{
	int val, index;

	card() { }
	card(int _val, int _index) { val = _val; index = _index; }

	void get(int i)
	{
		index = i;
		cin >> val;
	}

	bool operator< (const card &B) const
	{
		return val < B.val;
	}
};

int n;
card cards [2000];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cards [i].get(i);

	sort (cards, cards + n);

	for (int i = 0; i < n / 2; i++)
		cout << cards [i].index + 1 << ' ' << cards [n - i - 1].index + 1<< endl;

	return 0;
}