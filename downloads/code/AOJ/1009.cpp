#include <cstdio>
#include <algorithm>
int main(){
  int n, m;
  while(~scanf("%d%d",&n,&m))printf("%d\n",std::__gcd(n,m));
}
