/**
Kristian Kerrigan
ee_main.cpp
Dec. 10, 2016

Implementation of the console for the Expression Evaluator to allow for user input

*/

#include "expression_evaluator.hpp"
#include "function.hpp"
#include "real.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <regex>
#include <sstream>
using namespace std;

int main() {
	
		cout << "Expression Evaluator, (c) 2016 Kristian Kerrigan\n";
		ExpressionEvaluator ee;
		unsigned realPrecision = 10;

		for (unsigned count = 0; ; ++count) {
			try {
				cout << "> ";
				string command;
				if (!getline(cin, command) || command.empty())
					break;

				cout << "[" << count << "] = " << ee.evaluate(command) << endl;
			}
			catch (exception ex) {
				cout << ex.what() << endl;
			}
			catch (...) {}

		}
}

/*=============================================================

Revision History
Version 1.0.0: 2016-10-29
Added help command.

Version 0.1.0: 2014-11-27
Added: setp to set the real number precision.

Version 0.0.1: 2012-11-13
C++ 11 cleanup

Version 0.0.0: 2010-11-23
Alpha release.

=============================================================

Copyright Garth Santor/Trinh Han

The copyright to the computer program(s) herein
is the property of Garth Santor/Trinh Han of Canada.
The program(s) may be used and/or copied only with
the written permission of Garth Santor/Trinh Han
or in accordance with the terms and conditions
stipulated in the agreement/contract under which
the program(s) have been supplied.
=============================================================*/
