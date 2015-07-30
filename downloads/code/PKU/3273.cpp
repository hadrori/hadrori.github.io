#include <iostream>
#include <vector>
#define rep(i,a) for(int i = 0;i < (a); i++)
using namespace std;
typedef vector<int> vi;

int N, M;
vi spends;

bool can(int n){
    int cnt = 0, sum = 0;
    rep(i,N){
        if(sum + spends[i] > n){
            sum = 0;
            cnt++;
        }
        sum += spends[i];
        if(sum > n) return false;
    }
    return cnt < M;
}

int main(){
    cin >> N >> M;
    spends.resize(N);
    rep(i,N) cin >> spends[i];
    int lb = 0, ub = 1000000100;
    while(lb + 1 < ub){
        int mid = (lb + ub) / 2;
        if(can(mid)) ub = mid;
        else lb = mid;
    }
    cout << ub << endl;
    return 0;
}
