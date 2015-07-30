#include <bits/stdc++.h>

#define rep(i,a) for(int i = 0; i < (a); i++)

using namespace std;

int fact2[2],fact5[5];

int mod_fact(int n,int p,int &e){
    e=0;
    if(n==0)return 1;
    int res=mod_fact(n/p,p,e);
    e+=n/p;
    if(n/p%2!=0)return res*(p-(p==2?fact2[n%p]:fact5[n%p]))%p;
    return res*(p==2?fact2[n%p]:fact5[n%p])%p;
}
int extgcd(int a,int b,int &x,int &y){
    int d=a;
    if(b!=0){
        d=extgcd(b,a%b,y,x);
        y-=a/b*x;
    }
    else x=1, y=0;
    return d;
}
int mod_inv(int n,int m){
    int x,y;
    extgcd(n,m,x,y);
    return (x%m+m)%m;
}
int mod_pow(int n,int m,int p){
    int res=1;
    for(;m;m/=2){
        if(m&1)res=res*n%p;
        n=n*n%p;
    }
    return res;
}
int main(){
    fact2[0]=fact2[1]=1;
    fact5[0]=1;
    rep(i,4)fact5[i+1]=fact5[i]*(i+1)%5;

    int n,m;
    while(~scanf("%d%d",&n,&m)){
        m=n-m;
        int a5,e5,a2,e2;
        int b5,f5,b2,f2;
        a5=mod_fact(n,5,e5);
        b5=mod_fact(m,5,f5);
        a2=mod_fact(n,2,e2);
        b2=mod_fact(m,2,f2);

        e5-=f5;
        e2-=f2;
        int x=min(e5,e2),mod5,mod2;
        if(e5-x>0)mod5=0;
        else mod5=a5*mod_inv(b5,5)*mod_inv(mod_pow(2,x,5),5)%5;
        if(e2-x>0)mod2=0;
        else mod2=a2*mod_inv(b2,2)%2;

        rep(i,10)if(i%2==mod2&&i%5==mod5){
            printf("%d\n",i);
        }
    }
    return 0;
}
