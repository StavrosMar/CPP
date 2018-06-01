/* Test2 from  testDome 

  non digit values should be ignored for NumericInput.
  
*/


#include <iostream>
#include <string>

using namespace std;


class TextInput
{
private:
    
    std::string instring;
    
public:
    virtual void add(char c) {
        
        instring+=c;
    
    }

    std::string getValue() { return instring; }
};

class NumericInput : public TextInput {
    
    void add(char c) {
        
        if (isdigit(c)) {
            //Running inheritted method.
            TextInput::add(c);
        }
    }
    
};

#ifndef RunTests
int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
#endif
