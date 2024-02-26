#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

int hash_function(string text) {
    const int prime = 31;  //prime number for better distribution
    const int base = 26;   //using base-26 for second letter

    //hash calculation based on the characters in the input text
    int hashValue = 0;

    //use a simple formula for the first letter using ASCII value
    hashValue = (hashValue * prime) + static_cast<int>(text[0]);

    //use a different system for the second letter
    hashValue = (hashValue * base) + (text.length() > 1 ? (text[1] - 'a') : 0);

    //ensure the hash value is positive
    hashValue = (hashValue < 0) ? -hashValue : hashValue;

    //return calculated hash value
    return hashValue;
}
