#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 1000010;

bool p[MAX];
vector<int> prime;

void pcalc(){
    for(int i = 0; i < MAX; i++)
        p[i] = (i < 2)? false: true;
    for(int i = 0; i < MAX; i++)if(p[i]){
            prime.push_back(i);
            for(int j = 2 * i; j < MAX; j += i) p[j] = false;
        }
    return;
}

int main(){
    pcalc();
    int maxlen = 0;
    int maxp = 0;
    for(int i = 0; i < prime.size(); i++){
        int l = 0, r = 0;
        int sum = 2, p = prime[i];
        do{
            if(sum < p){
                r++;
                sum += prime[r];
            }
            else if(sum > p){
                sum -= prime[l];
                l++;
            }
            if(sum == p){
                if(maxlen < r - l + 1){
                    maxlen = r - l + 1;
                    maxp = p;
                }
                break;
            }
        }while(l < r);
    }
    cout << maxp << endl;
}
