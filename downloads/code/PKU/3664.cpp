#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef pair<int,int> pii;


int N, K;
vector<pii> A, B;
bool can[50010];

int main(){
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++){
        int a, b; scanf("%d%d", &a, &b);
        A.push_back(pii(a, i+1));
        B.push_back(pii(b, i+1));
    }
    sort(A.rbegin(), A.rend());
    for(int i = 0; i < K; i++)
        can[A[i].second] = 1;
    sort(B.rbegin(), B.rend());
    for(int i = 0; i < N; i++)
        if(can[B[i].second]) {
            printf("%d\n", B[i].second);
            break;
        }
    return 0;
}
