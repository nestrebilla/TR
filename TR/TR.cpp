// TR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Parser.h"
#include "Robot.h" 
#include <iostream>

using namespace std;
using namespace TR;

int main()
{
	Parser parser;
	Robot robot;
	string line;

	while (getline(cin, line)) {
		try {
			Command cmd = parser(line);
			robot.execute(cmd);
		}
		catch (const exception &e) {
			// Handle invalid commands gracefully
			cerr << "Error: " << e.what() << endl;
		}
	}
	return 0;
}
