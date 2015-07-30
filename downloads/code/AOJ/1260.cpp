#include <algorithm>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

typedef pair<int,int> pii;
typedef pair<vector<string>,pii> pvspii;

const string dir = "WE";

int N, M;
vector<pii> edge[4][2];
vector<string> lines[2];
map<vector<string>, int> dist[2];

void init(){
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 2; j++)
            edge[i][j].clear();
    for(int i = 0; i < 2; i++){
        lines[i].clear();
        dist[i].clear();
    }
        
}

bool input(){
    cin >> N >> M;
    if(!N) return 0;
    init();
    for(int i = 0; i < M; i++){
        int a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        int bb = dir.find(b);
        int dd = dir.find(d);
        edge[a][bb].push_back(pii(c,dd));
        edge[c][dd].push_back(pii(a,bb));
    }
    for(int j = 0; j < 2; j++)
        for(int i = 0; i < N; i++){
            string str; cin >> str;
            if(str == "-") lines[j].push_back("");
            else lines[j].push_back(str);
        }
    return 1;
}

int solve(){
    queue<pvspii> que;
    que.push(pvspii(lines[0],pii(0,0)));
    que.push(pvspii(lines[1],pii(0,1)));
    dist[0][lines[0]] = 0;
    dist[1][lines[1]] = 0;
    while(!que.empty()){
        vector<string> line = que.front().first;
        int d = que.front().second.first;
        int s = que.front().second.second;
        int ns = (s + 1) % 2;
        que.pop();
        if(dist[ns].count(line) > 0) return d + dist[ns][line];
        if(d == 3) continue;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < line[i].size(); j++){
                string l = line[i].substr(0,j), r = line[i].substr(j);
                if(l.size() > 0){
                    for(int k = 0; k < edge[i][0].size(); k++){
                        vector<string> next = line;
                        next[i] = r;
                        int ndir = edge[i][0][k].second;
                        int nl = edge[i][0][k].first;
                        if(ndir == 1) next[nl] += l;
                        else{
                            string tl = l;
                            reverse(tl.begin(), tl.end());
                            next[nl] = tl + next[nl];
                        }
                        if(dist[s].count(next) == 0) {
                            que.push(pvspii(next,pii(d+1,s)));
                            dist[s][next] = d+1;
                        }
                    }
                }
                if(r.size() > 0){
                    for(int k = 0; k < edge[i][1].size(); k++){
                        vector<string> next = line;
                        next[i] = l;
                        int ndir = edge[i][1][k].second;
                        int nl = edge[i][1][k].first;
                        if(ndir == 0) next[nl] = r + next[nl];
                        else{
                            string tr = r;
                            reverse(tr.begin(), tr.end());
                            next[nl] += tr;
                        }
                        if(dist[s].count(next) == 0){
                            que.push(pvspii(next,pii(d+1,s)));
                            dist[s][next] = d+1;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    while(input()) cout << solve() << endl;
    return 0;
}
