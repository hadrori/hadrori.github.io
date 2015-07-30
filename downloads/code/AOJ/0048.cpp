#include <bits/stdc++.h>
using namespace std;

const string s[] = {"light fly", "fly", "bantam", "feather", "light", "light welter", "welter", "light middle", "middle", "light heavy", "heavy"};
const double t[] = {48, 51, 54, 57, 60, 64, 69, 75, 81, 91, 1e9};

string solve(double w)
{
    return s[lower_bound(t,t+11,w)-t];
}

int main()
{
    double w;
    while(cin >> w) cout << solve(w) << endl;
    return 0;
}
