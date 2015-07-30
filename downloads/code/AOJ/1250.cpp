#include <iostream>
#include <cstdio>
#include <vector>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

int main(){
    int s;
    cin >> s;
    while(s--){
        vector<unsigned int> n(10);
        rep(i,9){
            scanf("%x", &n[i]);
        }
        unsigned int k = 0;
        rep(i,32){
            unsigned int sum = 0;            
            rep(j,8) sum += n[j];
            if((sum&(1<<i)) != (n[8]&(1<<i))){
                k |= 1<<i;
            }
            rep(j,9) n[j] ^= (k&(1<<i));
        }
        printf("%x\n",k);
    }
}
