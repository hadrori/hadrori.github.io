#include <iostream>
#include <vector>
#include <string>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;
int n, m;

int main(){
    bool locked = true;
    cin >> n;
    vector<string> id(n);

    rep(i,n){
        cin >> id[i];
    }
    cin >> m;
    rep(i,m){
        string str;
        cin >> str;
        bool flag = false;
        rep(j,n){
            if(id[j] == str){
                if(locked){
                    cout << "Opened by " << str << endl;
                    locked = false;
                }else{
                    cout << "Closed by " << str << endl;
                    locked = true;
                }
                flag = true;
                break;
            }
        }
        if(!flag) cout << "Unknown " << str << endl;
    }
}