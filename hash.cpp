#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

int hash_function(string text) {
    int prime = 31;  //prime number for better distribution
    const int base2 = 26; //using base-26 for second letter
    const int base3 = 19; //base-19 for third letter
    const int base4 = 13; //base-13 for fourth letter 
    const int base5 = 7; //base-7 for fifth letter 
    const int base6 = 5; 

    int hashValue = text.length();

    for (int i =0; i < text.length()-1; i++){ 
        hashValue += prime*text[i];
        prime -=4;
    }

    //return calculated hash value
    return hashValue;
}
/*
NOTE: keys with one or two chars will ALWAYS have the LOWEST hashvals,
and hashVals are dependant on alphabetical order. 
ex. 'Aaa' will be lower than 'Aab'.
*/
