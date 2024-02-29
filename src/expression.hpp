#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <string>
#include <vector>
#include <iostream>

enum class AtomType { None, Boolean, Number, Symbol };

struct Expression {
    AtomType type;
    bool boolValue;
    double numValue;
    std::string symValue;
    std::vector<Expression> children;

    Expression();
    Expression(bool value);
    Expression(double value);
    Expression(const std::string& value);

    bool operator==(const Expression& exp) const noexcept;

    std::string getStringRepresentation() const;
};


std::ostream& operator<<(std::ostream& os, const Expression& expr);








#endif // EXPRESSION_HPP
