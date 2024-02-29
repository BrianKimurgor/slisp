#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <iostream>
#include <sstream>
#include "environment.hpp"
#include "expression.hpp"
#include <stdexcept>



class Interpreter {
public:
    Interpreter();
    bool parse(std::string& expression) noexcept;
    Expression eval();
    void runREPL();

private:
    Environment environment;
    Expression parseExpression(std::string& expression);
    Expression evaluateExpression(const Expression& exp);
    Expression ast;

    // Add additional private methods if needed
};

#endif // INTERPRETER_HPP
