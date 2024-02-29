#include "environment.hpp"


Environment::Environment() {
    // Initialize the environment if needed
}

void Environment::addSymbol(const std::string& symbol, const Expression& exp) {
    // Add symbol to the environment
    symbolTable[symbol] = exp;
}

Expression Environment::getExpression(const std::string& symbol) const {
    // Get expression associated with the symbol
    auto it = symbolTable.find(symbol);
    if (it != symbolTable.end()) {
        return it->second;
    } else {
        return Expression(); // Return a default expression if symbol not found (can be improved)
    }
}

bool Environment::symbolExists(const std::string& symbol) const {
    // Check if symbol exists in the environment
    return symbolTable.find(symbol) != symbolTable.end();
}

void Environment::resetEnvironment() {
    // Reset the environment to the default state
    symbolTable.clear();
}
