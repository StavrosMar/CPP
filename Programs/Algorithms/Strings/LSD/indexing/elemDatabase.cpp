
/*
*   Topics covered:
*                    1) Core database structure.
*					    Idea in the process of building the indexing structure.
*						Tried not using templates in the beginning - design patterns only.
*					 
*					
*	TODO:
*					1) Use database 
*					2) Support basic database operations
*				       a) search b) delete c)
*					3) Extensibility i.e. test that we can arbitrarily add fields.
*					4) Multithreading safe
*					   a)per DbField granularity i.e. do not lock the entire structure if using locks if
*					   b)Lock implementation
*					   b)Lock free.
*                    
*/

//Draft for runtime resolution - 

//Interface for concrete Records - a Record consists of different Fields.
class DbField {
protected:
	const char* _type;
public:
	//const char* _type;
	virtual void convert(const string& s1) {
		this->convert(s1);
	};
	virtual ~DbField() = default;
};

//A integer based field;
class intField : public DbField {
public: 
	//Allow only construction via a string.

	intField(const char* t) { _type = t; };
	intField() = delete;
	intField& operator=(const intField&) = delete;

	int convert(const string s1) {
		return stoi(s1);
	}
};

//Class used for building an instace of a Record. The Fields needed are added here.
class DbRec {
	std::map<const char*,DbField*> DbFields; //fields of Database
	
	//add the fields for a DbRec - could
	void addField(const char* fName,DbField* f) {
		DbFields[fName] = f;
	}
	
	//Register all fields i.e. Field = new ...

	/*s_in is the string representation of the input as read by the parser.
	void convertFields(const string& s_in) {
		for (auto f : DbFields) {
			f->convert(s_in);
		}
	*/
};
