typedef pair<int,int> pii; // (cst, to)
vector<pii> G[MAX];
bool used[MAX];

int prim() {
    priority_queue<pii, vector<pii>, greater<pii> > que;
    memset(used, 0, sizeof(used));
    que.push(pii(0,0));
    int ret = 0;
    while(!que.empty()) {
        int cst = que.top().first, v = que.top().second;
        que.pop();
        if(used[v]) continue;
        used[v] = 1;
        ret += cst;
        for(int i = 0; i < G[v].size(); i++)
            que.push(pii(G[v][i].first, G[v][i].second));
    }
    return ret;
}
