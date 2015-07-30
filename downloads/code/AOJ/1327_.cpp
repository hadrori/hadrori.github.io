#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 1e8
#define EPS 1e-8
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef int number;
typedef vector<number> array;
typedef vector<array> matrix;

int N, M, A, B, C, T;

//n*nの単位行列
matrix identity(int n){
    matrix A(n, array(n));
    for(int i = 0; i < n; i++) A[i][i] = 1;
    return A;
}

//行列の積
matrix mul(const matrix &A, const matrix &B) {
    matrix C(A.size(), array(B[0].size()));
    for (int i = 0; i < C.size(); ++i)
        for (int j = 0; j < C[i].size(); ++j)
            for (int k = 0; k < A[i].size(); ++k){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= M;
            }
    return C;
}

//累乗 O( n^3 log e )
matrix pow(const matrix &A, int e) {
    return e == 0 ? identity(A.size())  :
        e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}

int main(){


    while(cin>>N>>M>>A>>B>>C>>T,N||M||A||B||C||T){
        matrix s(1, array(N));
        rep(i,N) cin >> s[0][i];
        matrix t(N, array(N));
        rep(i,N){
            if(i > 0) t[i][i-1] = C;
            t[i][i] = B;
            if(i<N-1) t[i][i+1] = A;
        }
        s = mul(s,pow(t,T));
        rep(i,N) cout << s[0][i] << (i==N-1? '\n': ' ');
    }
}
