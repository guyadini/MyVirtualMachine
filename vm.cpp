#include "vm.h"
#include <iostream>
#include <boost/algorithm/string.hpp>



using namespace std;
#define DEBUG

#ifdef DEBUG

#define DEBUG_PRINT(x) cout << x << endl;

#endif

//create the instructionSet variable according to input file
void VirtualMachine::parseInstructionSetFile(const string instFileName){

}



//Translate all textual instructions into actual Instruction objects
void VirtualMachine::addInstructions(const vector<string> &instVec){
	DEBUG_PRINT("Entering addInstructions\n")
	for (auto si = instVec.begin(); si!=instVec.end(); si++){
		DEBUG_PRINT("Adding instruction " << *si)
		this->addInstFromStr(*si);
	}

}

//execute the next instruction, advance the nextInst iterator
VirtualMachine::InstStatus VirtualMachine::executeNextInstruction(){
	if (nextInst==this->code.end()) return EOI;
	nextInst->execute();
	nextInst++;
	return GOOD;
}

//execute all instructions until EndOfInstructions
void VirtualMachine::executeAllInstructions(){
	while ( (this->executeNextInstruction() ) != EOI) {}
}

void X86Machine::addInstFromStr(const string s){
	//TODO: start by supporting pushl, movl, leal, addl, subl, ret.
	//For each of them, create a class, by overriding the execute() function.
	//The execute() function must change the stack pointer, the stack 
	//(by storing/popping register values), and the registers.
	//The ret instruction must terminate.
	try{
		DEBUG_PRINT("got instruction " << s)	
		vector<string> instTokens;
		boost::split(instTokens,s, boost::is_any_of(" \t,"));
		//TODO - get rid of length 0 tokens
		//TODO - separate the case of labels (starting with ".")
		string commandName = instTokens[0];
		if (instructionSet.count(commandName)==0) 
			throw InvalidInstructionException("Unrecognized instruction: " + commandName);
	}

	catch(InvalidInstructionException e){
		DEBUG_PRINT(e.msg);
		throw(e);
	
	}
}
