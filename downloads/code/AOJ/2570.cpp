#include <algorithm>
#include <iostream>
#include <string>

#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) (u).begin(),(u).end()
#define pb push_back

using namespace std;

string str;
int cur;
const int mod = 1000000007;

bool input(){
    str.clear();
    cur = 0;
    string tmp;
    getline(cin, tmp);
    if(tmp == "#") return 0;
    for(auto &c : tmp)if(c != ' ') str.pb(c);
    return 1;
}

void convert(){
    repi(i,3,str.size())
        if(((str[i] >= '0' && str[i] <= '9') || str[i] == 'S') &&
           str[i-1] == '>' && str[i-2] == '>'){
            str[i-2] = '$';
            str.erase(str.begin() + i - 1, str.begin() + i);
            i++;
        }
}

int number(){
    string ret;
    while(cur < str.size() && str[cur] >= '0' && str[cur] <= '9')
        ret.pb(str[cur++]);
    reverse(all(ret));
    return atoi(ret.c_str());
}

int expr();

int term(){
    if(str[cur] == '>'){
        cur++;
        int t = expr();
        cur += 2;
        return t * t % mod;
    }
    else return number();
}

int expr(){
    int right = term();
    if(cur >= str.size()) return right;
    if(str[cur] == '<')  return right;
    else{
        cur++;
        return expr() >> min(right, 31LL);
    }
}

int solve(){
    convert();
    reverse(all(str));
    return expr();
}

signed main(){
    while(input()){ cout << solve() << endl;}
    return 0;
}
