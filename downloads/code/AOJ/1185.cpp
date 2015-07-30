#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define pb push_back

typedef vector<int> vi;

struct Line{
    bool tate;
    int sx, sy, tx, ty;
    Line(int sx, int sy, int tx, int ty, bool tate):
	sx(sx),sy(sy),tx(tx),ty(ty),tate(tate){}
};

int h, w;
vector<vi> choco;
vector<Line> lines;

const int MAX_V = 1000000;
int  V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v){
    used[v] = true;
    for(int i = 0; i < G[v].size(); i++){
	int u = G[v][i], w = match[u];
	if(w < 0 || !used[w] && dfs(w)){
	    match[v] = u;
	    match[u] = v;
	    return true;
	}
    }
    return false;
}

int bipartie_matching(){
    int res = 0;
    memset(match, -1, sizeof(match));
    for(int v = 0; v < V; v++){
	if(match[v] < 0){
	    memset(used, 0, sizeof(used));
	    if(dfs(v)){
		res++;
	    }
	}
    }
    return res;
}

void make_line(){
    rep(i,h-1){
	rep(j,w-1){
	    //yoko
	    if((!choco[i][j] && choco[i+1][j] && choco[i][j+1] && choco[i+1][j+1]) ||
	       (choco[i][j] && !choco[i+1][j] && choco[i][j+1] && choco[i+1][j+1])){
		repi(x,j,w-1){
		    if((choco[i][x] && choco[i+1][x] && !choco[i][x+1] && choco[i+1][x+1]) ||
				 (choco[i][x] && choco[i+1][x] && choco[i][x+1] && !choco[i+1][x+1])){
			lines.pb(Line(j,i,x,i,0));
			break;
		    }
		    if(choco[i][x] && choco[i+1][x] && !choco[i][x+1] && !choco[i+1][x+1]) break;
		}
	    }
	    //tate
	    if((!choco[i][j] && choco[i+1][j] && choco[i][j+1] && choco[i+1][j+1]) ||
	       (choco[i][j] && choco[i+1][j] && !choco[i][j+1] && choco[i+1][j+1])){
		repi(y,i,h-1){
		    if((choco[y][j] && !choco[y+1][j] && choco[y][j+1] && choco[y+1][j+1]) ||
				 (choco[y][j] && choco[y+1][j] && choco[y][j+1] && !choco[y+1][j+1])){
			lines.pb(Line(j,i,j,y,1));
			break;
		    }
		    if(choco[y][j] && !choco[y+1][j] && choco[y][j+1] && !choco[y+1][j+1]) break;
		}
	    }
	}
    }
}

void init(){
    choco.clear();
    choco.resize(h,vi(w));
    rep(i,MAX_V) G[i].clear();
    lines.clear();
}

bool crossline(Line l1, Line l2){
    if(l1.tate == l2.tate) return false;

    if(l2.tate) swap(l1,l2);
    if((l1.sy <= l2.sy && l1.ty >= l2.sy) &&
       (l2.sx <= l1.sx && l2.tx >= l1.sx)) return true;
    return false;
}

int corner(){
    int ret = 0;
    rep(i,h-1)rep(j,w-1){
	if((!choco[i][j] && choco[i+1][j] && choco[i][j+1] && choco[i+1][j+1]) ||
	   (choco[i][j] && !choco[i+1][j] && choco[i][j+1] && choco[i+1][j+1]) ||
	   (choco[i][j] && choco[i+1][j] && !choco[i][j+1] && choco[i+1][j+1]) ||
	   (choco[i][j] && choco[i+1][j] && choco[i][j+1] && !choco[i+1][j+1])) ret++;
    }
    return ret;
}

int main(){
    while(cin >> h >> w, h || w){
	init();
	rep(i,h)rep(j,w){
	    char c;
	    cin >> c;
	    if(c == '#') choco[i][j] = 1;
	    else choco[i][j] = 0;
	}
	make_line();
	rep(i,lines.size())repi(j,i+1,lines.size()){
	    if(crossline(lines[i],lines[j])) add_edge(i,j);
	}
	V = lines.size();
	cout << corner() - lines.size() + bipartie_matching() + 1 << endl;
    }
    return 0;
}
