import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;

const long MAX = 1 << 30;

void main(){
    int ans = 0;
    foreach(n;1..MAX+1){
        long x = n;
        x ^= 2 * n;
        x ^= 3 * n;
        if(!x) ans++;
    }
    writeln(ans);
}
