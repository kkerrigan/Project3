#if !defined(GUARD_variable_hpp20091126_)
#define GUARD_variable_hpp20091126_

/**
Kristian Kerrigan
variable.hpp
Nov. 27, 2016

Implementation of the Variable base class 

*/


#include "operand.hpp"

class Variable : public Operand {
public:
	DEF_POINTER_TYPE(Variable)
	DEF_IS_CONVERTABLE_FROM(Variable)
	using value_type = Token::pointer_type;
private:
	value_type value_ = nullptr;
	string_type name_;
public:
	Variable(){}
	Variable(value_type value){}
	value_type get_value() const { return value_; }
	string_type to_string() const;
	void set_value(value_type v) { value_ = v; }
};




/*=============================================================

Revision History

Version 0.1.1: 2012-11-13
C++ 11 cleanup

Version 0.1.0: 2010-11-09
Switched boost::shared_ptr<> to std::shared_ptr<>.
Added TOKEN_PTR_TYPE macro.

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
#endif // GUARD_variable_hpp20091126_
