#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)

struct node{ int a, b, p, c;};
int N;
node dat[1000010];

void update(int v){
    if(v == 1) return;
    int p = dat[v].p, &a = dat[p].a, &b = dat[p].b;
    if(a != v and b != v and dat[b].c < dat[v].c) b = v;
    if(dat[a].c < dat[b].c) swap(a,b);
    
    int tmp = dat[p].c;
    dat[p].c = max(dat[a].c+(p==1), dat[b].c+1);
    if(dat[p].c == tmp) return;
    update(p);
}

void solve(){
    dat[0] = (node){0,0,0,-1};
    repi(i,2,N+2){
        cin >> dat[i].p;
        update(i);
        printf("%d ", dat[1].c);
    }
}

int main(){
    cin >> N;
    solve();
    return 0;
}
