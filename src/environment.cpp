#include "environment.hpp"

/**
 * Default constructor for the Environment class.
 *
 * This constructor initializes the environment with an empty symbol table.
 * You can potentially add further initialization logic here if needed for
    your specific use case.
 */
Environment::Environment() {
  // This part will initialize the environment if needed
}

/**
 * Adds a symbol (variable name) and its corresponding expression to the environment.
 *
 * This function takes two arguments:
 *   - `symbol`: The name of the variable as a string.
 *   - `exp`: The expression associated with the variable.
 *
 * It inserts the symbol-expression pair into the internal symbol table for future lookup.
 */
void Environment::addSymbol(const std::string& symbol, const Expression& exp) {
  // Here we add the symbol to the environment
  symbolTable[symbol] = exp;
}

/**
 * Retrieves the expression associated with a given symbol from the environment.
 *
 * This function takes a string representing the symbol name as input.
 * It searches the symbol table for the corresponding entry and returns the associated expression.
 *
 * If the symbol is not found in the environment, the function returns a default `Expression` object
  (which can be improved upon for handling missing symbols).
 */
Expression Environment::getExpression(const std::string& symbol) const {
  // Get expression associated with the symbol
  auto it = symbolTable.find(symbol);
  if (it != symbolTable.end()) {
    return it->second;
  } else {
    return Expression(); // Return a default expression if symbol not found (can be improved)
  }
}

/**
 * Checks if a given symbol exists in the environment's symbol table.
 *
 * This function takes a string representing the symbol name as input.
 * It searches the symbol table and returns `true` if the symbol exists, otherwise `false`.
 */
bool Environment::symbolExists(const std::string& symbol) const {
  // Check if symbol exists in the environment
  return symbolTable.find(symbol) != symbolTable.end();
}

/**
 * Resets the environment to its initial state.
 *
 * This function clears the internal symbol table, effectively removing all previously added
 symbols and their associated expressions from the environment.
 */
void Environment::resetEnvironment() {
  // Reset the environment to the default state
  symbolTable.clear();
}
