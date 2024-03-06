#ifndef EXPRESSION_HPP // Prevent multiple inclusions
#define EXPRESSION_HPP   // Define a unique identifier for the header file

#include <string>       // Include string library for `std::string`
#include <vector>        // Include vector library for `std::vector`
#include <iostream>      // Include iostream library for `std::ostream`

/**
 * This header file defines the `Expression` class and related elements used within the Slisp interpreter.
 */

/**
 * Enumeration that defines different atom types for expressions.
 *
 * This enum defines the possible types an `Expression` object can have:
 *  - None: Represents the absence of a value.
 *  - Boolean: Represents a true or false value.
 *  - Number: Represents a numerical value (double-precision floating-point).
 *  - Symbol: Represents a symbolic value (string).
 */
enum class AtomType { None, Boolean, Number, Symbol };

/**
 * This struct defines the `Expression` class, which represents various expressions
 * within the Slisp interpreter.
 *
 * An `Expression` object can be atomic (having a single value) or composite (containing multiple child expressions).
 */
struct Expression {
  /**
   * Type of the expression, defined by the `AtomType` enumeration.
   */
  AtomType type;

  /**
   * Boolean value for expressions of type `Boolean`.
   */
  bool boolValue;

  /**
   * Numerical value for expressions of type `Number`.
   */
  double numValue;

  /**
   * Symbolic value for expressions of type `Symbol`.
   */
  std::string symValue;

  /**
   * Vector of child expressions, used for representing composite expressions.
   */
  std::vector<Expression> children;

  /**
   * Default constructor for the `Expression` class.
   *
   * This constructor creates an expression of type `None` with default
   * boolean and numerical values set to false and 0.0, respectively.
   */
  Expression();

  /**
   * Constructor for creating boolean expressions.
   *
   * This constructor takes a boolean value as input and creates an expression
   * of type `Boolean` with the specified value.
   */
  Expression(bool value);

  /**
   * Constructor for creating numerical expressions.
   *
   * This constructor takes a double-precision floating-point value as input
   * and creates an expression of type `Number` with the specified value.
   */
  Expression(double value);

  /**
   * Constructor for creating symbolic expressions.
   *
   * This constructor takes a string as input and creates an expression of type
   * `Symbol` with the specified string value.
   */
  Expression(const std::string& value);

  /**
   * Equality comparison operator for `Expression` objects.
   *
   * This function compares two `Expression` objects for equality, taking into account
   * their types, boolean values, numerical values, symbolic values, and child expressions.
   * It is declared as `noexcept` to indicate that it does not throw any exceptions.
   */
  bool operator==(const Expression& exp) const noexcept;

  /**
   * Generates a string representation of the `Expression` object.
   *
   * This function returns a string that represents the expression in a human-readable format.
   * The exact format depends on the type of the expression.
   */
  std::string getStringRepresentation() const;
};

/**
 * Overloaded output stream operator for `Expression` objects.
 *
 * This function allows convenient printing of `Expression` objects to output streams using the `<<` operator.
 * It delegates the actual printing to the `getStringRepresentation()` function.
 */
std::ostream& operator<<(std::ostream& os, const Expression& expr);


#endif // EXPRESSION_HPP // Guard against multiple inclusions
