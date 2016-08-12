#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

#define DFS_WHITE 0
#define DFS_GREY  1
#define DFS_BLACK 2

#define MAXN 200100

struct edge
{
	int u, v;

	edge() { u = -1; }
	edge(int _u, int _v) { u = _u; v = _v; }
};

bool visited [MAXN];
int group [MAXN], n, p [MAXN];
vector <int> graph [MAXN];
vector <int> members [MAXN];
vector <int> rev [MAXN];
edge back_edge [MAXN];

int dfs (int current_node, int color)
{
	visited [current_node] = DFS_GREY;
	group [current_node] = color;
	members [color].push_back(current_node);

	for (int v : graph [current_node])
	{
		if (!visited [v])
			dfs (v, color);
		else if (visited [v] == DFS_GREY && back_edge [color].u == -1)
		{
			back_edge [color] = edge (current_node, v);
		}
	}
	visited [current_node] = DFS_BLACK;
}

int main()
{
	int root, solution = 0, color = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p [i];
		if (p [i] == i)
			root = p [i];
		rev [p [i]].push_back(i);
		graph [i].push_back(p [i]);
		graph [p [i]].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		if (visited [i] == DFS_WHITE)
			dfs (i, color++);
	for (int i = 1; i < color; i++)
	{
		if (back_edge [i].u != -1 && group [back_edge [i].u] != group [root])
		{
			int u = back_edge [i].u, v = back_edge [i].v;
			//cout << u << ' ' << v;
			//int candidate = members [i - 1] [0];
			int candidate = root;
			//cout << " candidate: " << candidate << endl;
			if (p [u] == v)
				p [u] = candidate;
			else
				p [v] = candidate;

			solution++;
		}
	}

	cout << solution << endl;
	for (int i = 1; i <= n; i++)
		cout << p [i] << ' ';
	cout << endl;

	return 0;
}
