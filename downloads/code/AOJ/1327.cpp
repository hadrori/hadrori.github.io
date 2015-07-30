#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define INF 1e9
using namespace std;
typedef int number;
typedef number* array;
typedef array* matrix;

int N, M, A, B, C, T;
matrix new_matrix(int n, int m){
    matrix A = new array[n];
    for(int i = 0; i < n; i++){
        A[i] = new number[m];
        for(int j = 0; j < m; j++) A[i][j] = 0;
    }
    return A;
}

void delete_matrix(matrix A, int n, int m){
    for(int i = 0; i < n; i++) delete[] A[i];
    delete[] A;
}

matrix identity(int n){
    matrix A = new_matrix(n,n);
    for(int i = 0; i < n; i++) A[i][i] = 1;
    return A;
}

matrix mul_matrix(matrix A, matrix B, int p, int n, int q){
    matrix C = new_matrix(p,q);
    for(int i = 0; i < p; i++){
        for(int j = 0; j < q; j++){
            C[i][j] = 0;
            for(int k = 0; k < n; k++){
                C[i][j] += A[i][k]*B[k][j];
                C[i][j] %= M;
            }
        }
    }
    return C;
}

matrix pow_matrix(matrix A, int n, int e){
    return e==0? identity(n):
        e%2==0? pow_matrix(mul_matrix(A,A,n,n,n),n,e/2):
        mul_matrix(A,pow_matrix(A,n,e-1),n,n,n);
}

int main(){

    while(cin>>N>>M>>A>>B>>C>>T,N||M||A||B||C||T){
        matrix s = new_matrix(1,N);
        rep(i,N) cin >> s[0][i];
        matrix t = new_matrix(N,N);
        rep(i,N){
            if(i > 0) t[i][i-1] = C;
            t[i][i] = B;
            if(i<N-1) t[i][i+1] = A;
        }
        s = mul_matrix(s,pow_matrix(t,N,T),1,N,N);
        rep(i,N) cout << s[0][i] << (i==N-1? '\n': ' ');
    }
}
