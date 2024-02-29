#include "expression.hpp"

Expression::Expression() : type(AtomType::None), boolValue(false), numValue(0.0) {}

Expression::Expression(bool value) : type(AtomType::Boolean), boolValue(value), numValue(0.0) {}

Expression::Expression(double value) : type(AtomType::Number), boolValue(false), numValue(value) {}

Expression::Expression(const std::string& value) : type(AtomType::Symbol), boolValue(false), numValue(0.0), symValue(value) {}

bool Expression::operator==(const Expression& exp) const noexcept {
    return type == exp.type && boolValue == exp.boolValue && numValue == exp.numValue && symValue == exp.symValue && children == exp.children;
}

std::string Expression::getStringRepresentation() const {
    switch (type) {
        case AtomType::None:
            return "None";
        case AtomType::Boolean:
            return boolValue ? "True" : "False";
        case AtomType::Number:
            // Convert double to string with desired precision
            // For simplicity, using std::to_string here
            return std::to_string(numValue);
        case AtomType::Symbol:
            return symValue;
        default:
            // Handle other cases if needed
            return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& os, const Expression& expr) {
    os << expr.getStringRepresentation();
    return os;
}
