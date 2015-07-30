import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;
import core.thread;

const int MAX = 1500000;

void main(){
    int ans = 0;
    int[MAX+1] cnt = 0;
    for(long n = 1; n < sqrt(cast(double)MAX); n++)
        for(long m = n + 1; m < sqrt(cast(double)MAX); m += 2)
            if(gcd(n,m) == 1)
                for(long l = 1;; l++){
                    long L = 2*l*m*(m + n);
                    if(L > MAX)break;
                    cnt[L]++;
                }
    foreach(i;1..MAX+1)
        if(cnt[i] == 1) ans++;
    writeln(ans);
}

long gcd(long a, long b){return b?gcd(b,a%b):a;}
