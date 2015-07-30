#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int N;
string seq = "";
string ans = "";

int main(){
    scanf("%d\n", &N);
    for(int i = 0; i < N; i++){
        char c; scanf("%c\n", &c);
        seq.push_back(c);
    }
    int l = 0, r = N-1, len = 0;
    while(l <= r){
        if(seq[l] < seq[r]) ans.push_back(seq[l++]);
        else if(seq[l] > seq[r]) ans.push_back(seq[r--]);
        else{
            string ls = seq.substr(l,N-len);
            string rs = seq.substr(l,N-len);
            reverse(rs.begin(), rs.end());
            if(ls < rs) {
                ans.push_back(ls[0]);
                l++;
            }
            else {
                ans.push_back(rs[0]);
                r--;
            }
        }
        len++;
    }
    for(int i = 0; i <= N / 80 - int(N % 80 == 0); i++){
        for(int j = 0; j < min(N-i*80,80); j++)
            printf("%c", ans[i*80+j]);
        printf("\n");
    }
    return 0;
}
