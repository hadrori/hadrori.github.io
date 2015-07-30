#include <algorithm>
#include <iostream>
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

array gauss_jordan(matrix &A, array &b){
    int n = b.size();
    matrix B(n,array(n+1));
    for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++) B[i][j] = A[i][j];
    for(int i = 0; i < n; i++) B[i][n] = b[i];
    for(int i = 0; i < n; i++){
	int pivot = i;
	for(int j = i; j < n; j++){
	    if(abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
	}
	swap(B[i],B[pivot]);
	if(abs(B[i][i]) < EPS){
	    array x;
	    return x;
	}

	for(int j = i + 1; j <= n; j++) B[i][j] /= B[i][i];
	for(int j = 0; j < n; j++){
	    if(i!=j){
		for(int k = i + 1; k <= n; k++) B[j][k] -= B[j][i]*B[i][k];
	    }
	}
    }
    array x(n);
    for(int i = 0; i < n; i++) x[i] = B[i][n];
    return x;
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
    return gauss(A,b);
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
