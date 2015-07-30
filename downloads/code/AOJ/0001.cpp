#include <iostream>
#include <algorithm>
main(){int h[10]={0};for(int i=0;i<10;std::cin >>h[i++]);sort(h,h+10);for(int i=0;i<3;std::cout<<h[9-i++]<<'\n');
}