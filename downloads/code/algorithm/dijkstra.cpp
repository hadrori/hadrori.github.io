struct node
{
        int v, d;
        node(int v, int d):v(v),d(d){}
        bool operator<(const node &n)const{ return d > n.d;}
};
struct edge{int to, d;};
int V;
vector<edge> G[MAX];
int dist[MAX]; // shortest distance

void dijkstra(int s)
{
        memset(dist, -1, sizeof(dist));
        priority_queue<node> que;
        que.push(node(s, 0));
        while(!que.empty()){
                int v = que.top().v, d = que.top().d;
                que.pop();
                if(dist[v] >= 0 and dist[v] <= d) continue;
                dist[v] = d;
                for(int i = 0; i < G[v].size(); i++)
                        que.push(node(G[v][i].to, d+G[v][i].d));
        }
}
