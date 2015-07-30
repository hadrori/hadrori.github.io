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
#include <bitset>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

int h, w, n;

int di[2] = {0,1};
int dj[2] = {1,0};

vector<string> fall(vector<string> field){
    vector<string> ret = field;
    rep(k,h+1)repd(i,h-2,-1)rep(j,w){
        if(ret[i+1][j] == '.' && ret[i][j] != '.')swap(ret[i][j],ret[i+1][j]);
    }
    return ret;
}

bool ok(vector<string> field){
    vector<string> ne = field;
    bool changed = false;

    rep(i,h)rep(j,w)if(field[i][j]!='.'){
        char ch = field[i][j];
        rep(k,2){
            int cnt = 0, ti = i, tj = j;
            while(field[ti][tj] == ch){
                cnt++;
                ti += di[k];
                tj += dj[k];
                if(ti>h-1 || tj>w-1) break;
            }
            ti = i;
            tj = j;
            while(field[ti][tj] == ch){
                cnt++;
                ti -= di[k];
                tj -= dj[k];
                if(ti<0 || tj<0) break;
            }
            if(cnt>n){
                changed = true;
                ti = i;
                tj = j;
                while(field[ti][tj] == ch){
                    ne[ti][tj] = '.';
                    ti += di[k];
                    tj += dj[k];
                    if(ti>h-1 || tj>w-1) break;
                }
                ti = i;
                tj = j;
                while(field[ti][tj] == ch){
                    ne[ti][tj] = '.';                   
                    ti -= di[k];
                    tj -= dj[k];
                if(ti<0 || tj<0) break;
                }
            }
        }
    }

    bool cl = true;
    rep(i,h){
        rep(j,w)if(ne[i][j]!='.'){
            cl = false;
            break;
        }
        if(!cl) break;
    }
/*
    rep(i,h){
        rep(j,w)cout << ne[i][j] << ' ';
        cout << endl;
    }
*/
    if(cl) return true;
    if(!changed) return false;
    return ok(fall(ne));
}

int main(){
    cin >> h >> w >> n;
    vector<string> field(h);
    rep(i,h) cin >> field[i];
    rep(i,h)rep(j,w-1){
        vector<string> tmp = field;
        swap(tmp[i][j],tmp[i][j+1]);
        tmp = fall(tmp);
        if(ok(tmp)){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
