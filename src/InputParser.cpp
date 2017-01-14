/*
 * InputParser.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: yogi
 */
#include "InputParser.h"
using namespace std;

bool operator<(const State &s1, const State &s2){
	return s1.name < s2.name;
}
bool LTMonitor::addState(const State &st)
{
	this->states.insert(st);
	return true;
}
bool LTMonitor::setInitialState(const string &stname){
	this->initialState = stname;
	return true;
}
bool LTMonitor::setTransition(const string &src, const string &dst, const string &alpha){
	this->transition[pair<string,string>(src,alpha)] = dst;
	return true;
}
bool LTMonitor::addAlphabet(const string &alpha)
{
	this->alphabet.insert(alpha);
	return true;
}
vector<string> InputReader::explode(string str, string delim){
	size_t prev = -1;
	size_t start = -1;
	vector<string> retVal;
	while((start = str.find(delim, prev+1)) != string::npos){
		retVal.push_back(str.substr(prev+1, start-prev-1));
		prev= start;
	}
	retVal.push_back(str.substr(prev+1));
	return retVal;
}

bool InputReader::parseInputFile(){
	string line;
	while(getline(cin, line)){
		if(line.find("Initial") != string::npos){
			size_t off1 = line.find_first_of('=');
			string initState = line.substr(off1+1, line.length()-off1-1);
			mon.setInitialState(initState);
			cout<<"Initial State:" << initState<<endl;
		}
		if(line.find("DELTA") != string::npos){
			size_t first_left_bracket = line.find_first_of('(');
			size_t first_comma = line.find_first_of(',');
			string st1 = line.substr(first_left_bracket+1, first_comma - first_left_bracket-1);
			size_t second_comma = line.find_last_of('=');
			string st2 = line.substr(second_comma+1);
			size_t second_left_bracket = line.find_first_of('(', first_left_bracket+1);
			string alpha;
			if (second_left_bracket != string::npos){
				size_t second_right_bracket = line.find_first_of(')',second_left_bracket+1);
				alpha = line.substr(second_left_bracket+1,second_right_bracket- second_left_bracket - 1);
				mon.setTransition(st1, st2, alpha);
				for(string anAlpha: explode(alpha, "&&")){
					mon.addAlphabet(anAlpha);
				}
			}else{
				alpha="X";
				mon.addAlphabet(alpha);
				mon.setTransition(st1, st2, alpha);
			}
			cout<<"Transition:" << st1 <<":"<<alpha << ":"<<st2<<endl;
		}
		if(line.find("STATE") != string::npos){
			size_t first_equal = line.find_first_of("=");
			size_t first_comma = line.find_first_of(",");
			string stateName = line.substr(first_equal+1,first_comma-first_equal-1);
			size_t second_equal = line.find_last_of( "=");
			string stateOutput = line.substr(second_equal+1, line.length()-second_equal-1);
			mon.addState(State(stateName, stateOutput));
			cout<<"State "<<stateName<<":"<<stateOutput<<endl;
		}
	}
	return true;
}

