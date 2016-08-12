#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int main()
{
    int pos1, pos2;
    int a, b;
    stringstream ss, sol;
    string one, two, three, input;

    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        if (input [i] == 'e')
            pos2 = i;
        else if (input [i] == '.')
            pos1 = i;
    }

    one = input.substr(0, pos1);
    two = input.substr(pos1 + 1, pos2 - pos1 - 1);
    three = input.substr(pos2 + 1, input.length() - pos2);

    ss << three;
    ss >> b;

    sol << one;

    for (int i = 0; i < b && i < two.length(); i++)
        sol << two [i];

    if (b < two.length())
    {
        sol << '.';
        for (int i = b; i < two.length(); i++)
            sol << two [i];
    }
    else
    {
        for (int i = two.length(); i < b; i++)
            sol << '0';
    }

    string solution = sol.str();

    bool gate = true;

    for (int i = 0; i < solution.length(); i++)
    {
        if (solution [i] != '0' || solution [i + 1] == '.')
            gate = false;

        if (!gate)
            cout << solution [i];
    }

    cout << '\n';

    return 0;
}
