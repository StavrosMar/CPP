// This is to check why const String<C>& x declarations don't work in my String template

#include <iostream>



int& printInt(int& addition, const int& stavros) {
    
    std::cout<< stavros << std::endl;
    
    int res = stavros + 3324;
    
    return stavros;
}


int main() {
    
    int nikos(123);
    
    int addition = printInt(nikos);
    
    std::cout<<*addition<<std::endl;
    
    return 0;
    
