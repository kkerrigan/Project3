/**
Kristian Kerrigan
variable.cpp
Nov. 27, 2016

Implementation of the Variable class methods

*/

#include "operator.hpp"
#include "variable.hpp"
#include "integer.hpp"
#include "real.hpp"
#include "boolean.hpp"
using namespace std;

Variable::string_type Variable::to_string() const {
	return ((name_ != "") ? name_ : "Variable: null");
}

//Variable perform function
Operand::pointer_type Assignment::perform(valueStack& valStk) {
	vector<Operand::pointer_type> operandList;
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Variable>(operandList[1])) {
		if (is<Integer>(operandList[0])) {
			dynamic_pointer_cast<Variable>(operandList[1])->set_value((Operand::pointer_type)convert<Integer>(operandList[0]));
			return (operandList[1]);
		}
		else if (is<Real>(operandList[0])) {
			dynamic_pointer_cast<Variable>(operandList[1])->set_value((Operand::pointer_type)convert<Real>(operandList[0]));
			return (operandList[1]);
		}
		else if (is<Boolean>(operandList[0])) {
			dynamic_pointer_cast<Variable>(operandList[1])->set_value((Operand::pointer_type)convert<Boolean>(operandList[0]));
			return (operandList[1]);
		}
		else
			throw exception("Error: Cannot perform: <Assignment>");
	}
	else
		throw exception("Error: assignment to a non-variable.");
}


/*=============================================================

Revision History

Version 0.0.1: 2012-11-13
C++ 11 cleanup

Version 0.0.0: 2009-11-26
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
