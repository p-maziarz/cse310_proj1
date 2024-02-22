#include <iostream>
#include <string>
#include "hash.h"
#include <list>
using namespace std;

int hash_function(string text) {
    const int prime = 31;  // A prime number for better distribution

    // Hash calculation based on the characters in the input text
    int hashValue = 0;

    for (char ch : text) {
        // Use a simple formula, you can modify this based on your design
        hashValue = (hashValue * prime) + static_cast<int>(ch);
    }

    // Ensure the hash value is positive (absolutely necessary for array indexing)
    hashValue = (hashValue < 0) ? -hashValue : hashValue;

    // Return the calculated hash value
    return hashValue;
}
