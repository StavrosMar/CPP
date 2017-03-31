// Alternative implementations of the operator << for String

// I created this example to troubleshoot a classic for_loop that was in place
(thought that it was not working because of s.begin() and s.end() member functions returning const C* pointers
Turned out I just had to add the word const in front of it and works like a charm (Second example - line 18)


// Member function
template<typename C>
std::ostream& operator<<(std::ostream& os, String<C>& s) {
	
	for(auto x : s ) {   // in order auto to work String must have begin() and end() functions defined.
		
		os<<x;
	
	}
	
	for(const C* i=s.begin() ; i!=s.end() ; ++i ) {   // classic for loop
	
		os<<*i;
	
	}
		
	for(auto i=s.begin() ; i!=s.end() ; ++i ) {   // classic for loop with auto
	
		os<<*i;
	
	}	

	return os;
}
