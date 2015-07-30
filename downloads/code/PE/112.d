import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;
import core.thread;

void main(){
    long num = 101;
    long bou = 0;
    while(true){
        string tmp = to!string(num);
        bool inc = false, dec = false;
        foreach(i;0..tmp.length-1)
            if(tmp[i+1] > tmp[i]) inc = true;
            else if(tmp[i+1] < tmp[i]) dec = true;
        if(inc && dec) bou++;
        if(bou * 100 % num == 0 && bou * 100 / num == 99){
            writeln(num);
            break;
        }
        num++;
    }
}
