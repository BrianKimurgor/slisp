// #include "tokenize.hpp"
// #include <iostream>
// #include <vector>

// namespace {
//     bool isWhitespace(char c) {
//         return c == ' ' || c == '\t' || c == '\n' || c == '\r';
//     }

//     bool isDigit(char c) {
//         return c >= '0' && c <= '9';
//     }

//     bool isSymbolStart(char c) {
//         return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
//     }

//     bool isSymbolChar(char c) {
//         return isSymbolStart(c) || isDigit(c);
//     }

//     bool isCommentStart(char c) {
//         return c == ';';
//     }
// }

// std::vector<std::string> tokenize(const std::string& input) {
//     std::vector<std::string> tokens;
//     std::string currentToken;
//     size_t line = 1;

//     auto pushToken = [&]() {
//         if (!currentToken.empty()) {
//             tokens.push_back(currentToken);
//             currentToken.clear();
//         }
//     };

//     for (char c : input) {
//         if (c == '\n') {
//             line++;
//         }

//         if (isWhitespace(c)) {
//             pushToken();
//         } else {
//             currentToken += c;
//         }
//     }

//     pushToken(); // Push the last token

//     return tokens;
// }

#include "tokenize.hpp"
#include <iostream>
#include <vector>

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

std::vector<std::string> tokenize(const std::string& input) {
    std::vector<std::string> tokens;
    std::string currentToken;
    size_t line = 1;

    auto pushToken = [&]() {
        if (!currentToken.empty()) {
            tokens.push_back(currentToken);
            currentToken.clear();
        }
    };

    for (char c : input) {
        if (c == '\n') {
            line++;
        }

        if (isWhitespace(c)) {
            pushToken();
        } else {
            currentToken += c;
        }
    }

    pushToken(); // Push the last token

    return tokens;
}
