/**
Kristian Kerrigan
function.cpp
Nov. 27, 2016
Revised: Dec. 10, 2016

Implementation of the Function class methods
Revision: Implementation of the perform() method for each token in function.hpp

*/
#include <boost/multiprecision/cpp_dec_float.hpp>
#include "operator.hpp"
#include "function.hpp"
#include "integer.hpp"
#include "real.hpp"
#include "boolean.hpp"
using namespace std;

//Power functions
//Two Integer values
Integer::value_type pow(Integer::value_type base, Integer::value_type exp) {
	Integer::value_type value = base;
	//Integer::value_type absExp = abs(exp);
	for (unsigned i = 1; i < exp; ++i)
		value *= base;
	return value;
}


//negative exponents
Real::value_type negPow(Integer::value_type a, Integer::value_type b) {
	Real::value_type result = (Real::value_type)a;
	Integer::value_type absExp = abs(b);
	for (unsigned i = 1; i < absExp; ++i) {
		result *= (Real::value_type)a;
	}
	return 1 / result;
}


/** One-arg functions */
//Abs
Operand::pointer_type Abs::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Integer>(boost::multiprecision::abs(convert<Integer>(operandList[0])->get_value()));
	else if (is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Integer>(1);
		else
			return make_operand<Integer>(0);
	}
	else
		return make_operand<Real>(boost::multiprecision::abs(convert<Real>(operandList[0])->get_value()));
}

