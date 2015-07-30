#include<iostream>#include<string>
main(){std::string s;std::cin>>s;std::cout<<((s[0]-'o')?*--s.end():'o')<<'\n';}
