namespace D2 {
/*
  depends on
  point
  (line)
*/

struct circle {
    point o;
    double r;
    circle(){}
    circle(point o, double r) : o(o), r(r) {}
    circle(double r, point o) : o(o), r(r) {}
};
std::ostream &operator<<(std::ostream &os, const circle &c) { os << c.o << " - " << c.r; return os; }

int icc(const circle &c, const circle &d) {
    /*
      1 : intersect
      0 : distinct
      -1: c < d
      -2: c > d

      intersect or contain : true
      distinct             : false
    */
    double od = (c.o-d.o).abs();
    return c.r+d.r<od+eps ? 0 : od+c.r<d.r+eps ? -1 : od+d.r<c.r+eps ? -2 : 1;
}

int icl(const circle &c, const line &l) {
    /*
      number of crosspoint
    */
    double d = (l.proj(c.o)-c.o).norm()-c.r*c.r;
    return d>eps ? 0 : std::abs(d)<eps ? 1 : 2;
}
int ilc(const line &l, const circle &c) { return icl(c,l); }
int ics(const circle &c, const line &s) {
    /*
      0 : distinct
      1 : intersect 1 point
      2 : s is in c
    */
    if (!icl(c, s)) return 0;
    double da = (s.a - c.o).abs();
    double db = (s.b - c.o).abs();
    if ((da < c.r-eps) and (db < c.r-eps)) return 0;
    if ((da < c.r-eps) xor (db < c.r-eps)) return 1;
    return ccw(s.a, s.b, s.proj(c.o)) ? 0 : 2;
}
int isc(const line &s, const circle &c) { return ics(c,s); }

double dcp(const circle &c, const point &p) {
    double d = (c.o-p).abs();
    if(d < c.r+eps) return 0;
    return d-c.r;
}
double dpc(const point &p, const circle &c) { return dcp(c,p); }

double dcl(const circle &c, const line &l) { return std::max(dlp(l,c.o)-c.r,0.); }
double dlc(const line &l, const circle &c) { return dcl(c,l); }
double dcs(const circle &c, const line &s) { return std::max(dps(c.o,s)-c.r,0.); }
double dsc(const line &s, const circle &c) { return dcs(c,s); }

std::pair<point,point> ccl(const circle &c, const line &l) {
    point h = l.proj(c.o), p = sqrt(c.r*c.r-(h-c.o).norm())*(l.b-l.a)/(l.b-l.a).abs();
    return std::pair<point,point>(h-p,h+p);
}
std::pair<point,point> clc(const line &l, const circle &c) { return ccl(c,l); }

std::pair<point,point> ccc(const circle &c1, const circle &c2) {
    if(!icc(c1,c2)) return std::pair<point,point>(c1.o,c2.o);
    double w = (c2.o-c1.o).abs(), th = (c2.o-c1.o).arg();
    double dth = std::acos((c1.r*c1.r+w*w-c2.r*c2.r)/(2.*c1.r*w));
    return std::pair<point,point>(c1.o+D2::polar(c1.r,th-dth),c1.o+D2::polar(c1.r,th+dth));
}

line tangent(const circle &c, const double &th) {
    point h = c.o+D2::polar(c.r,th);
    point p = D2::polar(c.r,th)*D2::point(0,1);
    return line(h-p,h+p);
}

std::vector<line> common_tangent(const circle &c, const circle &d) {
    std::vector<line> ret;
    double dist = (d.o - c.o).abs(), th = (d.o - c.o).arg();
    if (std::abs(c.r - d.r) < dist) { // outer
        double dth = std::acos((c.r - d.r) / dist);
        ret.push_back(tangent(c, th - dth));
        ret.push_back(tangent(c, th + dth));
    }
    if (std::abs(c.r + d.r) < dist) {
        double dth = std::acos((c.r + d.r) / dist);
        ret.push_back(tangent(c, th - dth));
        ret.push_back(tangent(c, th + dth));
    }
    return ret;
}
}
