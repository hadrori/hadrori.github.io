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
        mint pow(int k) {
                mint ret = 1, y = x;
                for(;k>0;y*=y,k>>=1) if(k&1) ret = ret*y;
                return ret;
        }
};
ostream &operator<<(ostream& os, const mint &m){ os << m.x; return os;}

mint inv[MAX];
void gen_inv(int n)
{
        inv[1] = 1;
        for(int i = 2; i < n; ++i) mod_inv[i] = inv[mod%i]*mint(mod-mod/i);
}

