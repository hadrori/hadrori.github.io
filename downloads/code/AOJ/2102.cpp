#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>

#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

using namespace std;

int n;
vector<pair<char,int> >cards;

bool mflag[10];

bool renzoku(bool* kflag);


bool onaji(bool* kflag){
    bool flag[10];
    rep(i,0,9)flag[i] = kflag[i];
    int a;
    int cnt = 0;
    char w;
    rep(i, 0, 9){
        if(!flag[i]){
            if(cnt == 0){
                w = cards[i].first;
                a = cards[i].second;
                cnt++;
            }else if(cnt < 3){
                if(cards[i].first != w) return false;
                else if(cards[i].second != a) return false;
                cnt++;
            }
            flag[i] = true;
            if(cnt == 3)break;
        }
    }
    bool skip = true;
    rep(i, 0, 9){
        if(!flag[i]){
            skip = false;
            break;
        }
    }
    if(!skip)return (onaji(flag) || renzoku(flag));
    return true;
    
}

bool renzoku(bool* kflag){
    bool flag[10];
    rep(i,0,9)flag[i] = kflag[i];
    int a;
    int cnt = 0;
    char w;
    rep(i, 0, 9){
        if(!flag[i]){
            if(cnt == 0){
                w = cards[i].first;
                a = cards[i].second;
                cnt++;
                flag[i] = true;
            }else if(cnt < 3){
                if(cards[i].first != w) return false;
                if(cards[i].second > a + 1) return false;
                else if(cards[i].second == a + 1){
                    a++;
                    flag[i] = true;
                    cnt++;
                }
            }
            
            if(cnt == 3)break;
        }
    }
    bool skip = true;
    rep(i, 0, 9){
        if(!flag[i]){
            skip = false;
            break;
        }
    }
    if(!skip)return (onaji(flag) || renzoku(flag));
    return true;
}

int main(){
    
    cin >> n;
    rep(k, 0, n){
        cards.clear();
        rep(i, 0, 9){
            int t;
            cin >> t;
            cards.push_back(make_pair('A',t));
        }
        rep(i, 0, 9){
            cin >> cards[i].first;
            mflag[i] = 0;
        }
        sort(cards.begin(),cards.end());
        //rep(i,0,9)cout << cards[i].first << ' ' << cards[i].second << endl;
        //cout <<endl;
        if(onaji(mflag) || renzoku(mflag)){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
        
        /*
        rep(i,0,9)cout << cards[i].first << ' ' << cards[i].second << endl;
        cout <<endl;
         */
    }
}