#include <cstdio>
#include <vector>

using namespace std;

vector<int> primes;
bool np[20010];

void gen(){
    np[0] = np[1] = 1;
    for(int i = 2; i < 20010; i++)
        if(!np[i]){
            primes.push_back(i);
            for(int j = i * i; j < 20010; j += i)
                np[j] = 1;
        }
}

int N, M, ans, pos;

int main(){
    gen();
    scanf("%d", &N);
    ans = 1;
    while(N --> 0){
        int num; scanf("%d", &num);
        for(int i = pos; primes[i] <= num; i++)
            if(num % primes[i] == 0 && primes[i] > M){
                ans = num;
                pos = i;
                M = primes[i];
            }
    }
    printf("%d\n", ans);
    return 0;
}
