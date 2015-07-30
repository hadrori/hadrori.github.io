#include <bits/stdc++.h>
using namespace std;

struct frac
{
        long long num, den;
        frac(){}
        frac(long long a) : num(a) { den = 1;}
        frac(long long a, long long b) : num(a), den(b) { normalize();}
        void normalize()
        {
                if(num == 0) {
                        den = 1;
                        return;
                }
                if(den < 0) {
                        num *= -1;
                        den *= -1;
                }
                long long t = __gcd(abs(num),den);
                num /= t; den /= t;
        }
        frac operator*=(const frac &f)
        {
                long long t = __gcd(den,abs(f.num)), u = __gcd(f.den,abs(num));
                num = num/u*f.num/t;
                den = den/t*f.den/u;
                return *this;
        }
        frac operator*(const frac &f) const { return frac(*this) *= f;}
        frac operator/=(const frac &f){ return frac(*this)*=frac(f.den,f.num);}
        frac operator/(const frac &f) const { return frac(*this)/=f;}
        frac operator+=(const frac &f){
                long long t = __gcd(den,f.den);
                num = f.den/t*num+den/t*f.num;
                den = den/t*f.den;
                normalize();
                return *this;
        }
        frac operator+(const frac &f) const { return frac(*this)+=f;}
        frac operator-=(const frac &f){
                long long t = __gcd(den,f.den);
                num = f.den/t*num-den/t*f.num;
                den = den/t*f.den;
                normalize();
                return *this;
        }
        frac operator-(const frac &f) const { return frac(*this)-=f;}
        bool operator<(const frac &f) const { return num*f.den < den*f.num;}
        bool operator>(const frac &f) const { return num*f.den > den*f.num;}
        bool operator<=(const frac &f) const { return !(num*f.den > den*f.num);}
        bool operator>=(const frac &f) const { return !(num*f.den < den*f.num);}
        bool operator==(const frac &f) const { return num*f.den == den*f.num;}
};
ostream &operator<<(ostream &os, const frac &f) {
        os<<f.num<<"/"<<f.den;
        return os;
}
const string hx = "0123456789abcdef";

int n, cur;
string b;

inline int next()
{
        cur++;
        return (hx.find(b[cur/4])>>(3-cur%4)&1)? 1: -1;
}

frac solve()
{
        cur = -1;
        int pb;
        frac a(0), h(0), a1, h1;
        for (;;) {
                const int b = next();
                const frac e = (frac(6*n)-a*9-h)/frac(9+b);
                if(frac(0) <= e and e < frac(1)) {
                        a1 = a+e;
                        h1 = h+e*b;
                        cur--;
                        break;
                }
                h += b; a += 1;
        }
        frac ret(-1);
        for (;a < 2*n; a+=1) {
                const int b = next();
                const frac e = (frac(12*n)-(a-a1)*9+h-h1)/(9-b);
                if(frac(0) <= e and e < frac(1)) return ((a1+a+e)*3+h1+h+e*b)/4;
                h = h+b;
        }
        return ((a1+a)*3+h1)/4;
}

int main()
{
        int t; cin >> t;
        while(t--) {
                cin >> n >> b;
                cout << solve() << endl;
        }
        return 0;
}
