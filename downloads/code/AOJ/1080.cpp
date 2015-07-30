#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct chara{
    string name;
    int vote, num;
    chara(){}
    chara(string name, int vote, int num):name(name),vote(vote),num(num){}
    bool operator<(const chara &c) const{
        if(vote == c.vote) return name > c.name;
        return vote > c.vote;
    }
};

int N, M, K, L;
map<string,int> id;
int islike[100010], cnt[100010];
chara charas[100010], like[100010];

void init(){
    id.clear();
    memset(islike, 0, sizeof(islike));
    memset(cnt, 0, sizeof(cnt));
}

bool input(){
    cin >> N >> M >> K >> L;
    if(!N) return 0;
    init();
    for(int i = 0; i < N; i++){
        string str; cin >> str;
        cin >> cnt[i];
        id[str] = i;
        charas[i] = chara(str, cnt[i], i);
    }
    for(int i = 0; i < M; i++){
        string str; cin >> str;
        int t = id[str];
        islike[t] = 1;
        like[i] = chara(str, cnt[t], t);
    }
    return 1;
}

bool ok(int m){
    if(m > K || m > M) return 0;
    int prev = 0, cur = cnt[K-m], pos = K-m;
    while(cur - prev > 0){
        pos += cur - prev;
        prev = cur;
        cur = cnt[pos];
    }
    long long sum = 0;
    int border = charas[pos].vote;
    string bordername = charas[pos].name;
    for(int i = cnt[pos]; i < m; i++){
        sum += border - like[i].vote;
        if(like[i].name > bordername) sum++;
        if(sum > L) return 0;
    }
    return 1;
}

int solve(){
    sort(charas, charas+N);
    sort(like, like+N);
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = islike[charas[0].num];
    for(int i = 1; i < N; i++)
        cnt[i] = cnt[i-1] + islike[charas[i].num];

    int lb = 0, ub = M+1, mid;
    while(ub - lb > 1){
        mid = (lb + ub) / 2;
        if(ok(mid)) lb = mid;
        else ub = mid;
    }
    return lb;
}

int main(){
    cin.sync_with_stdio(0);
    while(input()) cout << solve() << endl;
    return 0;
}
