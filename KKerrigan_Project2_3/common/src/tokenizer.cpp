/**
Kristian Kerrigan
tokenizer.cpp
Nov. 27, 2016

Implementation of the Tokenizer class methods
_get_number() will take the characters from the string and return either an Integer or Real Token

_get_identifier will take the character string and check the keywords_ library and return a Function token if it
finds a match, or create a Variable token

tokenize will parse through the input string and create the appropriate tokens depending on the character it reads
*/

#include "tokenizer.hpp"
#include "boolean.hpp"
#include "function.hpp"
#include "integer.hpp"
#include "operator.hpp"
#include "pseudo_operation.hpp"
#include "real.hpp"
#include "variable.hpp"

#include <exception>
#include <limits>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

/** Default constructor loads the keyword dictionary. */
Tokenizer::Tokenizer() {
	keywords_["abs"]     = keywords_["Abs"]		= keywords_["ABS"]		= make<Abs>();
	keywords_["arccos"]	 = keywords_["Arccos"]	= keywords_["ARCCOS"]	= make<Arccos>();
	keywords_["arcsin"]  = keywords_["Arcsin"]	= keywords_["ARCSIN"]	= make<Arcsin>();
	keywords_["arctan"]  = keywords_["Arctan"]	= keywords_["ARCTAN"]	= make<Arctan>();
	keywords_["ceil"]    = keywords_["Ceil"]	= keywords_["CEIL"]		= make<Ceil>();
	keywords_["cos"]     = keywords_["Cos"]		= keywords_["COS"]		= make<Cos>();
	keywords_["exp"]     = keywords_["Exp"]		= keywords_["EXP"]		= make<Exp>();
	keywords_["floor"]   = keywords_["Floor"]	= keywords_["FLOOR"]	= make<Floor>();
	keywords_["lb"]      = keywords_["Lb"]		= keywords_["LB"]		= make<Lb>();
	keywords_["ln"]      = keywords_["Ln"]		= keywords_["LN"]		= make<Ln>();
	keywords_["log"]     = keywords_["Log"]		= keywords_["LOG"]		= make<Log>();
	keywords_["sin"]     = keywords_["Sin"]		= keywords_["SIN"]		= make<Sin>();
	keywords_["sqrt"]    = keywords_["Sqrt"]	= keywords_["SQRT"]		= make<Sqrt>();
	keywords_["tan"]     = keywords_["Tan"]		= keywords_["TAN"]		= make<Tan>();
	keywords_["result"]  = keywords_["Result"]	= keywords_["RESULT"]	= make<Result>();
	keywords_["binary"]  = keywords_["Binary"]	= keywords_["BINARY"]	= make<Binary>();
	keywords_["max"]     = keywords_["Max"]		= keywords_["MAX"]		= make<Max>();
	keywords_["min"]     = keywords_["Min"]		= keywords_["MIN"]		= make<Min>();
	keywords_["arctan2"] = keywords_["Arctan2"] = keywords_["ARCTAN2"]	= make<Arctan2>();
	keywords_["mod"]     = keywords_["Mod"]		= keywords_["MOD"]		= make<Modulus>();
	keywords_["pow"]	 = keywords_["Pow"]     = keywords_["POW"]      = make<Pow>();
	keywords_["pi"]	     = keywords_["Pi"]      = keywords_["PI"]       = make<Pi>();
	keywords_["e"]	     = keywords_["E"]                               = make<E>();
	keywords_["true"]	 = keywords_["True"]    = keywords_["TRUE"]     = make<True>();
	keywords_["false"]	 = keywords_["False"]   = keywords_["FALSE"]    = make<False>();
	keywords_["not"]	 = keywords_["Not"]     = keywords_["NOT"]      = make<Not>();
	keywords_["and"]     = keywords_["And"]     = keywords_["AND"]      = make<And>();
	keywords_["nand"]	 = keywords_["Nand"]    = keywords_["NAND"]     = make<Nand>();
	keywords_["or"]	     = keywords_["Or"]      = keywords_["OR"]       = make<Or>();
	keywords_["nor"]	 = keywords_["Nor"]     = keywords_["NOR"]      = make<Nor>();
	keywords_["xor"]	 = keywords_["Xor"]     = keywords_["XOR"]      = make<Xor>();
	keywords_["xnor"]	 = keywords_["Xnor"]    = keywords_["XNOR"]     = make<Xnor>();
}


