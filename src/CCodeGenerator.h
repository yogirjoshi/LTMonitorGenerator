/*
 * CCodeGenerator.h
 *
 *  Created on: Jan 8, 2017
 *      Author: yogi
 */

#ifndef CCODEGENERATOR_H_
#define CCODEGENERATOR_H_
#include "InputParser.h"
class CCodeGenerator{
	LTMonitor mon;
public:
	inline CCodeGenerator(LTMonitor &mon): mon(mon){

	}
	bool writeHeaderCode(string);
	bool writeCPPCode(string);
	bool writeBaseClass();
};



#endif /* CCODEGENERATOR_H_ */
