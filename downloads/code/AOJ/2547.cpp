#include <iostream>
#include <queue>

using namespace std;

int main(){

    int n, ans = 0;
    cin >> n;
    priority_queue<int> s;
    while(n--){
        int a;
        cin >> a;
        while(!s.empty() && s.top() > a) s.pop();
        if(s.empty() || s.top() != a){
            s.push(a);
            ans++;
        }
    }
    cout << ans << endl;
}
