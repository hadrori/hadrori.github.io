namespace D2
{
/*
  depends on
  point
*/
struct line
{
        point a, b;
        line(){}
        line(point a, point b):a(a),b(b){}

        point vec() const { return b-a;}
        double abs() const { return vec().abs();}
        double norm() const { return vec().norm();}
        point proj(const point &p) const { return a+vec().proj(p-a);}
        point refl(const point &p) const { return proj(p)*2-p;}
};
std::ostream &operator<<(std::ostream &os, const line &l) { os << l.a << " - " << l.b; return os; }

bool ill(const line &l, const line &m){ return std::abs(l.vec().det(m.vec())) > eps;}
bool ils(const line &l, const line &s){ return ccw(l.a,l.b,s.a)*ccw(l.a,l.b,s.b)<=0;}
bool isl(const line &s, const line &l){ return ils(l,s);}
bool iss(const line &s, const line &t){ return ils(s,t) and ils(t,s);}
point cll(const line &l, const line &m){ return l.a+l.vec()*(m.vec().det(m.a-l.a)/m.vec().det(l.vec()));}
double dlp(const line &l, const point &p){ return (l.proj(p)-p).abs();}
double dpl(const point &p, const line &l){ return dlp(l,p);}
double dll(const line &l, const line &m){ return ill(l,m) ? 0.0 : dlp(l,m.a);}
double dps(const point &p, const line &s){ return ccw(s.a,s.b,s.proj(p)) ? std::min((s.a-p).abs(), (s.b-p).abs()) : (s.proj(p)-p).abs();}
double dsp(const line &s, const point &p){ return dps(p,s);}
double dss(const line &s, const line &m){ return iss(s,m)? 0.0 : std::min(std::min(dps(m.a,s),dps(m.b,s)), std::min(dps(s.a,m),dps(s.b,m)));}

}
