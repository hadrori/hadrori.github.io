vector<int> edge[128];
int col[128];
class Family {
public:
    int N;
    string pos = "Possible";
    string imp = "Impossible";

    bool dfs(int p, int g){
        if(col[p] >= 0) return col[p] == g;
        col[p] = g;
        rep(i, edge[p].size())
            if(!dfs(edge[p][i], 1-g)) return 0;
        return 1;
    }
    
    string isFamily( vector <int> p1, vector <int> p2 ) {
        N = p1.size();
        rep(i,N) edge[i].clear();
        memset(col, -1, sizeof(col));
        rep(i,N){
            if(p1[i] >= 0){
                edge[p2[i]].pb(p1[i]);
                edge[p1[i]].pb(p2[i]);                
            }
        }
        rep(i,N)if(col[i] < 0)
            if(!dfs(i, 0)) return imp;
        return pos;
    }
};
