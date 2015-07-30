#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<pair<int,int> > dia;
        rep(i,n){
            int sh,sm,ss, eh,em,es;
            scanf("%d:%d:%d %d:%d:%d",&sh,&sm,&ss,&eh,&em,&es);
            dia.push_back(make_pair(eh*60*60+em*60+es,sh*60*60+sm*60+ss));
        }
        sort(dia.begin(),dia.end());
        int cnt = 0;
        rep(i,n){
            int tmp = 0;
            repi(j,i,n){
                if(dia[i].first > dia[j].second) tmp++;
            }
            cnt = max(tmp,cnt);
        }
        cout << cnt << endl;
    }
}