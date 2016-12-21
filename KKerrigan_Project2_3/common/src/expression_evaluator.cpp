/**
Kristian Kerrigan
expression_evaluator.cpp
Dec. 10, 2016

Implementation of the Expression Evaluator evaluate method, which calls the three methods necessary to evaluate 
and expression:
				Tokenizer.tokenize()
				Parser.parse()
				RPNEvaluator.evaluate()

*/

#include "expression_evaluator.hpp"
#include "tokenizer.hpp"
#include "parser.hpp"
#include "RPNEvaluator.hpp"
#include "function.hpp"

#if defined(SHOW_STEPS)
#include <iostream>
#endif

void Result::clear() {

}

ExpressionEvaluator::result_type ExpressionEvaluator::evaluate( ExpressionEvaluator::expression_type const& expr ) {

	// todo: everything
	return this->rpn_.evaluate(this->parser_.parse(this->tokenizer_.tokenize(expr)));
}

/*=============================================================

Revision History

Version 0.0.0: 2010-10-31
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
