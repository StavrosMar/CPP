/* Palindrome Exercise 
    
   * Ignoring Capital / lowercase difference
     For Example "Deleveled" should return true as character case is ignored
   
   * Implemented for https://www.testdome.com/t 
   
*/
#include <string>
#include <stdexcept>
#include <iostream>
#include <cstdlib>


using namespace std;
//TODO - adapt it for ignoring capitals

class Palindrome
{
public:
    static bool isPalindrome(const std::string& word)
    {
        auto length=word.length();
        auto  diva(std::div(length,2));
        
        bool pal{true};
        
         for (int i = 0; i <= (diva.quot-1) ; ++i) {
              
             if( word[i] != word[length-i-1] && abs(word[i]-word[length-i-1]) != 32 ) {
                 pal = false;
                 break;
             }
         }
        
          return pal;
      }
        
};

#ifndef RunTests
int main()
{
    std::cout << Palindrome::isPalindrome("ananA");
}
#endif
