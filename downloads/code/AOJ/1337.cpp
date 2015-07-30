#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>

#define pb push_back
#define mp make_pair

using namespace std;

#define int long long

typedef pair<int,int> pii;

int N;
int l[64], t[64], r[64], b[64];
int table[256][256];

inline bool in(int i, int j){ return i >= 0 && j >= 0 && i < 256 && j < 256;}
const int di[] = {-1,1,0,0};
const int dj[] = {0,0,-1,1};

void dfs(int i, int j){
    int t = table[i][j];
    table[i][j] = -1;
    for(int d = 0; d < 4; d++){
        int ni = i + di[d], nj = j + dj[d];
        if(in(ni,nj) && table[ni][nj] == t)
            dfs(ni, nj);
    }
}

signed main(){
    while(cin >> N, N){
        vector<int> tmp;
        map<int,int> zip;
        for(int i = 0; i < N; i++){
            cin >> l[i] >> t[i] >> r[i] >> b[i];
            tmp.pb(l[i]);
            tmp.pb(t[i]);
            tmp.pb(r[i]);
            tmp.pb(b[i]);
        }
        sort(tmp.begin(), tmp.end());
        for(int i = 1; i <= tmp.size(); i++)
            zip[tmp[i-1]] = i;
        memset(table, 0, sizeof(table));
        for(int i = 0; i < N; i++){
            int mask = 1LL << i;
            int left = zip[l[i]];
            int right = zip[r[i]];
            int top = zip[t[i]];
            int bottom = zip[b[i]];
            for(int x = left; x < right; x++)
                for(int y = bottom; y < top; y++)
                    table[x][y] |= mask;
        }
        /*
        for(int i = 0; i < 16; i++){
            for(int j = 0; j < 16; j++)
                cout << table[i][j] << ' ';
            cout << endl;
        }
        */      
        int ans = 0;
        for(int i = 0; i < 256; i++)
            for(int j = 0; j < 256; j++)
                if(table[i][j] != -1){
                    ans++;
                    dfs(i, j);
                }

        
        cout << ans << endl;
    }
}
