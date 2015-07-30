#include <cstdio>
#include <cstring>

using namespace std;

int ans, in[2];
int dp[64][64][2][2];
int combi[64][64];

void gen(){
    combi[0][0] = 1;
    for(int i = 1; i < 64; i++){
        combi[i][0] = 1;
        for(int j = 1; j <= i; j++)
            combi[i][j] = combi[i-1][j-1]+combi[i-1][j];
    }
}

int calc(int p){
    int ret = 0;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    for(int i = 1, t = p; t > 0; i++){
        int b = t % 2; t >>= 1;
        for(int j = 0; j < i; j++)
            for(int k = 0; k < 2; k++)
                if(k < b) 
                    for(int x = 0; x < 2; x++)
                        for(int y = 0; y < 2; y++)
                            dp[i][j+1][k][0] += dp[i-1][j][x][y];
                else if(k == b)
                    for(int x = 0; x < 2; x++){
                        dp[i][j+(k==0)][k][0] += dp[i-1][j][x][0];
                        dp[i][j+(k==0)][k][1] += dp[i-1][j][x][1];
                    }
                else
                    for(int x = 0; x < 2; x++)
                        for(int y = 0; y < 2; y++)
                            dp[i][j][k][1] += dp[i-1][j][x][y];
        if(!t){
            for(int j = i; j > (i-1)/2; j--)
                ret += dp[i][j][1][0];
            for(int k = 1; k < i; k++)
                for(int j = k-1; j > (k-1)/2; j--)
                    ret += combi[k-1][j];
        }
    }
    return ret+1;
}

int main(){
    gen();
    /*
    while(1){
        int p; cin >> p;
        cerr << "-> " << calc(p) << endl;
    }
    */
    scanf("%d%d", in, in+1);
    in[0]--;
    printf("%d\n", calc(in[1])-calc(in[0]));
    return 0;
}
