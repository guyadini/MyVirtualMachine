#include "vm.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	X86Machine vm("");
	vector<string> instructions;
	char nextS[256];
	while ( (cin.getline(nextS,255)) ) instructions.push_back(string(nextS));
	vm.addInstructions(instructions);	
	return 0;	
}
