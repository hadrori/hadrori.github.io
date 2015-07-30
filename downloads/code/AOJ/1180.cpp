#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i, b) for(int i = 0; i < b; i++)
#define pb push_back

using namespace std;

int main(){
    int t, l;
    while(cin >> t >> l, t || l){
        vector<int> a;
        a.pb(t);
        int i = 0, j;
        bool cflag = true;
        while(cflag){
            vector<int> dig(l);
            int tmp = a[i];
            rep(k,l) dig[k] = tmp % 10, tmp /= 10;
            
            sort(dig.begin(),dig.end());
            
            int maxa = 0, mina = 0;
            rep(k,l){
                maxa *= 10;
                mina *= 10;
                maxa += dig[l-k-1];
                mina += dig[k];
            }

            a.pb(maxa - mina);
            i++;
            
            rep(k,i){
                if(a[i] == a[k]){
                    cflag = false;
                    j = k;
                    break;
                }
            }
        }
        
        cout << j << ' ' << a[i] << ' ' << i-j << endl;
    }
}