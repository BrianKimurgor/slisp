#include "interpreter_semantic_error.hpp"
#include "interpreter.hpp"
#include "tokenize.hpp"
#include <stack>


Interpreter::Interpreter() {
  // Initialize the interpreter if needed
}

Expression Interpreter::eval() {
  // TODO: Implement AST evaluation logic
  // Use the environment and evaluateExpression method

  return Expression(); // Return the result of the evaluation
}

Expression Interpreter::parseExpression(std::string & expression) {
  std::vector < std::string > tokens = tokenize(expression);

  // Create a stack to build the AST
  std::stack < Expression > stack;

  for (const auto & token: tokens) {
    if (token == "(") {
      stack.push(Expression());
    } else if (token == ")") {
      Expression currentExpression;
      while (!stack.empty() && stack.top().type != AtomType::None) {
        currentExpression.children.insert(currentExpression.children.begin(), stack.top());
        stack.pop();
      }
      stack.pop(); // Pop the opening parenthesis

      // Check for special forms and procedures and handle accordingly
      // TODO: Implement special form and procedure handling

      // Push the constructed expression onto the stack
      stack.push(currentExpression);
    } else {
      // For numbers and symbols, create an atom and push onto the stack
      stack.push(Expression(token));
    }
  }

  // The top of the stack should now contain the fully constructed AST
  return stack.top();
}

Expression Interpreter::evaluateExpression(const Expression & exp) {
  if (exp.type == AtomType::Number || exp.type == AtomType::Symbol) {
    // For atoms (numbers and symbols), return the atom itself
    return exp;
  } else {
    // For expressions, recursively evaluate each child
    Expression result;
    for (const auto & child: exp.children) {
      result.children.push_back(evaluateExpression(child));
    }

    // Check for special forms and procedures and handle accordingly
    // TODO: Implement special form and procedure handling

    // For simplicity, assuming here that the expression itself is the result
    return result;
  }
}

bool Interpreter::parse(std::string & expression) noexcept {
  try {
    // Parse the input expression to get the AST
    Expression ast = parseExpression(expression);

    // TODO: Store the AST for later evaluation
    // Here, just printing the AST for demonstration purposes
    std::cout << " " << ast << std::endl;

    // Store the AST for later evaluation
    // TODO: Implement AST storage logic

    return true; // Return true if parsing is successful
  } catch (...) {
    return false; // Return false on failure
  }
}

void Interpreter::runREPL() {
  std::string input;
  while (true) {
    std::cout << "slisp> ";
    getline(std::cin, input);

    if (input.empty()) {
      continue; // Ignore empty lines
    }

    if (!parse(input)) {
      std::cerr << "Error: Failed to parse input." << std::endl;

      continue;
    }

    try {
      // TODO: Evaluate the stored AST
      // Update the environment accordingly
      // Print the result
      Expression result; // Replace with actual evaluation result
      std::cout << result << std::endl; // Assuming Expression has an appropriate ostream operator
    } catch (const InterpreterSemanticError & e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
}
