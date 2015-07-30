#include <iostream>
#include <vector>
#include <string>

#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

using namespace std;

int gcd(int a, int b){
    //cout << 'A' << endl;
    if(b % a == 0) return a;
    if(a % b == 0) return b;
    if(b > a) return gcd(a, b % a);
    else return gcd(b, a % b);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}


int n, k;
/*
void shortans(vector<int> ans){
    vector<int> patte;
    patte.push_back(0);
    rep(i, 2, ans.size()){
        if((ans[i] != 0 || ans[i+1] != 0)){
            patte.push_back(i);
        }
        i++;
    }
    int gcds = patte[1] - patte[0];
    
    rep(i, 2, patte.size()){
        gcds = gcd(gcds, patte[i] - patte[i-1]);
    }
    
    if(patte.size() == 1){
        ans.clear();
        ans.push_back(0);
        ans.push_back(0);
        return;
    }
    if(gcds != 1){
        for(int i = 1; i < patte.size() ; i++){
            patte.erase(patte.begin() + i - 1);
            patte.erase(patte.begin() + 1 - 2);
        }
        patte.erase(patte.begin() + patte.size() - 1);
        patte.erase(patte.begin() + patte.size() - 2);
    }
    while(gcds != 1){
        patte.clear();
        
        patte.push_back(0);
        rep(i, 2, ans.size()){
            if((ans[i] != 0 || ans[i+1] != 0)){
                patte.push_back(i);
            }
            i++;
        }
        int gcds = patte[1] - patte[0];
        
        rep(i, 2, patte.size()){
            gcds = gcd(gcds, patte[i] - patte[i-1]);
        }
    }
}*/

int main(){
    cin >> n;
    
    rep(z, 0, n){
        cin >> k;
        
        vector<string> rhythm(k);
        
        rep(i, 0, k) cin >> rhythm[i];
        int lcms = rhythm[0].size();
        
        //cout << lcms << endl;
        
        rep(i, 1, k){
            //cout << rhythm[i].size()<< endl;
            lcms = lcm(lcms, rhythm[i].size());
        }
        
        
        
        if(lcms * 2 > 2048){
            cout << "Too complex." << endl;
        }else{
            vector<int> ans(lcms);
            rep(i, 0, lcms * 2) ans[i] = 0;
            rep(i, 0, k){
                int l = (lcms - rhythm[i].size()) / (rhythm[i].size() / 2);
                //cout << l << endl;
                int m = 0;
                for(int j = 0; j + 1 < rhythm[i].size(); j++){
                    ans[m++] += rhythm[i][j++] - '0';
                    ans[m] += rhythm[i][j] - '0';
                    m += l + 1;
                }
                /*
                rep(j, 0, ans.size()) cout << ans[j];
                cout << endl;
                */
            }
            //shortans(ans);
            
            rep(i, 0, lcms){
                if(ans[i] < 10)cout << ans[i];
                else{
                    char ch = 'A' - 10 + ans[i];
                    cout << ch;
                }
            }
            cout << endl;
            ans.clear();
        }
    }
    
}