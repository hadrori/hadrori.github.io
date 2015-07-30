import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;
import core.thread;

char[] num;

void main(){
    num ~= "1_2_3_4_5_6_7_8_900";
    writeln(dfs(1));
}

long dfs(int cur){
    if(cur == 17){
        long x = to!long(num);
        long k = cast(long)sqrt(cast(double)x);
        if(x == k * k) return k;
        else return -1;
    }
    foreach(i;0..10){
        num[cur] = cast(char)(i + 48);
        long t = dfs(cur + 2);
        if(t >= 0) return t;
    }
    return -1;
}
