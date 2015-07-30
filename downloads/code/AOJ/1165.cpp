#include <iostream>
#include <vector>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main(){
    int n;
    while(cin >> n, n){
        vector<pair<int, int> > art(n);
        art[0] = make_pair(0,0);
        repi(i, 1, n){
            int s, d;
            cin >> s >> d;
            art[i] = make_pair(art[s].first+dx[d], art[s].second+dy[d]);
        }
        int left = 0, right = 0, upper = 0, lower = 0;
        rep(i,n){
            left = min(left, art[i].first);
            right = max(right, art[i].first);
            upper = max(upper, art[i].second);
            lower = min(lower, art[i].second);
        }
        
        cout << right - left + 1 << ' ' << upper - lower + 1 << endl;
    }
}