#include <iostream>
#include <string>

#define rep(i,a) for(int i = 0;i < (a); i++)

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    string ans = "kogakubu10gokan";
    bool ok = false;
    while(n--){
        int y;
        string str;
        cin >> y >> str;
        if(!ok && y > q){
            ok = true;
        }
        if(!ok)ans = str;
    }
    cout << ans << endl;
}
