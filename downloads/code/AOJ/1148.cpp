#include <iostream>
#include <vector>
#include <stack>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

struct L{
    int time, man, io;
    L(int t, int m, int s):time(t),man(m),io(s){}
};

int main(){
    int r, q, t, n, m, s;
    while(cin >> n >> m, n || m){
        vector<L> lg;
        cin >> r;
        rep(i,r){
            cin >> t >> n >> m >> s;
            lg.push_back(L(t,m,s));
        }
        cin >> q;
        rep(i,q){
            int ts, te;
            cin >> ts >> te >> m;
            int sum = 0;
            int login = 0;
            rep(j,r-1){
                if((lg[j].man == m) && lg[j].io) login++;
                
                if(login > 0){
                    int tmp = min(lg[j+1].time,te) - max(lg[j].time,ts);
                    if(tmp > 0) sum += tmp;
                }
                
                if((lg[j+1].man == m) && !lg[j+1].io) login--;
            }
            cout << sum << endl;
        }
    }
}