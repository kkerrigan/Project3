/** 
Kristian Kerrigan 
parser.cpp
Nov. 27, 2016

Implementation of the shunting yard algorithm in order to change the Token pointers from infix notation to postfix notation

*/

#include "parser.hpp"
#include "function.hpp"
#include "operand.hpp"
#include "operator.hpp"
#include "pseudo_operation.hpp"
#include <stack>
using namespace std;

//Implementation of the Shunting Yard algorithm using the tokenizedExpression from Tokenizer.tokenize()
TokenList Parser::parse(TokenList const& infixTokens) {
	std::stack<Token::pointer_type>opStack;
	TokenList queue;

	if (!infixTokens.empty()) {
		for (auto current = infixTokens.cbegin(); current != infixTokens.cend(); ++current) {
			//if it's a Operand (Integer, Real, Boolean)
			if (is<Operand>(*current)) {
				queue.push_back(*current);
			}
			//If the token is a Function
			else if (is<Function>(*current))
				opStack.push(*current);
			//If the token is an argument separator
			else if (is<ArgumentSeparator>(*current)) {
				while (!is<LeftParenthesis>(opStack.top())) {
					queue.push_back(opStack.top());
					opStack.top();
				}
			}
			//If the token is a Left bracket
			else if (is<LeftParenthesis>(*current))
				opStack.push(*current);
			
			//If the token is a Right bracket 
			else if (is<RightParenthesis>(*current)) {
				while (!is<LeftParenthesis>(opStack.top())) {
					queue.push_back(opStack.top());
					opStack.pop();
				}
				//no matching left bracket
				if (opStack.empty()) {
					throw exception("Right paraenthesis has no matching left paraenthesis");
				}
				opStack.pop();
				if (!opStack.empty() && is<Function>(opStack.top())) {
					queue.push_back(opStack.top());
					opStack.pop();
				}
			}
			//If the token is an Operator 
			else if (is<Operator>(*current)) {
				while (!opStack.empty()) {
					if (!is<Operator>(opStack.top()))
						break;
					if (is<NAssocOperator>(*current))
						break;
					if (is<LAssocOperator>(*current)
						&& (convert<Operator>(*current)->get_precedence() > convert<Operator>(opStack.top())->get_precedence()))
						break;
					if (is<RAssocOperator>(*current)
						&& (convert<Operator>(*current)->get_precedence() >= convert<Operator>(opStack.top())->get_precedence()))
						break;

					queue.push_back(opStack.top());
					opStack.pop();
				}
				opStack.push(*current);
			}
			//Token is invalid
			else {
				throw exception("Unknown token");
			}
		}
		 //Emptying the stack and pushing to the queue
		while (!opStack.empty()) {
			//no match left bracket
			if (is<LeftParenthesis>(opStack.top())) {
				throw exception("Missing right-parenthesis");
			}
			queue.push_back(opStack.top());
			opStack.pop();
		}
	}
	return queue;
}


/*=============================================================

Revision History
Version 1.0.0: 2014-10-31
Visual C++ 2013

Version 0.0.1: 2012-11-13
C++ 11 cleanup

Version 0.0.0: 2009-12-02
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
