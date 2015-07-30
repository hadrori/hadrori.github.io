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

char tr, ta;

bool awinb(string a, string b){

    if(a[1] == tr && b[1] != tr) return true;
    if(a[1] != tr && b[1] == tr) return false;
    if(a[1] == ta && b[1] != ta) return true;
    if(a[1] != ta && b[1] == ta) return false;
    int anum, bnum;
    if(a[0] == 'T') anum = 10;
    else if(a[0] == 'J') anum = 11;
    else if(a[0] == 'Q') anum = 12;
    else if(a[0] == 'K') anum = 13;
    else if(a[0] == 'A') anum = 14;
    else anum = a[0]-'0';
    if(b[0] == 'T') bnum = 10;
    else if(b[0] == 'J') bnum = 11;
    else if(b[0] == 'Q') bnum = 12;
    else if(b[0] == 'K') bnum = 13;
    else if(b[0] == 'A') bnum = 14;
    else bnum = b[0]-'0';
    
    return anum>bnum;
}

int main(){
    while(cin >> tr, tr!='#'){
        string Ca[4][13];
        rep(i,4)rep(j,13) cin >> Ca[i][j];
        int ew = 0, ns = 0;
        int win = 0;
        rep(z,13){
            int leader = win;
            string mc = Ca[leader][z];
            ta = Ca[leader][z][1];
            rep(i,4){
                if(i == leader) continue;
                if(Ca[i][z][1] != tr && Ca[i][z][1] != ta) continue;
                if(!awinb(mc,Ca[i][z])){
                    mc = Ca[i][z];
                    win = i;
                }
            }
            if(win==0||win==2) ns++;
            else ew++;
        }
        if(ew>6) cout << "EW " << ew-6 << endl;
        else cout << "NS " << ns-6 << endl;
    }
}
