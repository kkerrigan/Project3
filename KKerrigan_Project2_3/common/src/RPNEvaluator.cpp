/**
Kristian Kerrigan
RPNEvaluator.cpp
Dec. 10, 2016

Implementation of the evaluate method which takes the TokenList that is now in postfix notation
and calls the neccessary perform functions

*/

#include "RPNEvaluator.hpp"
#include "integer.hpp"
#include "operation.hpp"
#include <cassert>
#include <stack>


Operand::pointer_type RPNEvaluator::evaluate(TokenList const& rpnExpression) {
	std::stack<Operand::pointer_type> operandStack;

	if (!rpnExpression.empty()) {
		for (auto current = rpnExpression.cbegin(); current != rpnExpression.cend(); ++current) {
			if (is<Operand>(*current))
				operandStack.push(convert<Operand>(*current));
			else {
				if (convert<Operation>(*current)->number_of_args() > operandStack.size())
					throw std::exception("Insufficent # operands for operation");
				else
					operandStack.push(convert<Operation>(*current)->perform(operandStack));

			}
		}
		if (operandStack.size() > 1)
			throw std::exception("Error: too many operands");
		else if (operandStack.empty())
			throw std::exception("Error: too many operations");

		return operandStack.top();
	}
	throw std::exception("Error: insufficient operands");
}

/*=============================================================

Revision History

Version 0.0.1: 2012-11-13
C++ 11 cleanup

Version 0.0.0: 2009-12-10
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
