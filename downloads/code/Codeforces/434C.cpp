#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back

const int mod = 1e9+7;
struct mint{
    int x;
    mint():x(0){}
    mint(int y){ if((x=y%mod+mod) >= mod) x-= mod;}

    mint &operator+=(const mint &m){ if((x += m.x) >= mod) x-=mod; return *this;}
    mint &operator-=(const mint &m){ if((x += mod-m.x) >= mod) x-=mod; return *this;}
    mint &operator*=(const mint &m){ x = 1LL*x*m.x%mod; return *this;}
    mint &operator/=(const mint &m){ x=(1LL*x*ex(m,mod-2).x)%mod; return *this;}
    mint operator+(const mint &m)const{ return mint(*this) += m;}
    mint operator-(const mint &m)const{ return mint(*this) -= m;}
    mint operator*(const mint &m)const{ return mint(*this) *= m;}
    mint operator/(const mint &m)const{ return mint(*this) /= m;}
    bool operator<(const mint &m)const{ return x < m.x;}
    mint ex(mint a, long long t){
        if(!t) return 1;
        mint res = ex(a,t/2);
        res *= res;
        return (t&1)?res*a:res;
    }
};
ostream &operator<<(ostream& os, const mint &m){ os << m.x; return os;}

struct PMA{
    int id, val, next[32];
    vector<int> matched;
    PMA(){memset(next, -1, sizeof(next)); val = 0; id = -1;}
};

PMA* pma[256];
int N, M, K, pl, v[32];
vector<vector<int>> ps;
vector<int> lr[2];
mint dp[210][210][510][2][2], ans[2];

vector<int> set_union(const vector<int> &a, const vector<int> &b){
    vector<int> res;
    set_union(all(a), all(b), back_inserter(res));
    return res;
}

PMA *buildPMA(vector<vector<int>> pattern){
    PMA *root, *now;
    pma[pl] = new PMA;
    root = pma[pl];
    root->id = pl;
    root->next[0] = pl++;
    for(int i = 0; i < (int)pattern.size(); ++i){
        auto &pat = pattern[i];
        now = root;
        for(int p: pat){
            ++p;
            if(now->next[p]<0){
                now->next[p] = pl;
                pma[pl] = new PMA;
                pma[pl]->id = pl;
                ++pl;
            }
            now = pma[now->next[p]];
        }
        now->matched.push_back(i);
    }
    
    queue<PMA*> que;
    for(int i = 1; i <= M; i++){
        if(root->next[i]<0) root->next[i] = root->id;
        else {
            pma[root->next[i]]->next[0] = root->id;
            que.push(pma[root->next[i]]);
        }
    }
    while(!que.empty()){
        now = que.front(); que.pop();
        for(int i = 1; i <= M; i++){
            if(now->next[i]>=0){
                PMA *nxt = pma[now->next[0]];
                while(nxt->next[i]<0) nxt = pma[nxt->next[0]];
                pma[now->next[i]]->next[0] = nxt->next[i];
                pma[now->next[i]]->matched = set_union(pma[now->next[i]]->matched, pma[nxt->next[i]]->matched);
                que.push(pma[now->next[i]]);
            }
        }
    }
    return root;
}

mint calc(int s){
    memset(dp,0,sizeof(dp));
    vector<int> &up = lr[s];
    dp[0][0][0][1][1] = 1;
    rep(i,up.size()) rep(j,pl) rep(k,K) rep(l,2) rep(m,2){
        if(!dp[i][j][k][l][m].x) continue;
        rep(d, m? up[i]+1: M) {
            int ni = i+1, nj = j, nk = k , nl = l&!d, nm = m&(up[i]==d);
            PMA *nxt = pma[j];
            while(nxt->next[d+1] < 0) nxt = pma[nxt->next[0]];
            nxt = pma[nxt->next[d+1]];
            if(!nl) nj = nxt->id, nk = min(K,k+nxt->val);
            dp[ni][nj][nk][nl][nm] += dp[i][j][k][l][m];
        }
    }
    mint ret = mint();
    rep(j,pl)rep(k,K)rep(l,2)rep(m,2)
        ret += dp[up.size()][j][k][l][m];
    return ret;
}

mint solve(){
    buildPMA(ps);
    rep(i,pl) for(int j: pma[i]->matched) pma[i]->val += v[j];
    int pos = lr[0].size()-1;
    do {
        if(pos+1<(int)lr[0].size()) lr[0][pos+1] = M-1;
        lr[0][pos]--;
    } while (lr[0][pos--]<0);
    if(lr[0].size() > 1 and !lr[0][0]) lr[0].erase(begin(lr[0]),begin(lr[0])+1);
    ++K;
    rep(i,2) ans[i] = calc(i);
    return ans[1]-ans[0];
}

void input(){
    cin >> N >> M >> K;
    rep(i,2){
        int len, d;
        cin >> len;
        while(len--) {
            cin >> d;
            lr[i].pb(d);
        }
    }
    rep(i,N){
        ps.pb(vector<int>());
        int len, d;
        cin >> len;
        while(len--) {
            cin >> d;
            ps[i].pb(d);
        }
        cin >> v[i];
    }
}

int main(){
    cin.sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
