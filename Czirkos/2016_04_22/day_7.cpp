#include <iostream>
#include <cstido>
using namespace std;

typedef struct {
	string lop; //Left operand.
	string rop; //Right operand.
	string op; //Operation.
} op;

typedef struct {
	unsigned short value;
	bool on;
} wire;

wire resolve (wire lop, wire rop, string op) {
	if(!lop.on) return lop;
	if(!rop.on && op!="NOT") return rop; 
	switch (op) {
		case "AND": return lop & rop;
		case "OR": return lop | rop;
		case "LSHIFT": return lop << rop;
		case "RSHIFT": return lop >> rop;
		case "NOT": return ~lop;
	}
}

map<string, wire> wires;
map<string, op> gates;

int main () {

	string line;
	unsigned short val;
	string lop;
	string rop;
	string op;
	wire tmpwire;
	op tmpop;
	while(getline(cin, line)) {
		if(sscanf(line, "%u -> %s", &val, &lop)) {
			tmpwire.value = val;
			tmpwire.on = true;
			wires.insert(lop, tmpwire);	
		} else if (sscanf(line, "%s %s %u") {


		} else () {
		
		}

		
	
	
	}

	return 0;
}
