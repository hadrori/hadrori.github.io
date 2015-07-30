#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d, e;
    while(cin >> a >> b >> c >> d >> e, a || b || c || d || e){
        int na, nb, nc, ans = 0;
        cin >> na >> nb >> nc;
        if(nc >= d)
            ans = e * nc + b * nb + a * na;
        else{
            int dcnt = d;
            ans = c * nc + b * nb + a * na;
            dcnt -= nc;
            if(dcnt > nb){
                dcnt -= nb;
                nb = 0;
            }else{
                nb -= dcnt;
                dcnt = 0;
            }
            if(dcnt > na){
                dcnt -= na;
                na = 0;
            }else{
                na -= dcnt;
                dcnt = 0;
            }
            ans = min(ans, e * d + b * nb + a * na);
        }
        cout << ans << endl;
    }
    return 0;
}
