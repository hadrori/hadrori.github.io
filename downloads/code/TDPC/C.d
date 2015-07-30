import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;
import core.thread;

string[] tokens;
int tokenId = 0;
string readToken(){
    for(;tokenId == tokens.length;)
        tokens = readln.split, tokenId = 0;
    return tokens[tokenId++];
}
int readInt(){ return to!int(readToken);}

int k;
int[1024] r;
double memo[1024][16];

void main(){
    k = readInt;
    foreach(i;0..1024) memo[i][] = -1;
    foreach(i;0..1<<k) r[i] = readInt;
    foreach(i;0..1<<k) writefln("%.10f", rec(i,k));
}

double rec(int m, int n){
    if(memo[m][n] >= 0) return memo[m][n];
    if(n == 0) return memo[m][n] = 1;
    
    double ret = 0, prev = rec(m, n - 1);
    int d = k - n;
    int left = 0, right = 1 << k, res;
    foreach(i;0..d){
        res = (left + right) / 2;
        if(m < res) right = res;
        else left = res;
    }
    res = (left + right) / 2;
    if(m < res) left = res;
    else right = res;
    foreach(i; left..right)
        ret += prev * rec(i, n - 1) / (1 + pow(10.0, 1.0 * (r[i] - r[m]) / 400));
    return (memo[m][n] = ret);
}