//Arccos
Operand::pointer_type Arccos::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::acos((Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if(is<Real>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::acos(convert<Real>(operandList[0])->get_value()));
	else if (is<Boolean>(operandList[0])) {
		if(convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Real>(boost::multiprecision::acos((Real::value_type)1.0));
		else
			return make_operand<Real>(boost::multiprecision::acos((Real::value_type)0.0));
	}
	else		
		throw exception("Error: Cannot perform: <Arccos>");
}

//Arcsin
Operand::pointer_type Arcsin::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::asin((Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if (is<Real>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::asin(convert<Real>(operandList[0])->get_value()));
	else if (is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Real>(boost::multiprecision::asin((Real::value_type)1.0));
		else
			return make_operand<Real>(boost::multiprecision::asin((Real::value_type)0.0));
	}
	else
		throw exception("Error: Cannot perform: <Arcsin>");
}

//Arctan
Operand::pointer_type Arctan::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::atan((Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if (is<Real>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::atan(convert<Real>(operandList[0])->get_value()));
	else if (is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Real>(boost::multiprecision::atan((Real::value_type)1.0));
		else
			return make_operand<Real>(boost::multiprecision::atan((Real::value_type)0.0));
	}
	else
		throw exception("Error: Cannot perform: <Arctan>");
}

//Ceil
Operand::pointer_type Ceil::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::ceil((Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if (is<Real>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::ceil(convert<Real>(operandList[0])->get_value()));
	else if (is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Real>(boost::multiprecision::ceil((Real::value_type)1.0));
		else
			return make_operand<Real>(boost::multiprecision::ceil((Real::value_type)0.0));
	}
	else
		throw exception("Error: Cannot perform: <Ceil>");
}

//Cos
Operand::pointer_type Cos::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::cos((Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if (is<Real>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::cos(convert<Real>(operandList[0])->get_value()));
	else if (is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Real>(boost::multiprecision::cos((Real::value_type)1.0));
		else
			return make_operand<Real>(boost::multiprecision::cos((Real::value_type)0.0));
	}
	else
		throw exception("Error: Cannot perform: <Cosine>");
}

//Exp
Operand::pointer_type Exp::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::exp((Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if (is<Real>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::exp(convert<Real>(operandList[0])->get_value()));
	else if (is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Real>(boost::multiprecision::exp((Real::value_type)1.0));
		else
			return make_operand<Real>(boost::multiprecision::exp((Real::value_type)0.0));
	}
	else
		throw exception("Error: Cannot perform: <Exp>");
}

//Floor
Operand::pointer_type Floor::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::floor((Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if (is<Real>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::floor(convert<Real>(operandList[0])->get_value()));
	else if (is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Real>(boost::multiprecision::floor((Real::value_type)1.0));
		else
			return make_operand<Real>(floor(0.0));
	}
	else
		throw exception("Error: Cannot perform: <Floor>");
}

//Lb
Operand::pointer_type Lb::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Real>(log2(static_cast<double>((Real::value_type)convert<Integer>(operandList[0])->get_value())));
	else if(is<Real>(operandList[0]))
		return make_operand<Real>(log2(static_cast<double>(convert<Real>(operandList[0])->get_value())));
	else if (is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Real>(log2(static_cast<double>(1)));
		else
			return make_operand<Real>(log2(static_cast<double>(0)));
	}
	else
		throw exception("Error: Cannot perform: <Lb>");
}

//Ln
Operand::pointer_type Ln::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::log((Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if (is<Real>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::log(convert<Real>(operandList[0])->get_value()));
	else if (is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Real>(boost::multiprecision::log((Real::value_type)1.0));
		else
			return make_operand<Real>(boost::multiprecision::log(Real::value_type(0.0)));
	}
	else
		throw exception("Error: Cannot perform: <Ln>");
}

//Sin
Operand::pointer_type Sin::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::sin((Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if (is<Real>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::sin(convert<Real>(operandList[0])->get_value()));
	else if (is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Real>(boost::multiprecision::sin((Real::value_type)1.0));
		else
			return make_operand<Real>(boost::multiprecision::sin((Real::value_type)0.0));
	}
	else
		throw exception("Error: Cannot perform: <Sine>");
}

//Log
Operand::pointer_type Log::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::log10((Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if (is<Real>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::log10(convert<Real>(operandList[0])->get_value()));
	else if (is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Real>(boost::multiprecision::log10((Real::value_type)1.0));
		else
			return make_operand<Real>(boost::multiprecision::log10((Real::value_type)0.0));
	}
	else
		throw exception("Error: Cannot perform: <Log>");
}

//Sqrt
Operand::pointer_type Sqrt::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::sqrt((Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if (is<Real>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::sqrt(convert<Real>(operandList[0])->get_value()));
	else if (is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Real>(boost::multiprecision::sqrt((Real::value_type)1.0));
		else
			return make_operand<Real>(boost::multiprecision::sqrt((Real::value_type)0.0));
	}
	else
		throw exception("Error: Cannot perform: <Sqrt>");
}

//Tan
Operand::pointer_type Tan::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::tan((Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if (is<Real>(operandList[0]))
		return make_operand<Real>(boost::multiprecision::tan(convert<Real>(operandList[0])->get_value()));
	else if (is<Boolean>(operandList[0])) {
		if (convert<Boolean>(operandList[0])->get_value() == true)
			return make_operand<Real>(boost::multiprecision::tan((Real::value_type)1.0));
		else
			return make_operand<Real>(boost::multiprecision::tan((Real::value_type)0.0));
	}
	else
		throw exception("Error: Cannot perform: <Tangent>");
}

/** Two-arg functions */
//Max
Operand::pointer_type Max::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Integer>(boost::multiprecision::max(convert<Integer>(operandList[0])->get_value(), convert<Integer>(operandList[1])->get_value()));
	else if (is<Real>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::max(convert<Real>(operandList[0])->get_value(), (Real::value_type)convert<Integer>(operandList[1])->get_value()));
	else if (is<Integer>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::max((Real::value_type)convert<Integer>(operandList[0])->get_value(), convert<Real>(operandList[1])->get_value()));
	else if (is<Real>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::max(convert<Real>(operandList[0])->get_value(), convert<Real>(operandList[1])->get_value()));
	else
		throw exception("Error: Cannot perform: <Max>");
}

//Min
Operand::pointer_type Min::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Integer>(boost::multiprecision::min(convert<Integer>(operandList[0])->get_value(), convert<Integer>(operandList[1])->get_value()));
	else if (is<Real>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::min(convert<Real>(operandList[0])->get_value(), (Real::value_type)convert<Integer>(operandList[1])->get_value()));
	else if (is<Integer>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::min((Real::value_type)convert<Integer>(operandList[0])->get_value(), convert<Real>(operandList[1])->get_value()));
	else if (is<Real>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::min(convert<Real>(operandList[0])->get_value(), convert<Real>(operandList[1])->get_value()));
	else
		throw exception("Error: Cannot perform: <Min>");
}

//Arctan2
Operand::pointer_type Arctan2::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Real>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::atan2(convert<Real>(operandList[1])->get_value(), convert<Real>(operandList[0])->get_value()));
	else if(is<Real>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::atan2((Real::value_type)convert<Integer>(operandList[1])->get_value(), convert<Real>(operandList[0])->get_value()));
	else if(is<Integer>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::atan2(convert<Real>(operandList[1])->get_value(), (Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else
		throw exception("Error: Cannot perform: <Arctan2>");
}

//Pow
Operand::pointer_type Pow::perform(valueStack& valStk) {
	TokenList operandList;
	
	operandList.push_back(valStk.top());
	valStk.pop();
	operandList.push_back(valStk.top());
	valStk.pop();

	if (is<Integer>(operandList[0]) && is<Integer>(operandList[1])) {
		if (convert<Integer>(operandList[0])->get_value() > 0)
			return make_operand<Integer>(pow(convert<Integer>(operandList[1])->get_value(), convert<Integer>(operandList[0])->get_value()));
		else
			return make_operand<Real>(negPow(convert<Integer>(operandList[1])->get_value(), convert<Integer>(operandList[0])->get_value()));

	}
	else if (is<Integer>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::pow(convert<Real>(operandList[1])->get_value(), (Real::value_type)convert<Integer>(operandList[0])->get_value()));
	else if (is<Real>(operandList[0]) && is<Integer>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::pow((Real::value_type)convert<Integer>(operandList[1])->get_value(), convert<Real>(operandList[0])->get_value()));

	else if (is<Real>(operandList[0]) && is<Real>(operandList[1]))
		return make_operand<Real>(boost::multiprecision::pow(convert<Real>(operandList[1])->get_value(), convert<Real>(operandList[0])->get_value()));
	else
		throw exception("Error: Cannot perfrom: <Pow>");

}


/*=============================================================

Revision History

Version 0.0.1: 2012-11-13
C++ 11 cleanup

Version 0.0.0: 2009-12-31
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
