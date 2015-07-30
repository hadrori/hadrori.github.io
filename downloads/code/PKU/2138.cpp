#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N, s;
string st, ans;
string dict[1024];
vector<int> edge[1024];
bool visited[1024];

bool sim(int a, int b){
    if(dict[b].size() - dict[a].size() != 1) return 0;
    int match = 0;
    int j = 0;
    for(int i = 0; i < dict[b].size(); i++)
        if(dict[b][i] == dict[a][j]) j++;

    if(dict[a].size() == j) return 1;
    return 0;
}

void dfs(int id){
    if(visited[id]) return;
    visited[id] = 1;
    if(ans.size() < dict[id].size()) ans = dict[id];
    for(int i = 0; i < edge[id].size(); i++)
        dfs(edge[id][i]);
}

int main(){
    cin >> N >> st;
    for(int i = 0; i < N; i++){
        string str; cin >> str;
        dict[i] = str;
        if(str == st) s = i;
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(i != j && sim(i, j))
                edge[i].push_back(j);
    ans = st;
    dfs(s);
    cout << ans << endl;
    return 0;
}
