#include <iostream>
#include <map>
#include <vector>

#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int main(){
    
    int n, m, a;
    
    while( cin >> n >> m >> a, n || m || a){
        vector< map< int,int, greater<int> > > amida(1000);
        
        int mh = 0;
        rep(i, 0, m){
            int h, p, q;
            cin >> h >> p >> q;
            if( h > mh){
                mh = h;
            }
            
            amida[p].insert(make_pair(h,q));
            amida[q].insert(make_pair(h,p));
            
        }
        
        while( mh > 0){
            if( amida[a].find(mh) != amida[a].end()){
                a = amida[a][mh];
            }
            mh--;
        }
        cout << a << endl;
    }
}