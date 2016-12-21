/**
Kristian Kerrigan
token.cpp
Nov. 27, 2016

Implementation of the Token class methods

*/

#include "token.hpp"
using namespace std;


Token::string_type	Token::to_string() const { 
	return string_type("<") + string_type(typeid(*this).name()).substr(6) + string_type(">");
}


/*=============================================================

Revision History

Version 0.0.0: 2012-11-13
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
