//============================================================================
// Name        : LTMonitorLibGenerator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "CCodeGenerator.h"
using namespace std;

int main(int arc, char *argv[]) {
	InputReader ip;
	ip.parseInputFile();
	CCodeGenerator cc(ip.mon);
	cc.writeHeaderCode("1");
	cc.writeCPPCode("1");
	cc.writeBaseClass();
	return 0;
}