/** Get an identifier from the expression.
	Assumes that the currentChar is pointing to a alphabetic.
	*/
Token::pointer_type Tokenizer::_get_identifier( Tokenizer::string_type::const_iterator& currentChar, Tokenizer::string_type const& expression ) {
	// accumulate identifier
	string_type ident;
	do
		ident += *currentChar++;
	while( currentChar != end(expression) && isalnum( *currentChar ) );

	// check for predefined identifier
	dictionary_type::iterator iter = keywords_.find(ident);
	if( iter != end(keywords_) )
		return iter->second;
	//not found in keywords_ so make a new Variable
	else {
		//check if variable has already been created in variables_
		iter = variables_.find(ident);
		if (iter != end(variables_))
			return iter->second;
		//variable not found in variables_ so make new Variable token
		else {
			Token::pointer_type variable = make<Variable>();
			variables_[ident] = variable;
			return variable;
		}
	}

	throw XBadCharacter(expression, currentChar - begin(expression));
}




/** Get a number token from the expression.
	@return One of BinaryInteger, Integer, or Real.
	@param currentChar [in,out] an iterator to the current character.  Assumes that the currentChar is pointing to a digit.
	@param expression [in] the expression being scanned.
*/
Token::pointer_type Tokenizer::_get_number(Tokenizer::string_type::const_iterator& currentChar, Tokenizer::string_type const& expression) {
	assert(isdigit(*currentChar) && "currentChar must pointer to a digit");
	char acc = 0;
	Integer::value_type newAc = 0; //new Interger holder
	//as long as it continues to read digits multiply the previous digit by 10 and add the value of the current
	//digit
	while (currentChar != end(expression) && isdigit(*currentChar)) {
		newAc *= 10;
		acc = *currentChar;
		newAc += atoi(&acc);
		++currentChar;
	}

	//found a decimal so must return a Real token
	if (currentChar != end(expression) && *currentChar == '.') {
		++currentChar;

		//convert to string to add each preceeding digit to
		std::string realString = static_cast<string>(newAc) + '.';

		while (currentChar != end(expression) && isdigit(*currentChar)) {
			char val = *currentChar;
			realString += val;
			++currentChar;
		}
		//return a Real token with the value that is in the converted string
		return make<Real>(Real::value_type(realString));
	}
	//no decimal was found so just return the previously created accumulated Integer
	else {
		return make<Integer>(newAc);
	}
}


/** Tokenize the expression.
	@return a TokenList containing the tokens from 'expression'. 
	@param expression [in] The expression to tokenize.
	@note Tokenizer dictionary may be updated if expression contains variables.
	@note Will throws 'BadCharacter' if the expression contains an un-tokenizable character.
	*/
