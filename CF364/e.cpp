#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

vector <int> graph [100100];
bool visited [100100];
int v, k;	

void dfs (int current_node, int depth)
{
	if (depth == 0)
		memset (visited, false, sizeof visited);

	for (int x : graph [current_node])
		if (!visited [x])
			dfs (x, depth + 1);
}

int main()
{
	cin >> v >> k;
	for (int i = 0; i < 2 * k; i++)
	{
		int x, y;
		cin >> x >> y;
		graph [x].push_back(y);
		graph [y].push_back(x):
	}

	dfs (x);



	return 0;
}