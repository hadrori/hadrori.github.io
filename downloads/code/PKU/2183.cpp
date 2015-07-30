#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>

using namespace std;

const int mod = 1000000;
int table[1000000];
int num;

int main(){
    memset(table,-1,sizeof(table));
    scanf("%d", &num);
    table[num] = 0;
    for(int i = 1; ; i++){
        num /= 10;
        num %= 10000;
        num = num * num % mod;
        if(table[num] >= 0) {
            printf("%d %d %d\n", num, i - table[num], i);
            break;
        }
        table[num] = i;
    }
    return 0;
}
