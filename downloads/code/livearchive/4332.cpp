#include <bits/stdc++.h>
using namespace std;

const int mod = 10007;

typedef vector<int> arr;
typedef vector<arr> mat;

mat identity(int n)
{
        mat ret(n,arr(n,0));
        for (int i = 0; i < n; i++) ret[i][i] = 1;
        return ret;
}

arr mul(const mat &A, const arr &x)
{
        arr y(A.size());
        for(int i = 0; i < (int)A.size(); ++i)
                for(int j = 0; j < (int)A[0].size(); ++j)
                        y[i] = (y[i]+A[i][j]*x[j])%mod;
        return y;
}

mat mul(const mat &A, const mat &B)
{
        mat C(A.size(), arr(B[0].size()));
        for(int i = 0; i < (int)C.size(); ++i)
                for(int j = 0; j < (int)C[i].size(); ++j)
                        for(int k = 0; k < (int)A[i].size(); ++k)
                                C[i][j] = (C[i][j]+A[i][k]*B[k][j])%mod;
        return C;
}

mat pow(mat A, int e)
{
        mat ret = identity(A.size());
        for (; e > 0; A=mul(A,A), e>>=1) if(e&1) ret = mul(ret, A);
        return ret;
}

int solve(int x)
{
        if(!x) return 1;
        mat A(4,arr(4));
        A[0][0] = A[0][1] = A[0][2] = A[0][3] = 2;
        A[1][0] = 1;
        A[2][2] = A[2][3] = 2;
        A[3][2] = 1;
        A = pow(A,x-1);
        arr B(4);
        B[0] = 4; B[1] = 1; B[2] = 2; B[3] = 1;
        B = mul(A,B);
        return B[0];
}

int main()
{
        int x;
        while(cin >> x, ~x) cout << solve(x) << endl;
        return 0;
}
