import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;
import core.thread;

long[37] pcnt, ccnt;
void main(){
    pcnt[] = 0; ccnt[] = 0;
    pdfs(0,9); cdfs(0,6);
    long[37] csum = 0;
    long psum = 0;
    foreach(i;1..37){
        csum[i] = csum[i-1] + ccnt[i];
        psum += pcnt[i];
    }
    double ans = 0;
    foreach(i;1..37){
        ans += csum[i-1] * pcnt[i];
    }
    writefln("%.7f",ans / (psum * csum[36]));
}

void pdfs(long sum, int k){
    if(k == 0){
        pcnt[sum]++;
        return;
    }
    foreach(i;1..5) pdfs(sum+i,k-1);
}
void cdfs(long sum, int k){
    if(k == 0){
        ccnt[sum]++;
        return;
    }
    foreach(i;1..7) cdfs(sum+i,k-1);
}
