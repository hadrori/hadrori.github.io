#include <iostream>
#include <vector>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

vector<vector<pair<int,int> > > works(410);
vector<int> critical(410);

int n, m;

int saiki(int node){
    if(node == 0) return critical[node] = 0;
    if(critical[node] != 0) return critical[node];
    
    int maxa = 0;
    rep(i,works[node].size()){
        maxa = max(maxa, saiki(works[node][i].first) + works[node][i].second);
    }
    
    return critical[node] = maxa;
}

int main(){
    cin >> n >> m;

    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        works[b].push_back(make_pair(a,c));
    }
    
    saiki(n-1);
    
    cout << critical[n-1] << endl;
    
}