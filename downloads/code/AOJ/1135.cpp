#include <iostream>

#define rep(i, b) for(int i = 0; i < b; i++)

typedef long long ll;

using namespace std;

int main(){
    int m;
    cin >> m;
    rep(z, m){
        ll money;
        int y, n;
        ll maxa = 0;
        cin >> money >> y >> n;
        rep(i, n){
            bool hukuri;
            double rate;
            ll charge;
            cin >> hukuri >> rate >> charge;
            ll fortune = money;
            if(hukuri){
                rep(i,y){
                    fortune = fortune + fortune * rate;
                    fortune -= charge;
                }
            }else{
                ll interest = 0;
                rep(i,y){
                    interest += fortune * rate;
                    fortune -= charge;
                }
                fortune += interest;
            }
            maxa = max(maxa, fortune);
        }
        cout << maxa << endl;
    }
}