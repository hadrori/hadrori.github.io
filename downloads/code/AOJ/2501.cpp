#include <iostream>
#include <cstdlib>

#define repi(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int main(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a--, b--, c--, d--;
    int dis = 10000000;
    for(int i = 1; i <= n; i++){
        int ab = abs(a % i - b % i) + abs(a / i - b / i);
        int cd = abs(c % i - d % i) + abs(c / i - d / i);
        dis = min(dis, ab + cd);
    }
    cout << dis << endl;
    
}