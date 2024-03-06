#ifndef INTERPRETER_SEMANTIC_ERROR_HPP // Prevent multiple inclusions
#define INTERPRETER_SEMANTIC_ERROR_HPP   // Define a unique identifier for the header file

#include <stdexcept>  // Include standard exception library
#include <string>     // Include string library for error message

/**
 * This header file defines the `InterpreterSemanticError` class,
 * which inherits from `std::runtime_error`.
 */
class InterpreterSemanticError : public std::runtime_error {
public:
  /**
   * Constructor for the `InterpreterSemanticError` class.
   *
   * This constructor takes a string argument representing the error message
   * and initializes a new `InterpreterSemanticError` object with that message.
   * It inherits the behavior of the `std::runtime_error` constructor.
   */
  InterpreterSemanticError(const std::string& message) : std::runtime_error(message) {}
};

#endif // INTERPRETER_SEMANTIC_ERROR_HPP // Guard against multiple inclusions
