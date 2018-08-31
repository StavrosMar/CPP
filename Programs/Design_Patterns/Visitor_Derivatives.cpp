#include <iostream>
#include <map>

using namespace std;

/*
*
*   Topics covered :
*                    Visitor Pattern : Given a number of Instruments not open for modification / Extension,
                                       add a number of actions on them (could be buttons for Front End for example)
*
*/

//Abstract class - interface for algos//

class Derivative;
class Strategy;


// Abstract visitor
class aVisitor {
public:
    virtual void dispatch(Derivative& i) = 0;
    virtual void dispatch(Strategy& i) = 0;

    
    virtual ~aVisitor() = default;
};

// I could potentially add as many streams as possible
class OrderInfo : public aVisitor {
public:
   void dispatch(Strategy& i) {};
   void dispatch(Derivative& i) {};
    ~OrderInfo() = default;
};

class TradeInfo : public aVisitor {
public:
   void dispatch(Strategy& i) {};
   void dispatch(Derivative& i) {};
    //~TradeInfo() = default;
};

class BalancePosition : public aVisitor {
public:
   void dispatch(Strategy& i) {};
   void dispatch(Derivative& i) {};
    //~BalancePosition() = default;
};


class Algo { 
public:
    //Abstract class for Algos;
    virtual const char* name() const = 0;
    virtual void execute() const = 0;
    virtual ~Algo() = default;
};

class VWAP : public Algo { 
private:
    const char* aname;
public:
    VWAP() : aname{"VWAP"} {};
    void execute() const {};
    const char* name() const {return aname;}
};

//Abstract class 
class Instrument { 
public:
    virtual ~Instrument() = default ;
};

class Strategy : public Instrument {
public:
   const char* name = "Strategy";
    virtual void acceptOp(aVisitor* oper) {
        oper->dispatch(*this);
    }
};

class Derivative : public Instrument {
public:
    const char* name = "Derivative";
    virtual void acceptOp(aVisitor* oper) {
        oper->dispatch(*this);
    }
};

//this keeps an algolist of all available algos - they can be register like factory.
class SendToAlgo : public aVisitor {
private:
    const Algo* algo;

public:
    SendToAlgo(const Algo* algo) : algo{algo} { };
    SendToAlgo() = delete;
    
    void dispatch(Strategy& i) { algo->execute(); cout<<"Executing "<<algo->name()<<" on a "<<i.name<<'\n';};
    void dispatch(Derivative& i) {algo->execute(); cout<<"Executing "<<algo->name()<<" on a "<<i.name<<'\n';};
    ~SendToAlgo() = default;
};



//This is our client
int main()
{
    Strategy butterfly;
    Derivative coffee;
    
    VWAP vwap;  //Build an algo object - could have done via a factory.
    SendToAlgo algosend(&vwap); //implicit cast from VWAP* to Algo*
    butterfly.acceptOp(&algosend); 
    coffee.acceptOp(&algosend);
   return 0;
}
