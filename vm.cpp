#include "vm.h"
#include <iostream>

using namespace std;
#define DEBUG

#ifdef DEBUG

#define DEBUG_PRINT(x) cout << x << endl;

#endif

//TODO: declare that it can throw an exception
//Translate all textual instructions into actual Instruction objects
void VirtualMachine::addInstructions(const vector<string> &instVec){
	for (auto si = instVec.begin(); si!=instVec.end(); si++){
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
	DEBUG_PRINT("got instruction " << s)	

}
