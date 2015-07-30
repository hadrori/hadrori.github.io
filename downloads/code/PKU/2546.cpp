#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>

using namespace std;

typedef complex<double> point;

const double eps = 1e-8;
const double pi = acos(-1.0);

struct circle{
    point p; double r;
    
    circle(){}
    circle(double x, double y, double r):r(r){ p = point(x, y);}

    double area(){ return r * r * pi;}
    double area(double th){ return r * r * th / 2;}
    double intersect_area(circle &a){
        double ret = 0.0;
        double dist = abs(p - a.p);
        if(dist + eps > r + a.r) return 0.0;
        if(dist + a.r < r + eps) return a.area();
        if(dist + r < a.r + eps) return area();
        double th1 = acos((dist*dist+r*r-a.r*a.r)/(2*dist*r))*2;
        double th2 = acos((dist*dist-r*r+a.r*a.r)/(2*dist*a.r))*2;
        
        ret = area(th1) + a.area(th2) - r*r*sin(th1)/2 - a.r*a.r*sin(th2)/2;
        return ret;
    }
};

circle c[2];

int main(){
    for(int i = 0; i < 2; i++){
        double x, y, r;
        scanf("%lf%lf%lf", &x, &y, &r);
        c[i] = circle(x, y, r);
    }
    printf("%.3f\n", c[0].intersect_area(c[1]));
    return 0;
}
