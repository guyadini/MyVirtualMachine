#include <map>
#include <string>
#include <vector>
#include <exception>

std::vector<std::string> strs;



//not to pollute the namespace
using std::string;
using std::vector;
using std::map;


//abstract instruction class
class Instruction{
	vector<string> operands;

public:
	virtual void execute() = 0;

}; 

//Abstract virtual machine class
class VirtualMachine{
	

protected:
	map<string,int> registers; //maps register name to value
	vector<Instruction> code;
	vector<Instruction>::iterator nextInst;
	map<int,int> stack; //maps from locations relative to stack base, to corresponding values
//protected functions	
	virtual void addInstFromStr(const string s) = 0;
//nested exception classes
	struct InvalidInstructionException{
		string msg;
		InvalidInstructionException(string s) {msg = s;}
	};

public:
	enum InstStatus{GOOD, BAD,EOI};
//public functions
	void addInstructions(const vector<string> &instVec);
	InstStatus executeNextInstruction();
	void executeAllInstructions();
	VirtualMachine() {nextInst = code.begin();}	
};


//Emulates some SUBSET of X86 instructions. 
class X86Machine : public VirtualMachine{
protected:
	virtual void addInstFromStr(const string s);

public:
	X86Machine(){
		

	}


};


