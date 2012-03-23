#include "vm.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	X86Machine vm;
	vector<string> instructions;
	string nextS;
	while ( (cin>>nextS) ) instructions.push_back(nextS);
	vm.addInstructions(instructions);	
	return 0;	
}
