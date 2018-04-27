#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
   
    int W; //width
    int H; //height
    std::cin >> W >> H ; std::cin.ignore();
    
    int N; //max number of times
    std::cin >> N ; std::cin.ignore();
    
    int X0,Y0;
    std:cin >> Y0 >> X0 ; cin.ignore();
    
       map<char,int> bbx{{'D',H-1},{'U',0}};
    map<char,int> bby{{'L',0},{'R',W-1}};
     
    int Xcurr{X0};
    int Ycurr{Y0};
    
    int error = 1000;
    int bb1(-100),bb2(-100),Ax,Bx,Ay,By,Xcurrprev,Ycurrprev;
    int incx(0), incy(0);
    int stuck(-1);
    
    string bombDirprev;
    // game loop
    while (!(error<1 && stuck<3)) {
    
        Xcurrprev = Xcurr;
        Ycurrprev = Ycurr;
        
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();
        
        
        if (bombDir.length()>1) {
      
            bb1 = bbx[bombDir[0]];
            bb2 = bby[bombDir[1]];
            
            (error > 0)? stuck=0: (incx = 1, incy = 1, stuck++);
            
         //   cout<<"entered if 1"<<"\n";
                    
        } else if (bbx.find(bombDir[0])!=bbx.end()) {
            
            bb1 = bbx[bombDir[0]];
            bb2 = Ycurrprev;
            (error > 0)? stuck=0: (incx = 1, incy = 0, stuck++);
            
         //   cout<<"entered if 2"<<"\n";
        } else {
            
            bb1 = Xcurrprev;
            bb2 = bby[bombDir[0]];
            (error > 0)? stuck=0: (incx = 0, incy = 1, stuck++);
          //  cout<<"entered if 3"<<"\n";
        }              
      
        Ax = min(Xcurr,bb1);
        Bx = max(Xcurr,bb1);
        Ay = min(Ycurr,bb2);
        By = max(Ycurr,bb2);        
        
        
       Xcurr = int(ceil(0.5*(Ax+Bx)))-incx;
       Ycurr = int(ceil(0.5*(Ay+By)))-incy;
       
       error = abs(Xcurr-Xcurrprev) + abs(Ycurr-Ycurrprev);
       
        // the location of the next window Batman should jump to.
        cout << to_string(Ycurr)+" "+(to_string(Xcurr)) << endl;
    }
}
