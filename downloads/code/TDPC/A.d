import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;

//Input
string[] tokens;
int tokenId = 0;
string readToken(){
    for(;tokenId == tokens.length;)
        tokens = readln.split, tokenId = 0;
    return tokens[tokenId++];
}
int readInt(){ return to!int(readToken);}

void main(){
    bool[10010] dp = false;
    int n = readInt;
    int sum = 0;
    dp[0] = true;
    foreach(i;0..n){
        int p = readInt;
        for(int j = sum; j >= 0; j--)
            dp[j + p] |= dp[j];
        sum += p;
    }
    int ans = 0;
    foreach(i;0..sum+1)if(dp[i])ans++;
    writeln(ans);
}
