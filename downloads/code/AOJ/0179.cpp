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

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

bool check(string str){
    char t = str[0];
    rep(i,str.size()) if(str[i] != t) return false;
    return true;
}

int main(){
    string worm;
    while(cin >> worm, worm != "0"){
        int n = worm.size();
        map<string,int> did;
        queue<string> bfs;
        bool ok = false;
        did[worm] = 0;
        bfs.push(worm);

        while(!bfs.empty()){
            string str = bfs.front();
            int cnt = did[str];
            bfs.pop();
            if(ok = check(str)){
                cout << did[str] << endl;
                break;
            }
            rep(i,n-1) if(str[i] != str[i+1]){
                string tmp = str;
                if((tmp[i]=='r' && tmp[i+1]=='b') || (tmp[i]=='b' && tmp[i+1]=='r')){
                    tmp[i] = 'g';
                    tmp[i+1] = 'g';
                }
                else if((tmp[i]=='b' && tmp[i+1]=='g') || (tmp[i]=='g' && tmp[i+1]=='b')){
                    tmp[i] = 'r';
                    tmp[i+1] = 'r';
                }
                else if((tmp[i]=='g' && tmp[i+1]=='r') || (tmp[i]=='r' && tmp[i+1]=='g')){
                    tmp[i] = 'b';
                    tmp[i+1] = 'b';
                }

                if(did.find(tmp) == did.end()){
                    did[tmp] = cnt+1;
                    bfs.push(tmp);
                }
            }
        }
        if(!ok) cout << "NA\n";
    }
}
