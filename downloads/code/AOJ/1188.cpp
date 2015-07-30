#include <bits/stdc++.h>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define all(u) (u).begin(),(u).end()
#define pb push_back
using namespace std;
typedef vector<int> vi;

int stoi(string num){
    int ret;
    stringstream s;
    s << num;
    s >> ret;
    return ret;
}

string str;
int cur;

int rec(){
    cur++;
    if(str[cur] != '[' && str[cur] != ']'){
        string t;
        while(str[cur] != '[' && str[cur] != ']')
            t += str[cur++];
        cur++;
        return stoi(t) / 2 + 1;
    }
    vi vote;
    while(str[cur] != ']'){
        vote.pb(rec());
    }
    sort(all(vote));
    int ret = 0;
    rep(i,vote.size()/2+1) ret += vote[i];
    cur++;
    return ret;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> str;
        cur = 0;
        cout << rec() << endl;
    }
    return 0;
}
