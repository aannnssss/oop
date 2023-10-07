#pragma once
#include <iostream>
#include <cstring>

class Three {    
    public:
        Three();
        size_t getSize() const;
        unsigned char* getNumber() const;

        Three(const size_t &n, unsigned char t = 0);
        Three(const std::initializer_list<unsigned char> &t);
        Three(const std::string t);
        Three(const Three& other);
        Three(Three && other) noexcept; // Move constructor
        std::ostream &print(std::ostream &os); 

        Three operator=(const Three &other); // Assignment
        Three operator+(const Three &other) const; // Addition
        Three operator-(const Three &other) const; // Substraction
        bool operator==(const Three &other) const; // Equal
        bool operator!=(const Three &other) const; // Not equal
        bool operator<(const Three &other) const; // Less
        bool operator<=(const Three &other) const; // Less or equal
        bool operator>(const Three other) const; // Greater
        bool operator>=(const Three other) const; // Greater or equal

       ~Three() noexcept; // Destructor
    private:
        size_t size;
        unsigned char *number;
};

bool isThree(const char &c);
