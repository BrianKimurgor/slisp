#ifndef ENVIRONMENT_HPP // Prevent multiple inclusions
#define ENVIRONMENT_HPP   // Define a unique identifier for the header file

#include <unordered_map>  // Include necessary header for unordered_map
#include "expression.hpp"  // Include header file for Expression class
#include "interpreter_semantic_error.hpp" // Include header file for InterpreterSemanticError class

/**
 * This header file defines the `Environment` class, which manages variables and their associated
 expressions within a Slisp interpreter.
 */
class Environment {
public:
  /**
   * Default constructor for the `Environment` class.
   *
   * This constructor initializes an empty symbol table for storing variables.
   */
  Environment();

  /**
   * Adds a symbol (variable name) and its corresponding expression to the environment.
   *
   * This function takes two arguments:
   *   - `symbol`: The name of the variable as a string.
   *   - `exp`: The expression associated with the variable.
   *
   * It inserts the symbol-expression pair into the internal symbol table for future lookup.
   */
  void addSymbol(const std::string& symbol, const Expression& exp);

  /**
   * Retrieves the expression associated with a given symbol from the environment.
   *
   * This function takes a string representing the symbol name as input.
   * It searches the symbol table for the corresponding entry and returns the associated expression.
   *
   * If the symbol is not found in the environment, the function throws an `InterpreterSemanticError`
    exception with an informative message.
   */
  Expression getExpression(const std::string& symbol) const;

  /**
   * Checks if a given symbol exists in the environment's symbol table.
   *
   * This function takes a string representing the symbol name as input.
   * It searches the symbol table and returns `true` if the symbol exists, otherwise `false`.
   */
  bool symbolExists(const std::string& symbol) const;

  /**
   * Resets the environment to its initial state.
   *
   * This function clears the internal symbol table, effectively removing all previously added symbols
    and their associated expressions from the environment.
   */
  void resetEnvironment();

  /**
   * Internal helper function to find an expression in the environment.
   *
   * This function is not part of the public interface and is used internally by other methods within
   the `Environment` class.
   * It takes a string representing the symbol name and searches the symbol table. If found, it returns
    the associated expression, otherwise throws an `InterpreterSemanticError` exception.
   */
  Expression find(const std::string& key) const;

private:
  /**
   * Internal symbol table used to store variables (symbols) and their corresponding expressions.
   *
   * This member variable is declared as private as it should only be accessed within the `Environment`
    class. It uses an `unordered_map` to efficiently store and retrieve symbol-expression pairs.
   */
  std::unordered_map<std::string, Expression> symbolTable;
};

#endif // ENVIRONMENT_HPP // Guard against multiple inclusions
