#include <iostream>
#include <vector>

using namespace std;

int N, base = -2;
int main(){
    cin >> N;
    if(!N){
        cout << 0 << endl;
        return 0;
    }
    vector<int> ans;
    while(N){
        int res = N % (-2);
        N /= -2;
        if(res == -1){
            res = 1;
            N++;
        }
        ans.push_back(res);
    }
    for(int i = ans.size()-1; i >= 0; i--)
        cout << ans[i];
    cout << endl;
    return 0;
}
