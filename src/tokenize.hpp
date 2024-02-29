// #ifndef TOKENIZE_HPP
// #define TOKENIZE_HPP

// #pragma once

// #include <string>
// #include <vector>

// struct Token {
//     enum Type { OPEN_PAREN, CLOSE_PAREN, SYMBOL, NUMBER, BOOLEAN, STRING, COMMENT, INVALID };
//     Type type;
//     std::string value;
//     size_t line;
// };
// std::vector<std::string> tokenize(std::string& input);

// #endif

#ifndef TOKENIZE_HPP
#define TOKENIZE_HPP

#pragma once

#include <string>
#include <vector>

struct Token {
    enum Type { OPEN_PAREN, CLOSE_PAREN, SYMBOL, NUMBER, BOOLEAN, STRING, COMMENT, INVALID };
    Type type;
    std::string value;
    size_t line;
};

std::vector<std::string> tokenize(const std::string& input);

#endif
