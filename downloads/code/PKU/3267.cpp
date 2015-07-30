#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int inf = int(1e9);
int W, L;
string word;
string dict[610];
int dp[512];

int cost(int head, int j){
    for(int tail = 0, i = head; i < L && tail < dict[j].size(); i++){
        if(word[i] == dict[j][tail]) tail++;
        if(tail == dict[j].size()) return i+1 - head - dict[j].size();
    }
    return inf;
}

int main(){
    cin >> W >> L;
    cin >> word;
    for(int i = 0; i < W; i++) cin >> dict[i];

    for(int i = 0; i < 512; i++) dp[i] = inf;
    dp[0] = 0;

    for(int i = 0; i < L; i++){
        for(int j = 0; j < W; j++)
            if(i + dict[j].size() <= L){
            int c = cost(i, j);
            if(c > L) continue;
            int t = i + c + dict[j].size();
            dp[t] = min(dp[t], dp[i]+c);
        }
    }
    
    int ans = inf;
    for(int i = 0; i <= L; i++)
        ans = min(ans, L-i+dp[i]);

    cout << ans << endl;
    return 0;
}
