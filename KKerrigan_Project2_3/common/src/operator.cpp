/**
Kristian Kerrigan
operator.cpp
Nov. 27, 2016
Revised: Dec. 10, 2016

Implementation of the Operator class methods
Revision: Implementation of all the perform() methods for non-boolean and non-relational binary operator
		  as well as unary operator tokens

*/
#include <boost/multiprecision/cpp_dec_float.hpp>

#include <vector>
#include "operator.hpp"
#include "integer.hpp"
#include "real.hpp"
#include "boolean.hpp"
using namespace std;

//Power functions
//Two Integer values
Integer::value_type power(Integer::value_type base, Integer::value_type exp) {
	if (exp.is_zero())
		return 1;
	auto x = power(base, exp / 2);
	if (exp % 2 == 0)
		return x*x;
	else
		return base*x*x;
}

//negative exponents
Real::value_type negPower(Integer::value_type a, Integer::value_type b) {
	Real::value_type result = (Real::value_type)a;
	Integer::value_type absExp = abs(b);
	for (unsigned i = 1; i < absExp; ++i) {
		result *= (Real::value_type)a;
	}
	return 1 / result;
}

/** Unary Operators*/
//Factorial
Operand::pointer_type Factorial::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0])) {
		Integer::value_type value = 1;
		for (unsigned i = 1; i <= convert<Integer>(operandList[0])->get_value(); ++i)
			value *= i;
		return make_operand<Integer>(value);
	}
	else
		throw exception("Error: Cannot perform: <Factorial>");
}

//Negation
Operand::pointer_type  Negation::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Integer>(-convert<Integer>(operandList[0])->get_value());
	else if (is<Real>(operandList[0]))
		return make_operand<Real>(-convert<Real>(operandList[0])->get_value());
	else
		throw exception("Error: Cannot perform: <Negation>");
}

//Identity
Operand::pointer_type Identity::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Integer>(+convert<Integer>(operandList[0])->get_value());
	else if (is<Real>(operandList[0]))
		return make_operand<Real>(+convert<Real>(operandList[0])->get_value());
	else
		throw exception("Error: Cannot perform: <Identity>");
}

//Logical Not
Operand::pointer_type Not::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Boolean>(operandList[0]))
		return make_operand<Boolean>(!convert<Boolean>(operandList[0])->get_value());
	else
		throw exception("Error: Cannot perform: <Not>");
}


/** Binary Operators */
//Addition
Operand::pointer_type Addition::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Integer>(convert<Integer>(operandList[1])->get_value() + convert<Integer>(operandList[0])->get_value());
	else if (is<Integer>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(convert<Real>(operandList[1])->get_value() + (Real::value_type)convert<Integer>(operandList[0])->get_value());
	else if (is<Real>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Real>((Real::value_type)convert<Integer>(operandList[1])->get_value() + convert<Real>(operandList[0])->get_value());
	else if (is<Real>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(convert<Real>(operandList[1])->get_value() + convert<Real>(operandList[0])->get_value());
	else if (is<Boolean>(operandList[0]) && is<Boolean>(operandList[1])) {
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
		throw exception("Error: Cannot perfrom: <Addition>");
}

//Subtraction
Operand::pointer_type Subtraction::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Integer>(convert<Integer>(operandList[1])->get_value() - convert<Integer>(operandList[0])->get_value());
	else if (is<Integer>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(convert<Real>(operandList[1])->get_value() - (Real::value_type)convert<Integer>(operandList[0])->get_value());
	else if (is<Real>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Real>((Real::value_type)convert<Integer>(operandList[1])->get_value() - convert<Real>(operandList[0])->get_value());
	else if (is<Real>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(convert<Real>(operandList[1])->get_value() - convert<Real>(operandList[0])->get_value());
	else
		throw exception("Error: Cannot perfrom: <Subtraction>");
}

//Multiplication
Operand::pointer_type Multiplication::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Integer>(convert<Integer>(operandList[1])->get_value() * convert<Integer>(operandList[0])->get_value());
	else if (is<Integer>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(convert<Real>(operandList[1])->get_value() * (Real::value_type)convert<Integer>(operandList[0])->get_value());
	else if (is<Real>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Real>((Real::value_type)convert<Integer>(operandList[1])->get_value() * convert<Real>(operandList[0])->get_value());
	else if (is<Real>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(convert<Real>(operandList[1])->get_value() * convert<Real>(operandList[0])->get_value());
	else if (is<Boolean>(operandList[0]) && is<Boolean>(operandList[1])) {
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
		throw exception("Error: Cannot perfrom: <Multiplication>");
}

//Division
Operand::pointer_type Division::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Integer>(convert<Integer>(operandList[1])->get_value() / convert<Integer>(operandList[0])->get_value());
	else if (is<Integer>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(convert<Real>(operandList[1])->get_value() / (Real::value_type)convert<Integer>(operandList[0])->get_value());
	else if (is<Real>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Real>((Real::value_type)convert<Integer>(operandList[1])->get_value() / convert<Real>(operandList[0])->get_value());
	else if (is<Real>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(convert<Real>(operandList[1])->get_value() / convert<Real>(operandList[0])->get_value());
	else
		throw exception("Error: Cannot perfrom: <Division>");
}

//Modulus
Operand::pointer_type Modulus::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Integer>(convert<Integer>(operandList[1])->get_value() % convert<Integer>(operandList[0])->get_value());
	else
		throw exception("Error: Cannot perform: <Modulus>");
}

//Power
Operand::pointer_type Power::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]) && is<Integer>(operandList[1])) {
		if (convert<Integer>(operandList[0])->get_value() > 0)
			return make_operand<Integer>(power(convert<Integer>(operandList[1])->get_value(), convert<Integer>(operandList[0])->get_value()));
		else
			return make_operand<Real>(negPower(convert<Integer>(operandList[1])->get_value(), convert<Integer>(operandList[0])->get_value()));

	}
	else if (is<Integer>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::pow(convert<Real>(operandList[1])->get_value(), (Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if (is<Real>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::pow((Real::value_type)convert<Integer>(operandList[1])->get_value(), convert<Real>(operandList[0])->get_value()));

	else if (is<Real>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::pow(convert<Real>(operandList[1])->get_value(), convert<Real>(operandList[0])->get_value()));
	else
		throw exception("Error: Cannot perform: <Power>");
		
}


/*=============================================================

Revision History

Version 0.1.1: 2012-11-13
C++ 11 cleanup

Version 0.1.0: 2010-11-08
Added exception for assignment to a non-variable.

Version 0.0.0: 2009-12-14
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
