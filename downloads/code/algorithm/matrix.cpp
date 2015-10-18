typedef double number;
typedef vector<number> arr;
typedef vector<arr> mat;

number dot(const arr &a, const arr &b) {
    number ans = 0;
    for(int i = 0; i < (int)a.size(); ++i)
        ans += a[i] * b[i];
    return ans;
}

arr mul(const mat &A, const arr &x) {
    arr y(A.size());
    for(int i = 0; i < (int)A.size(); ++i)
        for(int j = 0; j < (int)A[0].size(); ++j)
            y[i] += A[i][j] * x[j];
    return y;
}

mat mul(const mat &A, const mat &B) {
    mat C(A.size(), arr(B[0].size()));
    for(int i = 0; i < (int)C.size(); ++i)
        for(int j = 0; j < (int)C[i].size(); ++j)
            for(int k = 0; k < (int)A[i].size(); ++k)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

