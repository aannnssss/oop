#include "Three.hpp"

bool isThree(const char &c) {
    return (c >= '0' && c <= '2');
}

Three::Three() : size(0), number{nullptr} {}

size_t Three::getSize() const { return size; }

unsigned char* Three::getNumber() const { return number; }

Three::Three(const size_t &n, unsigned char t) {
    number = new unsigned char[n];
    for (size_t i = 0; i < n; i++)
        number[i] = t;
    size = n;  
}

Three::Three(const std::initializer_list<unsigned char> &t) {
    number = new unsigned char[t.size()];
    size = t.size();
    size_t i{size};
    for (unsigned char c : t) {
        if (!isThree(c)) { 
            throw std::logic_error("Three digit can't be 3 or more");
        }
        number[--i] = c;
    }
}

Three::Three(const std::string t) {
    size  = t.size();
    number = new unsigned char[size];
    for(int i = size - 1, j = 0;  i >= 0 && j < size; i--, j++) {
        if (!isThree(t[i])) { 
            throw std::logic_error("Three digit can't be 3 or more");
        }
        number[i] = t[j];
    }
}

Three::Three(const Three &other) {
    size  = other.size;
    number = new unsigned char[size];
    for(size_t i = 0; i < size; i++) {
        number[i] = other.number[i];
    }
}

Three::Three(Three &&other) noexcept {
    size = other.size;
    number = other.number;
    other.size = 0;
    other.number = nullptr;
}

Three Three::operator=(const Three &other) {
    if (&other != this) {
        delete[] number;
        size = other.size;
        number = new unsigned char[size];
        for (size_t i = 0; i < size; i++) {
            number[i] = other.number[i];
        }
    }
    return *this;
}

Three Three::operator+(const Three &other) const {
    size_t resultSize = std::max(other.size, size) + 1;
    std::string result(resultSize, '0');
    int carry = 0;
    for (size_t i = 0; i < resultSize; i++) {
        int d1 = (i < size) ? (number[i] - '0') : 0;
        int d2 = (i < other.size) ? (other.number[i] - '0') : 0;

        int sum = d1 + d2 + carry;
        result[i] = (sum % 3) + '0';
        carry = sum / 3;
    }
    if (carry > 0) {
        result[resultSize - 1] = carry + '0';
    }
    if (result[resultSize - 1] == '0'){
        result.erase(resultSize - 1, 1);
    }
    std::reverse(result.begin(), result.end());
    return Three(result);
}

Three Three::operator-(const Three &other) const {
    if (*this < other) { throw std::logic_error("Difference can't be negative"); }
    size_t resultSize = std::max(other.size, size) + 1;
    std::string result(resultSize, '0');
    int carry = 0;
    for (size_t i = 0; i < resultSize; i++) {
        int d1 = (i < size) ? (number[i] - '0') : 0;
        int d2 = (i < other.size) ? (other.number[i] - '0') : 0;

        int diff = d1 - d2 - carry;
        if (diff < 0) {
            diff += 3;
            carry = 1;
        } else {
            carry = 0;
        }
        result[i] = diff + '0';
    }
    if (result[resultSize - 1] == '0'){
        result.erase(resultSize - 1, 1);
    }
    std::reverse(result.begin(), result.end());
    return Three(result);
}

bool Three::operator==(const Three &other) const {
    if (size != other.size) { return 0; }
    for (size_t i = 0; i < size; i++) {
        if (number[i] != other.number[i]) {
            return 0;
        }
    }
    return 1;
}

bool Three::operator!=(const Three &other) const {
    if (*this == other) { return 0; }
    return 1;
 }

bool Three::operator<(const Three &other) const {
    if (&other == this) { throw std::logic_error("The same object"); }
    if (size < other.size) { return 1; }
    else if (size > other.size) { return 0; }
    else {
        for (size_t i = size; i--;) {
            if (number[i] < other.number[i]) { return 1; }
            else if (number[i] > other.number[i]) { return 0; }
        }
    }
    return 0;
}

bool Three::operator<=(const Three &other) const {
    if (*this > other) { return 0; }
    return 1;
}

bool Three::operator>(const Three other) const {
    if (*this < other || *this == other) { return 0; }
    return 1;
}

bool Three::operator>=(const Three other) const {
    if (*this < other) { return 0; }
    return 1;
}

std::ostream& Three::print(std::ostream &os) {
    for (size_t i = size; i--;) {
        os << number[i];
    }
    return os;
}

Three::~Three() noexcept {
    if (size > 0) {
        size = 0;
        delete[] number;
        number = nullptr;
    }
}