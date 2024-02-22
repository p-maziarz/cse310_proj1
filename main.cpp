/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s):
Your team alias: 
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"
using namespace std;

struct Node {
    string value;
    Node* next;
};

const int MAX_TOKENS = 500;

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.


    // Step 3: Initialize your hash table and populate it using your hash function
    // TODO: Create your hash table data structure and use the hash function to populate it
    const int MAX_SLOTS = 100;
    Node* hashTable[MAX_SLOTS] = {nullptr};

    for (int i = 0; i < n; i++) {
        int hashValue = hash_function(text[i]) % k;

        Node *newNode = new Node{texts[i], nullptr};

        if (hashTable[hashValue] == nullptr) {
            hashTable[hashValue] = newNode;
        } else {
            Node *current = hashTable[hashValue];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Step 4: Print the contents of the first 5 slots in the hash table
    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    // TODO: Print the contents of the first 5 slots in your hash table
    for (int i = 0; i < min(5, MAX_SLOTS); i++) {
        Node* current = hashTable[i];
        while (current != nullptr) {
            cout << "Slot " << i << ": " << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Step 5: Print the lengths of each slot in the hash table
    cout << "==== Printing the slot lengths ====" << endl;
    // TODO: Print the lengths of each slot in your hash table
    for (int = 0; i < MAX_SLOTS; i++) {
        Node* current = hashTable[i];
        int slotLength = 0;
        while (current != nullptr) {
            slotLength++;
            current = current->next;
        }
        cout << "Slot " << i << ": " << slotLength << endl;
    }

    // Step 6: Print the standard deviation of all slot lengths in the hash table
    cout << "==== Printing the standard variance ====" << endl;
    // TODO: Calculate and print the standard deviation of all slot lengths in your hash table

    return 0;
}
