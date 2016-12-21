#if !defined(GUARD_boolean_hpp20091126_)
#define GUARD_boolean_hpp20091126_

/**
Kristian Kerrigan
boolean.hpp
Nov. 27, 2016

Implementation of the Boolean class and the tokens for true and false

*/

#include "operand.hpp"


	/** Boolean token. */
class Boolean : public Operand {
public:
	using value_type = bool;
	DEF_POINTER_TYPE(Boolean)
private:
	value_type	value_;
public:
	Boolean(value_type value = 0)
		: value_(value) { }

	virtual value_type		get_value() const { return value_; }
	string_type				to_string() const;

	DEF_IS_CONVERTABLE_FROM(Boolean)
};

class True : public Boolean {
public:
	value_type get_value() const { return true; }
	DEF_IS_CONVERTABLE_FROM(True)
};

class False : public Boolean {
public:
	value_type get_value() const { return false; }
	DEF_IS_CONVERTABLE_FROM(False)
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
#endif // GUARD_boolean_hpp20091126_
