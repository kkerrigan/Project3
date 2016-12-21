/**
Kristian Kerrigan
integer.cpp
Nov. 27, 2016

Implementation of the Integer class methods

*/

#include "integer.hpp"
#include "function.hpp"
#include "operator.hpp"
#include "boolean.hpp"
#include "real.hpp"
#include <boost/lexical_cast.hpp>
#include <array>
using namespace std;


Integer::string_type Integer::to_string() const {
	return boost::lexical_cast<string_type>(get_value());
}




/*=============================================================

Revision History
Version 1.0.0: 2014-10-29
C++ 11 refactor.
Converted Integer::value_type to boost::multiprecision::cpp_int

Version 0.2.0: 2012-11-16
Added Bit operators, Pow

Version 0.1.0: 2012-11-15
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
