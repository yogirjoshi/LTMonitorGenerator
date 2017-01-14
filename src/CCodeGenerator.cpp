/*
 * CCodeGenerator.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: yogi
 */

#include "CCodeGenerator.h"
#include <fstream>

using namespace std;
bool CCodeGenerator::writeCPPCode(string id){
	ofstream f1;
	f1.exceptions(ios::failbit | ios::badbit);
	f1.open(string("Monitor" + id + ".cpp").c_str());
	f1 << "#include \"Monitor"<< id << ".hpp\"" <<endl;
	f1 << "namespace LTMon{" << endl;
	f1 << "\t\tLTMonitor" << id << "::LTMonitor" << id << "(){" << endl;
	f1 << "\t\t\tinitialState = \"" << mon.initialState << "\";" << endl;
	for(auto aState: mon.states){
		f1 << "\t\t\tstates.push_back(\""<< aState.name << "\");" << endl;
	}
	f1 << "\t\t}" << endl;
	f1 << "\t\tvoid LTMonitor" + id + "::monitor(string &curr_state, map<string, vector<bool> > &predValues, int size) {" << endl;
	f1 << "\t\t\tfor(int i = 0; i < size; i++) {" <<endl;
	f1 << "\t\t\t\tstring predVal;"<< endl;
	f1 << "\t\t\t\tfor(map<string, vector<bool> >::iterator it = predValues.begin(); it != predValues.end(); ++it){" <<endl;
	f1 << "\t\t\t\t\tif(it->first == \"X\" && it->second[i]){" << endl;
	f1 << "\t\t\t\t\t\tpredVal = \"X\";break;" << endl;
	f1 << "\t\t\t\t\t}" << endl;
	f1 << "\t\t\t\t\tif( it->second[i] && it->first != \"X\") {" << endl;
	f1 << "\t\t\t\t\t\tpredVal+=it->first;" << endl;
	f1 << "\t\t\t\t\t\tpredVal+=\"&&\";" << endl;
	f1 << "\t\t\t\t\t}" << endl;
	f1 << "\t\t\t\t}\n";
	f1 << "\t\t\t\tif(predVal.substr(predVal.length()-2, 2) == \"&&\"){" << endl;
	f1 << "\t\t\t\t\tpredVal = predVal.substr(0,predVal.length()-2);" << endl;
	f1 << "\t\t\t\t}"<<endl;
	for(map <pair<string, string>, string>::iterator it = mon.transition.begin(); it != mon.transition.end();++it){
		f1 << "\t\t\t\t" << "if(predVal == \"" << it->first.second << "\" && curr_state == \"" << it->first.first <<"\"){" << endl;
		f1 << "\t\t\t\t\t" << "curr_state=\"" << it->second << "\";" << endl;
		f1 << "\t\t\t\t}" << endl;
	}
	f1 << "\t\t\t}" << endl;
	f1 << "\t\t}" << endl;
	f1 << "}" << endl;
	f1.close();
	return true;
}

bool CCodeGenerator::writeBaseClass(){
	ofstream f1;
	f1.open("Monitor.hpp");
	f1 << "#ifndef LTLMONITOR_H_" <<  endl;
	f1 << "#define LTLMONITOR_H_" <<  endl;
	f1 << "#include <string>" << endl;
	f1 << "#include <map>" << endl;
	f1 << "#include <vector>" << endl;
	f1 << "using namespace std;" << endl;
	f1 << "namespace LTMon{" << endl;
	f1 << "\tclass LTMonitor {" << endl;
 	f1 << "\t\tpublic:"<< endl;
 	f1 << "\t\t\tstring initialState;"  << endl;
 	f1 << "\t\t\tvector<string> states;"<< endl;
 	f1 << "\t\tvirtual void monitor(string &curr_state, map<string, vector<bool> > &predValues, int size);" << endl;
 	f1 << "\t};\n";
 	f1 << "}\n";
	f1 << "#endif";
	f1.close();
	return true;
	// written states
}
bool CCodeGenerator::writeHeaderCode(string id){
	ofstream f1;
	f1.exceptions(ios::failbit | ios::badbit);
	f1.open(string("Monitor" + id + ".hpp").c_str());
	f1 << "#ifndef LTLMONITOR_H_" << string(id) << endl;
	f1 << "#define LTLMONITOR_H_" << string(id) << endl;
	f1 << "#include \"Monitor.hpp\"" << endl;
	f1 << "using namespace std;" << endl;
	f1 << "namespace LTMon{" << endl;

	f1 << "\tclass LTMonitor"<< id << " : public LTMonitor{" << endl;
	f1 << "\tpublic:" << endl;
	f1 << "\t\tLTMonitor" << id << "();" << endl;
	f1 << "\t\tvirtual void monitor(string &curr_state, map<string, vector<bool> > &predValues, int size) = 0;" << endl;
	f1 << "\t};\n";
	f1 <<"}\n";
	f1 << "#endif";
	f1.close();
	return true;
}
