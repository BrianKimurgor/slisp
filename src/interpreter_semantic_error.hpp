#ifndef INTERPRETER_SEMANTIC_ERROR_HPP
#define INTERPRETER_SEMANTIC_ERROR_HPP

#include <stdexcept>
#include <string>

// class InterpreterSemanticError : public std::runtime_error {
// public:
//     explicit InterpreterSemanticError(const std::string& message)
//         : std::runtime_error(message) {}
// };
class InterpreterSemanticError : public std::runtime_error {
public:
    InterpreterSemanticError(const std::string& message) : std::runtime_error(message) {}
};

#endif // INTERPRETER_SEMANTIC_ERROR_HPP
