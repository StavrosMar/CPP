// Why my implementation did not work

#include<iostream>
#include<vector>
#include<string>
#include<map>

//*****My initial**********
namespace initial {

// Assoc Definition
class Assoc {
public:
        using VecOfPairs = std::vector<std::pair<std::string,int>>;

        // Plain members
        VecOfPairs vec;

};


// Map Definition
class Map : public Assoc {

        //Constructors
        /* Issue here
           there is not constructor defined for Assoc
           Initialiser cannot be used like that */
//	   Map(VecOfPairs& vinput) : vec{vinput} {}; //Giati den vlepei to vec ???
};

}



//**** Ody proposed 1 ************
namespace ody1 {

// Assoc Definition
 class Assoc {
  public:
          using VecOfPairs = std::vector<std::pair<std::string,int>>;
  Assoc(VecOfPairs& inVec) : vec{inVec} {}


       // Plain members
      VecOfPairs vec;
 
 };


// Map Definition
 class Map : public Assoc {
 public:
       //Constructors
       //Explicitly run the constructor of Assoc to initialise all members coming from Assoc
        Map(VecOfPairs& vinput) : Assoc::Assoc(vinput) {}; 
 	
	
	//Testing Stavros
	/*-//If I enable the following vec then
	   	it takes precedence over the one inherited by Assoc.
		thus if print_lememe() is run it through a Segfault
		as this vec has not yet been initialised
	   	//VecOfPairs vec;
	*/
	
	void print_lememe() {
		
		std::cout<<vec[0].first<<std::endl;
	}
	//Testing Stavros - End
 };

}


//******* Ody proposed 2 ***********
namespace ody2 {

#include <iostream>
#include <vector>

// Assoc Definition
 class Assoc {
  public:
        
	using VecOfPairs = std::vector<std::pair<std::string,int>>;
  	Assoc(VecOfPairs& inVec) : vec{inVec} {}

      // Plain members
     VecOfPairs vec;

};


// Map Definition
 class Map : public Assoc {
	
	// Explicitly inherit the constructor
        using Assoc::Assoc;
 };

}


int main() {
std::vector<std::pair<std::string,int>> t{ {"hipHop",1} };

ody1::Map a {t};

//Testing Stavros - main
//Try commenting and uncommenting //Testing - Stavros section
a.print_lememe();
//Testing Stavros - main - End

}

