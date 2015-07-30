#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod = 1000000000;
void add(ll &a, ll b) { a = (a+b+mod)%mod;}
string tos(ll x)
{
        stringstream ss;
        ss << x;
        string s; ss >> s;
        while(s.size() < 9) s = "0"+s;
        return s;
}

vec mul(mat &a, vec &b)
{
        const int p = a.size(), q = b.size();
        vec ret(p,0);
        for (int i = 0; i < p; i++)
                for (int j = 0; j < q; j++)
                        add(ret[i], a[i][j]*b[j]%mod);
        return ret;
}

mat mul(mat &a, mat &b)
{
        const int m = a.size();
        mat c(m,vec(m,0));
        for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                        for (int k = 0; k < m; k++)
                                add(c[i][j], a[i][k]*b[k][j]%mod);
        return c;
}

ull n;
int k;
ll c[16][16];

void pascal()
{
        c[0][0] = 1;
        for (int i = 1; i <= k; i++) {
                c[i][0] = c[i][i] = 1;
                for (int j = 1; j < i; j++)
                        add(c[i][j], c[i-1][j-1]+c[i-1][j]);
        }
}

mat pow(mat &a, ull e)
{
        const int m = a.size();
        mat b(m,vec(m,0));
        for (int i = 0; i < m; i++) b[i][i] = 1;
        for(; e; a=mul(a,a), e>>=1) if(e&1) b = mul(b,a);
        return b;
}

void gen(int kk, mat &a, vec &b)
{
        const int m = kk+2;
        b.assign(m, 1<<kk);
        a.assign(m,vec(m,0));
        a[0][0] = a[0][1] = 1;
        for (int i = 1; i < m; i++) {
                int kkk = kk-i+1;
                for (int j = 0; j <= kkk; j++) a[i][j+1] = c[kkk][j];
        }
}

string solve()
{
        pascal();
        ll ans = 0, sig = k%2? -1: 1;
        mat a; vec b;
        for (int j = 0; j <= k; j++) {
                gen(j, a, b);
                a = pow(a,n);
                b = mul(a,b);
                add(ans, sig*b[0]*c[k][j]);
                sig *= -1;
        }
        return tos(ans);
}

void input()
{
        cin >> n >> k;
}

int main()
{
        input();
        cout << solve() << endl;
        return 0;
}
