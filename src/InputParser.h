/*
 * InputParser.h
 *
 *  Created on: Jan 8, 2017
 *      Author: yogi
 */

#ifndef INPUTPARSER_H_
#define INPUTPARSER_H_
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class State{
public:
	string name;
	string output;
	State(string name, string output): name(name), output(output){}
	friend bool operator< (const State &st1, const State &st2);
};

class LTMonitor{
public:
set<State> states;
set<string> alphabet;
map <pair<string, string>, string> transition;
string initialState;

public:

inline LTMonitor(){

}
bool addState(const State &st);
bool addAlphabet(const string &alpha);
bool setTransition(const string &src, const string &dest, const string &alpha);
bool setInitialState(const string &st);
};


class InputReader{
public:
	ifstream inputFile;
	LTMonitor mon;
public:
	inline InputReader(){
		cin.exceptions(std::ifstream::badbit );
	}
	bool parseInputFile();
	vector<string> explode(string str, string delim);
};

#endif /* INPUTPARSER_H_ */
