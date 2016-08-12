#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <cfloat>

using namespace std;

double solution = DBL_MAX, v, x, y;
double a, b, dist;
int n;

int main()
{
    scanf ("%lf %f", &a, &b);
    scanf ("%d", &n);
    while (n--)
    {
        scanf ("%lf %lf %lf", &x, &y, &v);
        dist = sqrt ((x - a) * (x - a) + (y - b) * (y - b));
        solution = min (solution, dist / v);
    }

    printf ("%.9f\n", solution);

    return 0;
}
