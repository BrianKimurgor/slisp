#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <unordered_map>
#include "expression.hpp"
#include "interpreter_semantic_error.hpp"

class Environment {
public:
    Environment();
    void addSymbol(const std::string& symbol, const Expression& exp);
    Expression getExpression(const std::string& symbol) const;
    bool symbolExists(const std::string& symbol) const;
    void resetEnvironment();
    std::unordered_map<std::string, Expression> variables;

    Expression find(const std::string& key) {
        auto it = variables.find(key);
        if (it != variables.end()) {
            return it->second;
        }
        throw InterpreterSemanticError("unknown symbol: " + key);
    }

private:
    std::unordered_map<std::string, Expression> symbolTable;
};

#endif // ENVIRONMENT_HPP
