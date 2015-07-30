struct edge
{
        int from, to, cst;
        edge(){}
        edge(int from, int to, int cst):from(from),to(to),cst(cst){}
        bool operator<(const edge &e)const{return cst < e.cst;}
};

// Eが連結ならTに最小全域木が入る
int kruskal(vector<edge> &E, vector<edge> &T)
{
        sort(E.begin(), E.end());
        T.clear();
        union_find uf(n) ;
        int w = 0;
        for(int i = 0; i < E.size(); i++){
                edge &e = E[i];
                if(uf.same(e.from, e.to)) continue;
                uf.unite(e.from, e.to);
                w += e.cst;
                T.push_back(e);
        }
        return w;
}
