#include "expression.hpp" // Include header file for Expression class

/**
 * This header file defines the implementation of the `Expression` class,
 * which represents various expressions within the Slisp interpreter.
 */

/**
 * Default constructor for the Expression class.
 *
 * This constructor creates an expression of type `None` with default boolean
 * and numerical values set to false and 0.0, respectively.
 */
Expression::Expression() : type(AtomType::None), boolValue(false), numValue(0.0) {}

/**
 * Constructor for creating boolean expressions.
 *
 * This constructor takes a boolean value as input and creates an expression
 * of type `Boolean` with the specified boolean value.
 */
Expression::Expression(bool value) : type(AtomType::Boolean), boolValue(value), numValue(0.0) {}

/**
 * Constructor for creating numerical expressions.
 *
 * This constructor takes a double-precision floating-point value as input
 * and creates an expression of type `Number` with the specified value.
 */
Expression::Expression(double value) : type(AtomType::Number), boolValue(false), numValue(value) {}

/**
 * Constructor for creating symbolic expressions.
 *
 * This constructor takes a string as input and creates an expression of type
 * `Symbol` with the specified string value.
 */
Expression::Expression(const std::string& value) : type(AtomType::Symbol), boolValue(false), numValue(0.0), symValue(value) {}

/**
 * Equality comparison operator for Expression objects.
 *
 * This function compares two Expression objects for equality, taking into account
 * their types, boolean values, numerical values, symbolic values, and child expressions.
 * It is declared as noexcept to indicate that it does not throw any exceptions.
 */
bool Expression::operator==(const Expression& exp) const noexcept {
  // Compare all relevant member variables for equality
  return type == exp.type && boolValue == exp.boolValue && numValue == exp.numValue && symValue == exp.symValue && children == exp.children;
}

/**
 * Generates a string representation of the Expression object.
 *
 * This function returns a string that represents the expression in a human-readable format.
 * The exact format depends on the type of the expression.
 */
std::string Expression::getStringRepresentation() const {
  switch (type) {
    case AtomType::None:
      return "None";
    case AtomType::Boolean:
      return boolValue ? "True" : "False";
    case AtomType::Number:
      return std::to_string(numValue); // Convert double to string (adjust precision if needed)
    case AtomType::Symbol:
      return symValue;
    default:
      return "Unknown"; // Handle other cases if necessary
  }
}

/**
 * Overloaded output stream operator for Expression objects.
 *
 * This function allows convenient printing of Expression objects to output streams using the `<<` operator.
 * It delegates the actual printing to the `getStringRepresentation()` function.
 */
std::ostream& operator<<(std::ostream& os, const Expression& expr) {
  os << expr.getStringRepresentation(); // Output the string representation
  return os;
}
