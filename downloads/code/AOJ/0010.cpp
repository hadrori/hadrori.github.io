#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <bitset>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

typedef long long ll;

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        double a1 = 2*(x2-x1), a2 = 2*(x3-x1);
        double b1 = 2*(y2-y1), b2 = 2*(y3-y1);
        double c1 = x1*x1 - x2*x2 + y1*y1 - y2*y2;
        double c2 = x1*x1 - x3*x3 + y1*y1 - y3*y3;
        double x = (b1*c2 - b2*c1) / (a1*b2 - a2*b1);
        double y = (c1*a2 - c2*a1) / (a1*b2 - a2*b1);
        double r = sqrt((x1-x)*(x1-x) + (y1-y)*(y1-y));
        printf("%.3f %.3f %.3f\n", x, y, r);
    }

}
