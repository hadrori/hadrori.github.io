#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> pii;
const int inf = 100;
vector<vector<pii> > skills;
int M, N;
bool can[128][128];
bool used[128];

bool ok(int a, int b){
    for(int i = 0; i < N; i++)
        if(skills[a][i].first > skills[b][i].second)
            return 0;
    return 1;
}

bool ok2(int cur){

    for(int i = 0; i < M; i++)
        if(!used[i] and !can[cur][i]) return 0;
    return 1;
}

bool solve(){
    cin >> M >> N;
    for(int i = 0; i < M; i++){
        vector<pii> res = vector<pii>(N, pii(0, inf));
        int K; cin >> K;
        for(int j = 0; j < K; j++){
            int s, t; string c;
            cin >> s >> c >> t;
            s--;
            if(c[0] == '>') res[s].first = max(res[s].first, t);
            else res[s].second = min(res[s].second, t);
            if(res[s].first > res[s].second) return 0;
        }
        skills.push_back(res);
    }    
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            if(ok(i, j)) can[i][j] = 1;
    int cnt = 0;
    for(int i = 0; i < M; i++){
        int f = -1;
        for(int j = 0; j < M; j++)
            if(!used[j] and ok2(j)){
                used[j] = 1;
                f = j;
                break;
            }
        if(f < 0) return 0;
        if(++cnt == M) return 1;
    }
    return 0;
}

int main(){
    cout << (solve()? "Yes": "No") << endl;
    return 0;
}
