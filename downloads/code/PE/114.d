import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;
import core.thread;

long[64] dp;

void main(){
    dp[0] = dp[1] = dp[2] = 1;
    foreach(unit;3..51){
        dp[unit] = unit - 1;
        foreach(i;0..unit-2)
            for(int j = 3; j + i < unit; j++)
                dp[unit] += dp[unit-j-i-1];
        stderr.writeln("Unit ", unit, ": ",dp[unit]);
    }
    stderr.writeln(dp[7]);
    writeln(dp[50]);
}
