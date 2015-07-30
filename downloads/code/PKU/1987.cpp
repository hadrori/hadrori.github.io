#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
const int inf = int(1e9);
struct edge{
    int to, dist;
    edge(){}
    edge(int to, int dist):to(to),dist(dist){}
};
int N, M, K;
int cnt[40010];
edge G[40010][4];
bool used[40010];
int subtree_size[40010];

int ans;
int calc_subtree(int v, int p){
    int c = 1;
    for(int i = 0; i < cnt[v]; i++){
        int w = G[v][i].to;
        if(w == p || used[w]) continue;
        c += calc_subtree(w, v);
    }
    subtree_size[v] = c;
    return c;
}

pii search_centroid(int v, int p, int t){
    pii res = pii(inf, -1);
    int s = 1, m = 0;
    for(int i = 0; i < cnt[v]; i++){
        int w = G[v][i].to;
        if(w == p || used[w]) continue;
        res = min(res, search_centroid(w, v, t));
        m = max(m, subtree_size[w]);
        s += subtree_size[w];
    }
    return min(res, pii(max(m,t-s),v));
}

void enumerate_paths(int v, int p, int d, vector<int> &ds){
    ds.push_back(d);
    for(int i = 0; i < cnt[v]; i++){
        int w = G[v][i].to;
        if(w == p || used[w]) continue;
        enumerate_paths(w, v, d+(G[v][i].dist), ds);
    }
}

int count_pairs(vector<int> &ds){
    int res = 0;
    sort(ds.begin(), ds.end());
    vector<int>::iterator jtr = ds.end();
    int j = ds.size(), i = 0;
    for(vector<int>::iterator itr = ds.begin(); itr != ds.end(); itr++, i++){
        while(jtr != ds.begin()  and *(itr) + *(jtr-1) > K) --jtr, --j;
        res += j - (j>i? 1: 0);
    }
    return res / 2;
}

void solve_sub(int v){
    calc_subtree(v, -1);
    int s = search_centroid(v, -1, subtree_size[v]).second;
    used[s] = 1;
    for(int i = 0; i < cnt[s]; i++)
        if(!used[G[s][i].to]) solve_sub(G[s][i].to);
    vector<int> ds;
    ds.push_back(0);
    for(int i = 0; i < cnt[s]; i++){
        int w = G[s][i].to;
        if(used[w]) continue;
        vector<int> tds;
        enumerate_paths(w, s, G[s][i].dist, tds);
        ans -= count_pairs(tds);
        ds.insert(ds.end(), tds.begin(), tds.end());
    }
    ans += count_pairs(ds);
    used[s] = 0;
}

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int a, b, d; char c;
        scanf("%d %d %d %c", &a, &b, &d, &c);
        a--; b--;
        G[a][cnt[a]++] = edge(b,d);
        G[b][cnt[b]++] = edge(a,d);
    }
    scanf("%d", &K);
    solve_sub(0);
    printf("%d\n", ans);
    return 0;
}
