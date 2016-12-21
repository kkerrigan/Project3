#if !defined(GUARD_operator_hpp20091126_)
#define GUARD_operator_hpp20091126_

/**
Kristian Kerrigan
operator.hpp
Nov. 27, 2016

Implementation of the Operator base class and the individual Tokens for each possible operation

*/


#include "operation.hpp"
#include "operand.hpp"


/** Operator Precedence values. */
typedef enum { 
	MIN = 0, 
	ASSIGNMENT,
	LOGOR,
	LOGXOR,
	LOGAND,
	EQUALITY,
	RELATIONAL,
	ADDITIVE, 
	MULTIPLICATIVE,  
	POWER, 
	UNARY, 
	POSTFIX, 
	MAX } precedence_type;



/** Defines a precedence category method.  Used inside a class declaration. */
#define DEF_PRECEDENCE(category)	public: precedence_type get_precedence() const override { return category; }



/** Operator token base class. */
class Operator : public Operation {
public:
	DEF_POINTER_TYPE(Operator)
	virtual precedence_type get_precedence() const = 0;
};

		/** Binary operator token base class. */
		class BinaryOperator : public Operator {
		public:
			virtual unsigned number_of_args() const override { return 2; }
		};

				/** Right-associative operator base class. */
				class RAssocOperator : public BinaryOperator {};

						/** Power token. */
						class Power : public RAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Power)
							DEF_PRECEDENCE(POWER)
							Operand::pointer_type perform(valueStack& valStk);
						};
						/** Assignment token.*/
						class Assignment : public RAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Assignment)
							DEF_PRECEDENCE(ASSIGNMENT)
							Operand::pointer_type perform(valueStack& valStk);
				       };

			   /** Left-associative operator base class. */
			   class LAssocOperator : public BinaryOperator {};
						
						/** Addition token */
						class Addition : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Addition)
							DEF_PRECEDENCE(ADDITIVE)
							Operand::pointer_type perform(valueStack& valStk);
						};
						/** Subtraction token */
						class Subtraction : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Subtraction)
							DEF_PRECEDENCE(ADDITIVE)
							Operand::pointer_type perform(valueStack& valStk);
						};
						/** Multiplication token */
						class Multiplication : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Multiplication)
							DEF_PRECEDENCE(MULTIPLICATIVE)
							Operand::pointer_type perform(valueStack& valStk);
						};
						/** Division token */
						class Division : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Division)
							DEF_PRECEDENCE(MULTIPLICATIVE)
							Operand::pointer_type perform(valueStack& valStk);
						};
						/** Modulus token*/
						class Modulus : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Modulus)
							DEF_PRECEDENCE(MULTIPLICATIVE)
							Operand::pointer_type perform(valueStack& valStk);
						};

						/** Less than token */
						class Less : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Less)
							DEF_PRECEDENCE(RELATIONAL)
							Operand::pointer_type perform(valueStack& valStk);
						};

						/** Less than or equal token */
						class LessEqual : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(LessEqual)
							DEF_PRECEDENCE(RELATIONAL)
							Operand::pointer_type perform(valueStack& valStk);
						};

						/** Greater than token */
						class Greater : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Greater)
							DEF_PRECEDENCE(RELATIONAL)
							Operand::pointer_type perform(valueStack& valStk);
						};

						/** Greater than or equal token */
						class GreaterEqual : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(GreaterEqual)
							DEF_PRECEDENCE(RELATIONAL)
							Operand::pointer_type perform(valueStack& valStk);
						};

						/** Equality token */
						class Equality : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Equality)
							DEF_PRECEDENCE(EQUALITY)
							Operand::pointer_type perform(valueStack& valStk);
						};

						/** Inequality token */
						class Inequality : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Inequality)
							DEF_PRECEDENCE(EQUALITY)
							Operand::pointer_type perform(valueStack& valStk);
						};

						/** AND token */
						class And : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(And)
							DEF_PRECEDENCE(LOGAND)
							Operand::pointer_type perform(valueStack& valStk);
						};

						/** NAND token*/
						class Nand : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Nand)
							DEF_PRECEDENCE(LOGAND)
							Operand::pointer_type perform(valueStack& valStk);
						};

						/** OR token */
						class Or : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Or)
							DEF_PRECEDENCE(LOGOR)
							Operand::pointer_type perform(valueStack& valStk);
						};

						/** NOR token */
						class Nor : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Nor)
							DEF_PRECEDENCE(LOGOR)
							Operand::pointer_type perform(valueStack& valStk);

						};

						/** XOR token */
						class Xor : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Xor)
							DEF_PRECEDENCE(LOGXOR)
							Operand::pointer_type perform(valueStack& valStk);
						};

						/** XNOR token */
						class Xnor : public LAssocOperator {
							DEF_IS_CONVERTABLE_FROM(Xnor)
							DEF_PRECEDENCE(LOGXOR)
							Operand::pointer_type perform(valueStack& valStk);
						};


	   /** Unary operator token base class. */
	   class UnaryOperator : public Operator {
	   public:
		   virtual unsigned number_of_args() const override { return 1; }
	   };
			
			/**Non-associative base class*/
			class NAssocOperator : public UnaryOperator{};
			
			
				/** Negation token*/
				class Negation : public NAssocOperator {
					DEF_IS_CONVERTABLE_FROM(Negation)
					DEF_PRECEDENCE(UNARY)
					Operand::pointer_type perform(valueStack& valStk);
				};
				/** Identity token*/
				class Identity : public NAssocOperator {
					DEF_IS_CONVERTABLE_FROM(Identity)
					DEF_PRECEDENCE(UNARY)
					Operand::pointer_type perform(valueStack& valStk);
				};
				/** Factorial Token*/
				class Factorial : public NAssocOperator {
					DEF_IS_CONVERTABLE_FROM(Factorial)
					DEF_PRECEDENCE(POSTFIX)
					Operand::pointer_type perform(valueStack& valStk);
				};

				/** NOT Token */
				class Not : public NAssocOperator {
					DEF_IS_CONVERTABLE_FROM(Not)
					DEF_PRECEDENCE(UNARY)
					Operand::pointer_type perform(valueStack& valStk);
				};


/*=============================================================

Revision History
Version 1.0.0: 2016-11-02
Added 'override' keyword where appropriate.

Version 0.3.0: 2014-10-30
Removed bitwise operators.

Version 0.2.0: 2012-11-16
Added BitAnd, BitNot, BitOr, BitShiftLeft, BitShiftRight

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
#endif // GUARD_operator_hpp20091126_
