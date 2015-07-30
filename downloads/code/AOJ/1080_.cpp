#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int,string> pis;

int N, M, K, L;

vector<pis> all, fav, nfav;
map<string, int> isfav;

void init(){
    isfav.clear();
    all.clear();
    fav.clear();
    nfav.clear();
}

bool input(){
    cin >> N >> M >> K >> L;
    if(!N) return 0;
    init();
    for(int i = 0; i < N; i++){
        string str; cin >> str;
        int t; cin >> t;
        all.push_back(pis(-t,str));
    }
    for(int i = 0; i < M; i++){
        string str; cin >> str;
        isfav[str] = 1;
    }
    return 1;
}

bool ok(int m){
    if(m > K) return 0;
    if(nfav.size() <= K-m) return 1;
    long long sum = 0;
    for(int i = 0; i < m; i++){
        sum += max(0, fav[i].first - nfav[K-m].first);
        if(nfav[K-m].first <= fav[i].first && nfav[K-m].second < fav[i].second) sum++;
        if(sum > L) return 0;
    }
    return sum <= L;
}

int solve(){
    for(vector<pis>::iterator it = all.begin(); it != all.end(); it++)
        if(isfav[it->second]) fav.push_back(*it);
        else nfav.push_back(*it);
    sort(fav.begin(), fav.end());
    sort(nfav.begin(), nfav.end());
    int lb = 0, ub = M+1, mid;
    while(ub - lb > 1){
        mid = (ub + lb) / 2;
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