TokenList Tokenizer::tokenize(string_type const& expression) {
	TokenList tokenizedExpression;
	auto currentChar = expression.cbegin();

	for(;;) 
	{
		// strip whitespace
		while( currentChar != end(expression) && isspace(*currentChar) )
			++currentChar;

		// check of end of expression
		if( currentChar == end(expression) ) break;

		// check for a number
		if( isdigit( *currentChar ) ) {
			tokenizedExpression.push_back( _get_number( currentChar, expression ) );
			continue;
		}

		//check for Operators
		if (*currentChar == '!') {
			if ((currentChar + 1) != end(expression) && *(currentChar + 1)== '=' && *(currentChar +2) !='=') {
				tokenizedExpression.push_back(make<Inequality>());
				currentChar += 2;
			}
				else {
					tokenizedExpression.push_back(make<Factorial>());
					++currentChar;
				}
				
			continue;
			}

		if (*currentChar == '+') {
			if (tokenizedExpression.size() != 0 && (is<Operand>(tokenizedExpression.back())
												 || is<RightParenthesis>(tokenizedExpression.back())
												 || is<Factorial>(tokenizedExpression.back()))) {
				tokenizedExpression.push_back(make<Addition>());
				++currentChar;
			}
			else {
				tokenizedExpression.push_back(make<Identity>());
				++currentChar;
			}
			continue;
		}
		if (*currentChar == '-') {
			if (tokenizedExpression.size() != 0 && (is<Operand>(tokenizedExpression.back()) 
												 || is<RightParenthesis>(tokenizedExpression.back())
												 || is<Factorial>(tokenizedExpression.back()))) {
				tokenizedExpression.push_back(make<Subtraction>());
				++currentChar;
			}
			else {
				tokenizedExpression.push_back(make<Negation>());
				++currentChar;
			}
			continue;
		}
		if (*currentChar == '*') {
			tokenizedExpression.push_back(make<Multiplication>());
			++currentChar;
			continue;
		}
		if (*currentChar == '/') {
			tokenizedExpression.push_back(make<Division>());
			++currentChar;
			continue;
		}
		if (*currentChar == '%') {
			tokenizedExpression.push_back(make<Modulus>());
			++currentChar;
			continue;
		}
		if (*currentChar == '#') {
			tokenizedExpression.push_back(make<Power>());
			++currentChar;
			continue;
		}

		//check for parentheses
		if (*currentChar == '(') {
			tokenizedExpression.push_back(make<LeftParenthesis>());
			++currentChar;
			continue;
		}
		if (*currentChar == ')') {
			tokenizedExpression.push_back(make<RightParenthesis>());
			++currentChar;
			continue;
		}

		//check for relational operators
		if ((currentChar + 1) != end(expression) && *currentChar == '<')
		{
			if (*(currentChar + 1) == '=')
			{
				tokenizedExpression.push_back(make<LessEqual>());
				currentChar += 2;
			}
			else
			{
				tokenizedExpression.push_back(make<Less>());
				++currentChar;
			}
			continue;
		}
		if ((currentChar + 1) != end(expression) && *currentChar == '>')
		{
			if (*(currentChar + 1) == '=')
			{
				tokenizedExpression.push_back(make<GreaterEqual>());
				currentChar += 2;
			}
			else
			{
				tokenizedExpression.push_back(make<Greater>());
				++currentChar;
			}
			continue;
		}
		//check for assignment / equality
		if (*currentChar == '=')
		{
			if ((currentChar + 1) != end(expression) && *(currentChar + 1) == '=')
			{
				tokenizedExpression.push_back(make<Equality>());
				currentChar += 2;
			}
			else
			{
				++currentChar;
				tokenizedExpression.push_back(make<Assignment>());
			}
			continue;
		}

		//argument seperator 
		if (*currentChar == ',') {
			tokenizedExpression.push_back(make<ArgumentSeparator>());
			++currentChar;
			continue;
		}

		if (isalpha(*currentChar)) {
			tokenizedExpression.push_back(_get_identifier(currentChar, expression));
			continue;
		}
		// not a recognized token
		throw XBadCharacter( expression, currentChar - begin(expression) );
	}

	return tokenizedExpression;
}

/*=============================================================

Revision History

Version 0.2.0: 2012-11-16
Added BitAnd, BitNot, BitOr, BitXOr, BitShiftLeft, BitShiftRight
Simplified CHECK_OP macros

Version 0.1.0: 2012-11-15
Replaced BadCharacter with XTokenizer, XBadCharacter, and XNumericOverflow
Added BinaryInteger, Binary <function>

Version 0.0.1: 2012-11-13
C++ 11 cleanup

Version 0.0.0: 2009-11-25
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
