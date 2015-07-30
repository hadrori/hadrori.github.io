import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;
import core.thread;

//Input
string[] tokens;
int tokenId = 0;
string readToken(){
    for(;tokenId == tokens.length;)
        tokens = readln.split, tokenId = 0;
    return tokens[tokenId++];
}
int readInt(){ return to!int(readToken);}

//chmin/chmax
void chmin(T)(ref T t, T f) { if (t > f) t = f; }
void chmax(T)(ref T t, T f) { if (t < f) t = f; }

//Pair
struct Pair(S, T) {
    S x; T y;
    int opCmp(ref const Pair p) const { return (x < p.x) ? -1 : (x > p.x) ? +1 : (y < p.y) ? -1 : (y > p.y) ? +1 : 0; }
    string toString() const { return "(" ~ to!string(x) ~ ", " ~ to!string(y) ~ ")"; }
}
auto pair(S, T)(S x, T y) { return Pair!(S, T)(x, y); }

int A, B;
int[1024] a, b;
Pair!(int, int)[1024][1024] memo;

void main(){
    A = readInt;
    B = readInt;
    foreach(i;0..1024)
        foreach(j;0..1024) memo[i][j] = pair(-1,-1);
    foreach(i;0..A) a[i] = readInt;
    foreach(i;0..B) b[i] = readInt;
    writeln(rec(0,0).x);
}

Pair!(int,int) rec(int i, int j){
    if(memo[i][j].x >= 0) return memo[i][j];
    if(i == A && j == B) return (memo[i][j] = pair(0,0));
    if(i == A){
        auto tmp = rec(i, j + 1);
        swap(tmp.x, tmp.y);
        tmp.x += b[j];
        return (memo[i][j] = tmp);
    }
    if(j == B){
        auto tmp = rec(i + 1, j);
        swap(tmp.x, tmp.y);
        tmp.x += a[i];
        return (memo[i][j] = tmp);
    }
    auto ret = rec(i + 1, j), hoge = rec(i, j + 1);
    swap(ret.x, ret.y);
    swap(hoge.x, hoge.y);
    ret.x += a[i];
    hoge.x += b[j];
    chmax(ret, hoge);
    return (memo[i][j] = ret);
}
