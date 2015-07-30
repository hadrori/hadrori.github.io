#include <iostream>
#include <queue>

#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int n, a, b, c, x;

int nextrand(int x0){
    return (a * x0 + b) % c;
}

int main(){
    while(cin >> n >> a >> b >> c >> x, n){
        queue<int> y;
        rep(i, 0, n){
            int t;
            cin >> t;
            y.push(t);
        }
        int nx = x;
        int cnt = -1;
        while(!y.empty()){
            if(cnt >= 10000)break;
            if(y.front() == nx){
                y.pop();
            }
            nx = nextrand(nx);
            cnt++;
        }
        if(y.empty()) cout << cnt << endl;
        else cout << -1 << endl;
    }
    
}