#include <algorithm>
#include <iostream>

using namespace std;

int N, m[10010];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", m+i);
    sort(m, m+N);
    printf("%d\n", m[N/2]);
    return 0;
}
