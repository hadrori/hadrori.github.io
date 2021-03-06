#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define pb push_back
#define EPS 1e-5
using namespace std;
typedef double number;
typedef vector<number> array;
typedef vector<array> matrix;

vector<double> v;

#define MAKEROT(x,y,c,s) {double r = sqrt(x*x+y*y); c = x/r; s = y/r;}
#define ROT(x,y,c,s) {double u = c*x+s*y; double v = -s*x+c*y; x = u; y = v;}
array givens(matrix A, array b){
    int n = b.size();
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            double c, s;
            MAKEROT(A[i][i], A[j][i], c, s);
            ROT(b[i], b[j], c, s);
            for (int k = i; k < n; k++)
                ROT(A[i][k],A[j][k],c,s);
        }
    }
    for (int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++)
            b[i] = b[i] - A[i][j] * b[j];
        b[i] = b[i] / A[i][i];
    }
    return b;
}

int d;

array solve_eq(int m, int n){
    matrix A(d+1,array(d+1));
    array b(d+1);
    int cnt = 0;
    rep(i,d+3)if(i != m && i != n){
        b[cnt] = v[i];
        rep(j,d+1) A[cnt][j] = pow(1.0*i,1.0*j);
        cnt++;
    }
    return givens(A,b);
}

int main(){
    while(cin >> d, d){
        v.resize(d+3);
        int ans = -1;
        rep(i,d+3) cin >> v[i];
        rep(i,d+3){
            repi(j,i+1,d+3){
                array b = solve_eq(i,j);
                double e = 0, f = 0;
                rep(k,d+1) e += pow(1.0*i,1.0*k) * b[k];
                rep(k,d+1) f += pow(1.0*j,1.0*k) * b[k];
                if(abs(e-v[i]) > EPS && abs(f-v[j]) < EPS){
                    ans = i;
                    break;
                }
                if(abs(e-v[i]) < EPS && abs(f-v[j]) > EPS){
                    ans = j;
                    break;
                }
            }
            if(ans >= 0) break;
        }
        cout << ans << endl;
    }
    return 0;
}
