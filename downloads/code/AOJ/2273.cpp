#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 1e8
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
    set<string> used;
    string str = "a";
    while(1){
        cout << '?';
        cout << str << endl;
        used.insert(str);
        string tmp;
        cin >> tmp;
        if(used.find(tmp) != used.end()){
            printf("!OUT\n");
            break;
        }
        if(tmp[0] != str[str.size()-1]){
            printf("!OUT\n");
            break;
        }
        used.insert(tmp);
        reverse(all(tmp));
        if(used.find(tmp) == used.end()) str = tmp;
        else {
            while(used.find(tmp) != used.end()){
                tmp += tmp;
            }
            str = tmp;
        }
    }
}
