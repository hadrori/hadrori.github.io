import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;
import core.thread;

const long D = 2000000;

void main(){
    long ans = 0;
    long dif = 1000000;
    for(long m = 1; m < sqrt(cast(double)D*4)/2; m++){
        long t = m * (m + 1);
        long lb = 0, ub = cast(long)sqrt(cast(double)D*4);
        while(lb + 1 < ub){
            long mid = (lb + ub) / 2;
            if(mid * (mid + 1) * t > 4 * D)ub = mid;
            else lb = mid;
        }
        if(abs(ub * (ub + 1) * t - 4 * D) < dif){
            ans = ub * m;
            dif = abs(ub * (ub + 1) * t - 4 * D);
        }
        if(abs(lb * (lb + 1) * t - 4 * D) < dif){
            ans = lb * m;
            dif = abs(lb * (lb + 1) * t - 4 * D);
        }
    }
    writeln(ans);
}
