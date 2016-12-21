/**
Kristian Kerrigan
boolean.cpp
Nov. 27, 2016
Revised: Dec. 10, 2016

Implementation of the Boolean class methods and the implementation of perform() for each 
Relational and Binary Logic token from Operator.hpp

*/
#include <vector>
#include "operator.hpp"
#include "integer.hpp"
#include "real.hpp"
#include "boolean.hpp"
using namespace std;

Boolean::string_type Boolean::to_string() const {
	ostringstream oss;
	oss << boolalpha << get_value();
	string boolVal = oss.str();
	boolVal[0] = tolower(boolVal[0]);

	return boolVal;
}

/** Relational Operators */
Operand::pointer_type Equality::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Boolean>(operandList[1]) && is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[1])->get_value() == convert<Boolean>(operandList[0])->get_value())
			return make_operand<Boolean>(true);
		else
			return make_operand<Boolean>(false);
	}
	else {
		if (is<Integer>(operandList[1]) && is<Integer>(operandList[0])) {
			if (convert<Integer>(operandList[1])->get_value() == convert<Integer>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Real>(operandList[1]) && is<Real>(operandList[0])) {
			if (convert<Real>(operandList[1])->get_value() == convert<Real>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Real>(operandList[1]) && is<Integer>(operandList[0])) {
			if (convert<Real>(operandList[1])->get_value() == (Real::value_type)convert<Integer>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Integer>(operandList[1]) && is<Real>(operandList[0])) {
			if ((Real::value_type)convert<Integer>(operandList[1])->get_value() == convert<Real>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else
			throw exception("Cannot convert");
	}
}

//Inequality
Operand::pointer_type Inequality::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Boolean>(operandList[1]) && is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[1])->get_value() != convert<Boolean>(operandList[0])->get_value())
			return make_operand<Boolean>(true);
		else
			return make_operand<Boolean>(false);
	}
	else {
		if (is<Integer>(operandList[1]) && is<Integer>(operandList[0])) {
			if (convert<Integer>(operandList[1])->get_value() != convert<Integer>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Real>(operandList[1]) && is<Real>(operandList[0])) {
			if (convert<Real>(operandList[1])->get_value() != convert<Real>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Real>(operandList[1]) && is<Integer>(operandList[0])) {
			if (convert<Real>(operandList[1])->get_value() != (Real::value_type)convert<Integer>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Integer>(operandList[1]) && is<Real>(operandList[0])) {
			if ((Real::value_type)convert<Integer>(operandList[1])->get_value() != convert<Real>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else
			throw exception("Cannot convert");
	}
}

//Less than
Operand::pointer_type Less::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Boolean>(operandList[1]) && is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[1])->get_value() < convert<Boolean>(operandList[0])->get_value())
			return make_operand<Boolean>(true);
		else
			return make_operand<Boolean>(false);
	}
	else {
		if (is<Integer>(operandList[1]) && is<Integer>(operandList[0])) {
			if (convert<Integer>(operandList[1])->get_value() < convert<Integer>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Real>(operandList[1]) && is<Real>(operandList[0])) {
			if (convert<Real>(operandList[1])->get_value() < convert<Real>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Real>(operandList[1]) && is<Integer>(operandList[0])) {
			if (convert<Real>(operandList[1])->get_value() < (Real::value_type)convert<Integer>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Integer>(operandList[1]) && is<Real>(operandList[0])) {
			if ((Real::value_type)convert<Integer>(operandList[1])->get_value() < convert<Real>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else
			throw exception("Cannot convert");
	}
}

//Less than or equal
Operand::pointer_type LessEqual::perform(valueStack& valStk){
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Boolean>(operandList[1]) && is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[1])->get_value() <= convert<Boolean>(operandList[0])->get_value())
			return make_operand<Boolean>(true);
		else
			return make_operand<Boolean>(false);
	}
	else {
		if (is<Integer>(operandList[1]) && is<Integer>(operandList[0])) {
			if (convert<Integer>(operandList[1])->get_value() <= convert<Integer>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Real>(operandList[1]) && is<Real>(operandList[0])) {
			if (convert<Real>(operandList[1])->get_value() <= convert<Real>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Real>(operandList[1]) && is<Integer>(operandList[0])) {
			if (convert<Real>(operandList[1])->get_value() <= (Real::value_type)convert<Integer>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Integer>(operandList[1]) && is<Real>(operandList[0])) {
			if ((Real::value_type)convert<Integer>(operandList[1])->get_value() <= convert<Real>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else
			throw exception("Cannot convert");
	}
}

//Greater than 
Operand::pointer_type Greater::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Boolean>(operandList[1]) && is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[1])->get_value() > convert<Boolean>(operandList[0])->get_value())
			return make_operand<Boolean>(true);
		else
			return make_operand<Boolean>(false);
	}
	else {
		if (is<Integer>(operandList[1]) && is<Integer>(operandList[0])) {
			if (convert<Integer>(operandList[1])->get_value() > convert<Integer>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Real>(operandList[1]) && is<Real>(operandList[0])) {
			if (convert<Real>(operandList[1])->get_value() > convert<Real>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Real>(operandList[1]) && is<Integer>(operandList[0])) {
			if (convert<Real>(operandList[1])->get_value() > (Real::value_type)convert<Integer>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Integer>(operandList[1]) && is<Real>(operandList[0])) {
			if ((Real::value_type)convert<Integer>(operandList[1])->get_value() > convert<Real>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else
			throw exception("Cannot convert");
	}
}

//Greater than or equal
Operand::pointer_type GreaterEqual::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Boolean>(operandList[1]) && is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[1])->get_value() >= convert<Boolean>(operandList[0])->get_value())
			return make_operand<Boolean>(true);
		else
			return make_operand<Boolean>(false);
	}
	else {
		if (is<Integer>(operandList[1]) && is<Integer>(operandList[0])) {
			if (convert<Integer>(operandList[1])->get_value() >= convert<Integer>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Real>(operandList[1]) && is<Real>(operandList[0])) {
			if (convert<Real>(operandList[1])->get_value() >= convert<Real>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Real>(operandList[1]) && is<Integer>(operandList[0])) {
			if (convert<Real>(operandList[1])->get_value() >= (Real::value_type)convert<Integer>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else if (is<Integer>(operandList[1]) && is<Real>(operandList[0])) {
			if ((Real::value_type)convert<Integer>(operandList[1])->get_value() >= convert<Real>(operandList[0])->get_value())
				return make_operand<Boolean>(true);
			else
				return make_operand<Boolean>(false);
		}
		else
			throw exception("Cannot convert");
	}
}


/** Binary Logical Operators */
//AND
Operand::pointer_type And::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Boolean>(operandList[0]) && is<Boolean>(operandList[1])) {
		if (convert<Boolean>(operandList[1])->get_value() == true && convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Boolean>(true);
		else if (convert<Boolean>(operandList[1])->get_value() == true && convert<Boolean>(operandList[0])->get_value() == false)
			return make_operand<Boolean>(false);
		else if (convert<Boolean>(operandList[1])->get_value() == false && convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Boolean>(false);
		else
			return make_operand<Boolean>(false);
	}
	else
		throw exception("Error: Cannot perform: <And>");
}

//Nand
Operand::pointer_type Nand::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Boolean>(operandList[0]) && is<Boolean>(operandList[1])) {
		if (convert<Boolean>(operandList[1])->get_value() == true && convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Boolean>(false);
		else if (convert<Boolean>(operandList[1])->get_value() == true && convert<Boolean>(operandList[0])->get_value() == false)
			return make_operand<Boolean>(true);
		else if (convert<Boolean>(operandList[1])->get_value() == false && convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Boolean>(true);
		else
			return make_operand<Boolean>(true);
	}
	else
		throw exception("Error: Cannot perform: <Nand>");
}

//Or
Operand::pointer_type Or::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Boolean>(operandList[0]) && is<Boolean>(operandList[1])) {
		if (convert<Boolean>(operandList[1])->get_value() == true && convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Boolean>(true);
		else if (convert<Boolean>(operandList[1])->get_value() == true && convert<Boolean>(operandList[0])->get_value() == false)
			return make_operand<Boolean>(true);
		else if (convert<Boolean>(operandList[1])->get_value() == false && convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Boolean>(true);
		else
			return make_operand<Boolean>(false);
	}
	else
		throw exception("Error: Cannot perform: <Or>");
}

//Nor
Operand::pointer_type Nor::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Boolean>(operandList[0]) && is<Boolean>(operandList[1])) {
		if (convert<Boolean>(operandList[1])->get_value() == true && convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Boolean>(false);
		else if (convert<Boolean>(operandList[1])->get_value() == true && convert<Boolean>(operandList[0])->get_value() == false)
			return make_operand<Boolean>(false);
		else if (convert<Boolean>(operandList[1])->get_value() == false && convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Boolean>(false);
		else
			return make_operand<Boolean>(true);
	}
	else
		throw exception("Error: Cannot perform: <Nor>");
}

//Xor
Operand::pointer_type Xor::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Boolean>(operandList[0]) && is<Boolean>(operandList[1])) {
		if (convert<Boolean>(operandList[1])->get_value() == true && convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Boolean>(false);
		else if (convert<Boolean>(operandList[1])->get_value() == true && convert<Boolean>(operandList[0])->get_value() == false)
			return make_operand<Boolean>(true);
		else if (convert<Boolean>(operandList[1])->get_value() == false && convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Boolean>(true);
		else
			return make_operand<Boolean>(false);
	}
	else
		throw exception("Error: Cannot perform: <Xor>");
}

//Xnor
Operand::pointer_type Xnor::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Boolean>(operandList[0]) && is<Boolean>(operandList[1])) {
		if (convert<Boolean>(operandList[1])->get_value() == true && convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Boolean>(true);
		else if (convert<Boolean>(operandList[1])->get_value() == true && convert<Boolean>(operandList[0])->get_value() == false)
			return make_operand<Boolean>(false);
		else if (convert<Boolean>(operandList[1])->get_value() == false && convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Boolean>(false);
		else
			return make_operand<Boolean>(true);
	}
	else
		throw exception("Error: Cannot perform: <Xnor>");
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
