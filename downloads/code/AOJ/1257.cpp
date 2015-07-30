#include <bits/stdc++.h>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;

bool p[10010];
vi prm;

void pcalc(){
    rep(i,10010) p[i] = (i < 2)? false: true;
    rep(i,10010)if(p[i]){
        prm.pb(i);
        for(int j = i*2; j < 10010; j += i) p[j] = false;
    }
}

int main(){
    pcalc();
    int n;
    while(cin >> n, n){
        int left = 0, right = 0, sum = 2;
        int ans = 0;
        do{
            if(sum > n) sum -= prm[left++];
            if(sum < n) sum += prm[++right];
            if(sum == n) {
                ans++;
                sum -= prm[left++];
            }
        }while(prm[right] <= n && left != right);

        cout << ans << endl;
    }
    return 0;
}
