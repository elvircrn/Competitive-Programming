#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

#define MAXV 100100

vector <int> graph [MAXV];
int parent [MAXV], n, dist [MAXV], sub [MAXV];

int dfs (int u)
{
    int s = 0;
    for (int v : graph [u])
        s += dfs (v);
    sub [u] = s;
    return s + 1;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        parent [i] = v;
        graph [v].push_back(i);
        dist [i] = dist [v] + 1;
    }





    return 0;
}
