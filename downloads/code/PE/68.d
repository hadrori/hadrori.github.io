import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;
import core.thread;

int[15] seq;
bool[11] used;

void main(){
    seq[] = 0;
    used[] = false;
    seq[0] = 10;
    used[10] = true;
    writeln(dfs(0));
}

long dfs(int cur){
    if(cur == 15){
        int t = 100;
        for(int i = 0; i < 15; i += 3)
            if(t > seq[i]){
                t = seq[i];
                cur = i;
            }
        long ret = 0;
        for(int i = cur; i - cur < 15; i++){
            ret *= 10;
            if(seq[i % 15] == 10) ret *= 10;
            ret += seq[i % 15];
        }
        return ret;
    }
    if(cur == 14){
        int sum = 0;
        foreach(i;0..3)sum += seq[i];
        foreach(i;0..3)sum -= seq[14-i];
        if(sum != 0) return 0;
    }
    if(seq[cur] != 0) return dfs(cur+1);
    long ret = 0;
    if(cur < 3){
        foreach(i;1..11)
            if(!used[i]){
                used[i] = true;
                seq[cur] = i;
                if(cur == 1) seq[14] = i;
                if(cur == 2) seq[4] = i;
                ret = max(ret, dfs(cur+1));
                used[i] = false;
                seq[cur] = 0;
                if(cur == 1) seq[14] = 0;
                if(cur == 2) seq[4] = 0;
            }
    }
    else if(cur % 3 == 2){
        int sum = 0;
        foreach(i;0..3) sum += seq[i];
        sum -= seq[cur-2] + seq[cur-1];
        if(sum <= 0 || sum >= 11 || used[sum]) return 0;
        seq[cur] = sum;
        seq[cur+2] = sum;
        used[sum] = true;
        ret = max(ret,dfs(cur+1));
        used[sum] = false;
        seq[cur] = 0;
        seq[cur+2] = 0;
    }
    else {
        foreach(i;1..11)if(!used[i]){
                seq[cur] = i;
                used[i] = true;
                ret = max(ret,dfs(cur+1));
                seq[cur] = 0;
                used[i] = false;
        }
    }
    return ret;
}
