//============================================================================
// Name        : LTMonitorLibGenerator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "CCodeGenerator.h"
using namespace std;

int main(int argc, char *argv[]) {
	InputReader ip;
	if ( argc < 2 ){
		throw invalid_argument("Monitor name not provided");
	}
	try {
		ip.parseInputFile();
		CCodeGenerator cc(ip.mon);
		cc.writeHeaderCode(argv[1]);
		cc.writeCPPCode(argv[1]);
		cc.writeBaseClass();
	}
	catch (ofstream::failure &e) {
		cerr << "Failed to perform IO ->" << e.what() << endl;
		return -1;
	}
	return 0;
}
