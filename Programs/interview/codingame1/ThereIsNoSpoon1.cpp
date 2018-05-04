#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
 
 class Hash {
     
 
 Hash(const int& N) : m_N{N} {};
 
 int operator()(const int& x, const int& y) {
    
    return (x+m_N*y);   
    
 }
 private:
 
    int m_N = 100; //Default size
};

class Point {

public:   
    Point(const int& x = 0, const int& y = 0) : m_x(x),m_y(y) {};
    
    int x() {
        
        return m_x;
    }
    
    int y() {
        
        return m_y;
    }
    
private:

    int m_x;
    int m_y;

};

int main()
{
    int width; // the number of cells on the X axis
    list<Point> ListCoors;
    
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        
        for (int j=0; j < line.length() ; j++ ){
            
            if ( line[j] != '0' ) {
                
                ListCoors.push_back( Point{line[j],i} );
                
            }
        }
    }
    
    

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
   
    // Three coordinates: a node, its right neighbor, its bottom neighbor
    cout << "0 0 1 0 0 1" << endl;
}
