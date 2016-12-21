#if !defined(GUARD_function_hpp20091126_)
#define GUARD_function_hpp20091126_

/**
Kristian Kerrigan
function.hpp
Nov. 27, 2016
Revised: Dec. 10, 2016

Implementation of the Function class and the individual Tokens for each function
Revision: added static method clear() to the Result token

*/


#include "operation.hpp"
#include "integer.hpp"
#include <vector>

/** Function token base class. */
class Function : public Operation { };

		/** One argument function token base class. */
		class OneArgFunction : public Function {
		public:
			virtual unsigned number_of_args() const override { return 1; }
		};

				/** Absolute value function token. */
				class Abs : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Abs)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Arc cosine function token*/
				class Arccos : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Arccos)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Arc sin function token*/
				class Arcsin : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Arcsin)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Arc tan function token */
				class Arctan : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Arctan)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Ceiling function token */
				class Ceil : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Ceil)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Cosine function token */
				class Cos : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Cos)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Exponent function token */
				class Exp : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Exp)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Floor function token */
				class Floor : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Floor)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Lb function token */
				class Lb : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Lb)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Ln function token */
				class Ln : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Ln)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Log function token */
				class Log : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Log)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Sine function token */
				class Sin : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Sin)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Square root function token */
				class Sqrt : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Sqrt)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Tangent function token */
				class Tan : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Tan)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Result function token */
				class Result : public OneArgFunction {
				public:
					DEF_IS_CONVERTABLE_FROM(Result)
				    static void clear();
				};

				/** Binary function token */
				class Binary : public OneArgFunction {
					DEF_IS_CONVERTABLE_FROM(Binary)
					//Operand::pointer_type perform(valueStack& valStk);
				};
		
				
		/** Two argument function token base class. */
		class TwoArgFunction : public Function {
		public:
			virtual unsigned number_of_args() const override { return 2; }
			};
		        
				/** Max function token */
				class Max : public TwoArgFunction {
					DEF_IS_CONVERTABLE_FROM(Max)
				    Operand::pointer_type perform(valueStack& valStk);
				};

				/** Min function token */
				class Min : public TwoArgFunction {
					DEF_IS_CONVERTABLE_FROM(Min)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Arctan2 function token */
				class Arctan2 : public TwoArgFunction {
					DEF_IS_CONVERTABLE_FROM(Arctan2)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** Pow function token */
				class Pow : public TwoArgFunction {
					DEF_IS_CONVERTABLE_FROM(Pow)
					Operand::pointer_type perform(valueStack& valStk);
				};
			


/*=============================================================

Revision History

Version 1.0.0: 2016-11-02
Added 'override' keyword where appropriate.

Version 0.0.2: 2014-10-30
Removed binary function

Version 0.0.1: 2012-11-13
C++ 11 cleanup

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
#endif // GUARD_function_hpp20091126_
