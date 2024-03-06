#include "tokenize.hpp" // Include header for previously defined helper functions (assumed)
#include <iostream>       // Include iostream library for error messages (optional)
#include <vector>        // Include vector library for storing tokens

/**
 * This namespace contains helper functions used by the `tokenize` function.
 * These functions are private to this file (`namespace { ... }`) to avoid polluting the global namespace.
 *
 *  * `isWhitespace(char c)`: Checks if a character is whitespace (space, tab, newline, or carriage return).
 *  * `isDigit(char c)`: Checks if a character is a digit (0-9).
 *  * `isSymbolStart(char c)`: Checks if a character can be the first character of a symbol (a-z, A-Z, or underscore).
 *  * `isSymbolChar(char c)`: Checks if a character can be part of a symbol (includes digits for extended symbol compatibility).
 *  * `isCommentStart(char c)`: Checks if a character is the start of a single-line comment (semicolon).
 */
namespace {

  bool isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
  }

  bool isDigit(char c) {
    return c >= '0' && c <= '9';
  }

  bool isSymbolStart(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
  }

  bool isSymbolChar(char c) {
    return isSymbolStart(c) || isDigit(c);
  }

  bool isCommentStart(char c) {
    return c == ';';
  }
}

/**
 * This function tokenizes a Slisp expression string into a vector of individual tokens.
 *
 * The function iterates over each character in the input string and performs the following:
 *  1. Tracks line numbers for potential error reporting (optional).
 *  2. Uses a lambda function `pushToken` to add the current token to the result vector
 *     whenever whitespace is encountered or the end of the string is reached.
 *  3. Skips whitespace characters.
 *  4. Handles different token types:
 *     - Numbers: Consecutive digits are accumulated into a single token.
 *     - Symbols: Sequences of letters, digits, and underscores are considered symbols.
 *     - Comments: Characters starting with a semicolon (``) are ignored until the end of the line.
 *
 * Finally, the function pushes the last token (if any) to the result vector and returns the complete list of tokens.
 */
// std::vector<std::string> tokenize(const std::string& input) {
//   std::vector<std::string> tokens;
//   std::string currentToken;
//   size_t line = 1;
//   size_t i;

//   auto pushToken = [&]() {
//     if (!currentToken.empty()) {
//       tokens.push_back(currentToken);
//       currentToken.clear();
//     }
//   };

//   for (char c : input) {
//     if (c == '\n') {
//       line++;
//     }

//     if (isWhitespace(c)) {
//       pushToken();
//     } else {
//       if (isDigit(c)) {
//         // Handle numbers
//         while (isDigit(c)) {
//           currentToken += c;
//           c = input[++i]; // Move to the next character without incrementing loop counter
//         }
//       } else if (isSymbolStart(c)) {
//         // Handle symbols
//         while (isSymbolChar(c)) {
//           currentToken += c;
//           c = input[++i]; // Move to the next character without incrementing loop counter
//         }
//       } else if (isCommentStart(c)) {
//         // Skip comments until the end of the line
//         while (c != '\n' && c != '\0') {
//           c = input[++i]; // Move to the next character without incrementing loop counter
//         }
//       } else {
//         // Other characters are treated as single-character tokens
//         currentToken += c;
//       }
//     }
//   }

//   pushToken(); // Push the last token

//   return tokens;
// }
std::vector<std::string> tokenize(const std::string& input) {
  std::vector<std::string> tokens;
  std::string currentToken;
  size_t line = 1;
  size_t i = 0; // Declare i outside the loop

  auto pushToken = [&]() {
    if (!currentToken.empty()) {
      tokens.push_back(currentToken);
      currentToken.clear();
    }
  };

  for (i = 0; i < input.size(); ++i) {
    char c = input[i];

    if (c == '\n') {
      line++;
    }

    if (isWhitespace(c)) {
      pushToken();
    } else {
      if (isDigit(c)) {
        // Handle numbers
        while (isDigit(c)) {
          currentToken += c;
          c = input[++i]; // Move to the next character without incrementing loop counter
        }
      } else if (isSymbolStart(c)) {
        // Handle symbols
        while (isSymbolChar(c)) {
          currentToken += c;
          c = input[++i]; // Move to the next character without incrementing loop counter
        }
      } else if (isCommentStart(c)) {
        // Skip comments until the end of the line
        while (c != '\n' && c != '\0') {
          c = input[++i]; // Move to the next character without incrementing loop counter
        }
      } else {
        // Other characters are treated as single-character tokens
        currentToken += c;
      }
    }
    i++;
  }

  pushToken(); // Push the last token

  return tokens;
}
