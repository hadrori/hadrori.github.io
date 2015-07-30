#include <algorithm>
#include <cstdio>

using namespace std;

int bowl[32];
int seq1[32], seq2[32];

int main(){
    for(int i = 0; i < 20; i++){
        scanf("%d", bowl+i);
        seq1[i] = seq2[i] = bowl[i];
    }
    int ans1 = 0;
    for(int i = 0; i < 19; i++)
        if(seq1[i]){
            ans1++;
            seq1[i] = 0;
            if(i + 1 < 20) seq1[i+1] = (seq1[i+1] + 1) % 2;
            if(i + 2 < 20) seq1[i+2] = (seq1[i+2] + 1) % 2;
        }
    int ans2 = 0;
    for(int i = 19; i > 0; i--)
        if(seq2[i]){
            ans2++;
            seq2[i] = 0;
            if(i - 1 >= 0) seq2[i-1] = (seq2[i-1] + 1) % 2;
            if(i - 2 >= 0) seq2[i-2] = (seq2[i-2] + 1) % 2;
        }
    
    printf("%d\n", min(ans1, ans2));
    return 0;
}
