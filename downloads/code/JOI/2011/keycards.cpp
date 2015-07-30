#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
struct mint
{
        int x;
        mint():x(0){}
        mint(int y){ if((x=y%mod+mod) >= mod) x-= mod;}

        mint &operator+=(const mint &m){ if((x += m.x) >= mod) x-=mod; return *this;}
        mint &operator-=(const mint &m){ if((x += mod-m.x) >= mod) x-=mod; return *this;}
        mint &operator*=(const mint &m){ x = 1LL*x*m.x%mod; return *this;}
        mint &operator/=(const mint &m){ x=(1LL*x*ex(m,mod-2).x)%mod; return *this;}
        mint operator+(const mint &m)const{ return mint(*this) += m;}
        mint operator-(const mint &m)const{ return mint(*this) -= m;}
        mint operator*(const mint &m)const{ return mint(*this) *= m;}
        mint operator/(const mint &m)const{ return mint(*this) /= m;}
        bool operator<(const mint &m)const{ return x < m.x;}
        bool operator>(const mint &m)const{ return x > m.x;}
        bool operator==(const mint &m)const{ return x == m.x;}
        bool operator&&(const mint &m)const{ return x && m.x;}
        bool operator||(const mint &m)const{ return x || m.x;}
        mint inv() { return ex(mint(x),mod-2);}
        mint ex(mint a, long long t){
                if(!t) return 1;
                mint res = ex(a,t/2);
                res *= res;
                return (t&1)?res*a:res;
        }
};
ostream &operator<<(ostream& os, const mint &m){ os << m.x; return os;}

int n, k;
mint fact[1000010], p22[1000010]; // p22[i] : 2^(2^i)

void gen()
{
        fact[0] = 1;
        for (int i = 0; i < n; i++) fact[i+1] = fact[i]*(i+1);
        p22[0] = 2;
        for (int i = 0; i < n; i++) p22[i+1] = p22[i]*p22[i];
}

mint comb(int a, int b)
{
        return fact[a]/fact[b]/fact[a-b];
}

mint g(int m, int i)
{
        return comb(m,i)*p22[m-i];
}

mint solve()
{
        if(n == k) return 1;
        if(n == 1) return 0;
        gen();
        mint ans = 0, p = 1, np = mod-1;
        for (int i = 0; i <= n-k; i++) {
                ans += p*g(n-k,i);
                swap(p,np);
        }
        return comb(n,k)*ans;
}

void input()
{
        cin >> n >> k;
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
