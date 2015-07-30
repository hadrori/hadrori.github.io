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
        bool operator==(const frac &f) const { return num*f.den == den*f.num;}
        double to_double() const { return 1.*num/den;}
        frac abs() const { return frac(abs(f.num),f.den);}
};
ostream &operator<<(ostream &os, const frac &f) {
        os<<f.num<<"/"<<f.den;
        return os;
}
