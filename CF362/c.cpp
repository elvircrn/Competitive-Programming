#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>

using namespace std;

typedef long long ll;

map <pair <ll, ll>, ll> prices;

int main()
{
    int q;

    cin >> q;

    while (q--)
    {
        int t;

        cin >> t;

        if (t == 1)
        {
            long long v, u, w;

            //zamijenio si
            cin >> v >> w >> u;

            ll cV = v, cW = w, levelV = 0, levelW = 0;

            while (cV)
            {
                levelV++;
                cV /= 2;
            }

            while (cW)
            {
                levelW++;
                cW /= 2;
            }

            ll currentV = v, currentW = w;

            while (currentV != currentW)
            {
                ll prevV = currentV;
                ll prevW = currentW;
                if (levelV > levelW)
                {
                    currentV /= 2;
                    levelV--;
                }
                else if (levelV < levelW)
                {
                    currentW /= 2;
                    levelW--;
                }
                else
                {
                    currentW /= 2;
                    currentV /= 2;
                    levelW--;
                    levelV--;
                }

                if (prevV != currentV)
                {
                    prices [make_pair(prevV, currentV)] += u;
                    prices [make_pair(currentV, prevV)] += u;
                }

                if (prevW != currentW)
                {
                    prices [make_pair(prevW, currentW)] += u;
                    prices [make_pair(currentW, prevW)] += u;
                }
            }
        }
        else if (t == 2)
        {
            ll cost = 0, cV, cW, levelV = 0, levelW = 0, v, w;
            cin >> v >> w;
            cV = v;
            cW = w;
            while (cV)
            {
                levelV++;
                cV /= 2;
            }

            while (cW)
            {
                levelW++;
                cW /= 2;
            }

            ll currentV = v, currentW = w;

            while (currentV != currentW)
            {
                ll prevV = currentV;
                ll prevW = currentW;
                if (levelV > levelW)
                {
                    currentV /= 2;
                    levelV--;
                }
                else if (levelV < levelW)
                {
                    currentW /= 2;
                    levelW--;
                }
                else
                {
                    currentW /= 2;
                    currentV /= 2;
                    levelW--;
                    levelV--;
                }

                if (prevV != currentV)
                {
                    cost += prices [make_pair(prevV, currentV)];
                }

                if (prevW != currentW)
                {
                    cost += prices [make_pair(prevW, currentW)];
                }
            }

            cout << cost << endl;
        }
    }


    return 0;
}
