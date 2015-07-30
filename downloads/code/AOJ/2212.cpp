#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

struct PMA{
    PMA* next[256];     //失敗時に0を利用
    vector<int> matched;//sort済みを仮定
    PMA(){memset(next, 0, sizeof(next));}
    ~PMA(){for(int i = 0; i < 256; i++) if(next[i]) delete next[i];}
};

vector<int> set_union(const vector<int> &a,const vector<int> &b){
    vector<int> res;
    set_union(all(a), all(b), back_inserter(res));
    return res;
}

//パターンマッチングオートマトンの生成,生成元パターンをpattern, 個数をcountに代入して用いる
PMA *buildPMA(vector<string> pattern){
    PMA *root = new PMA, *now;
    root -> next[0] = root;
    //Phase1.Trie木の生成
    for(int i = 0; i < pattern.size(); i++){
        now = root;
        for(int j = 0; j < pattern[i].size(); j++){
            if(now -> next[(int)pattern[i][j]] == 0)
                now -> next[(int)pattern[i][j]] = new PMA;
            now = now -> next[(int)pattern[i][j]];
        }
        now -> matched.push_back(i);
    }
    queue<PMA*> que;
    //Phase2.BFSによるオートマトンの生成
    for(int i = 1; i < 256; i++){
        if(!root -> next[i]) root -> next[i] = root; //使われていない部分のnextをrootに
        else {
            root -> next[i] -> next[0] = root;      //失敗時はルートに戻る
            que.push(root -> next[i]);
        }
    }
    while(!que.empty()){
        now = que.front(); que.pop();
        for(int i = 1; i < 256; i++){
            if(now -> next[i]){
                PMA *next = now -> next[0];
                while(!next -> next[i]) next = next -> next[0];
                now -> next[i] -> next[0] = next -> next[i];
                now -> next[i] -> matched = set_union(now -> next[i] -> matched,
                                                      next -> next[i] -> matched);
                que.push(now -> next[i]);
            }
        }
    }
    return root;
}

void match(PMA* &pma, const string s, vector<int> &res){
    for(int i = 0; i < s.size(); i++){
        int c = s[i];
        while(!pma -> next[c])
            pma = pma -> next[0];
        pma = pma -> next[c];
        for(int j = 0; j < pma -> matched.size(); j++)
            res[pma -> matched[j]] = true;
    }
}

int h, w, n;
vector<string> table;
pii s, g;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
string d[] = {"L","R","U","D"};

struct S{
    pii p;
    int turn;
    PMA *pma;
    string str; //debug用経路
    S(pii p, int turn, PMA *pma, string str):p(p),turn(turn),pma(pma),str(str){}
};

bool inrange(pii p){
    int x = p.first, y = p.second;
    return x >= 0 && x < w && y >= 0 && y < h;
}

int main(){
    while(cin >> h >> w, h || w){
        table.resize(h);
        rep(i,h) cin >> table[i];
        rep(i,h)rep(j,w)
            if(table[i][j] == 'S') s = pii(j,i);
            else if(table[i][j] == 'G') g = pii(j,i);
        cin >> n;
        vector<string> pattern(n);
        rep(i,n) cin >> pattern[i];
        PMA* root = buildPMA(pattern);
	
        int ans = -1;
        queue<S> que;
        que.push(S(s,0,root,""));
        set<PMA*> visited[64][64];
        while(!que.empty()){
            S t = que.front(); que.pop();
            rep(i,t.pma->matched.size()) cout << t.pma->matched[i] << endl;
            if(t.p == g){
                ans = t.turn;
                break;
            }
            rep(i,4){
                pii np = pii(t.p.first+dx[i],t.p.second+dy[i]);
                if(inrange(np) && table[np.second][np.first] != '#'){
                    PMA* next = t.pma;
                    vi res(n);
                    match(next,d[i],res);
                    bool ok = false;
                    rep(j,n) ok |= res[j];
                    if(!ok && visited[np.first][np.second].find(next) ==
                       visited[np.first][np.second].end()){
                        visited[np.first][np.second].insert(next);
                        que.push(S(np,t.turn+1,next,t.str+d[i]));
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
