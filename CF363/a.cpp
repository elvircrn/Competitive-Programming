#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

#define MAXN 200100

string dirs;
int n, x [MAXN];
vector <int> left;
vector <int> right;

int currentR = -1;

int main()
{
	int n, solution = MAXN + 5;
	cin >> n >> dirs;
	for (int i = 0; i < n; i++)
	{
		cin >> x [i];	
		if (dirs [i] == 'R')
			currentR = x [i];
		else if (dirs [i] == 'L' && currentR != -1)
		{
			solution = min (solution, std::abs(currentR - x [i]));
		}
	}

	if (solution == MAXN + 5)
		cout << -1 << endl;
	else 
		cout << solution / 2 << endl;




	return 0;
}