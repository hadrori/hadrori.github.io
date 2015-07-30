#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vec;
typedef vector<vec> mat;

#define INF 100000000

int main(){
    int n, k;
    while(cin>>n>>k,n||k){
        mat dist(n+1,vec(n+1,INF));
        while(k--){
            int t;
            cin >> t;
            if(t){
                int c[2], e;
                cin >> c[0] >> c[1] >> e;
                dist[c[0]][c[1]] = min(dist[c[0]][c[1]],e);
                dist[c[1]][c[0]] = min(dist[c[1]][c[0]],e);
                rep(k,2)rep(i,n+1)rep(j,n+1){
                    dist[i][j] = min(dist[i][j],dist[i][c[k]]+dist[c[k]][j]);
                }
            }else{
                int a, b;
                cin >> a >> b;
                cout << ((dist[a][b]==INF)? -1:dist[a][b]) << endl;
            }
        }
    }
}
