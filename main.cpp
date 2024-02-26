/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s):
Your team alias: 
*/

//TODO: make it only print the specified # of slots, not a fixed 100 slots

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
    string texts[MAX_TOKENS];

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

    //validating input for number of slots
    if (k < 5 || k > 100) {
        cerr << "Invalid number of inputs." << endl;
        return 1;
    }

    //validating input for number of tokens
    if (n == 0) {
        cerr << "No tokens entered. Exiting." << endl;
        return 1;
    }

    //clear cin buffer to handle any remaining characters
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();

    //initializing hash table & using the hash function to enter the data into the slots
    const int MAX_SLOTS = 100;
    Node* hashTable[MAX_SLOTS] = {nullptr};

    for (int i = 0; i < n; i++) {
        int hashValue = hash_function(texts[i]) % k;

        Node *newNode = new Node;
        newNode->value = texts[i];
        newNode->next = nullptr;


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

    //print the contents of the first 5 slots in the hash table
    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    for (int i = 0; i < min(5, MAX_SLOTS); i++) {
        Node* current = hashTable[i];
        cout << "Slot " << i << ": ";
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    //print the lengths of each slot in the hash table
    cout << "==== Printing the slot lengths ====" << endl;
    for (int i = 0; i < MAX_SLOTS; i++) {
        Node* current = hashTable[i];
        int slotLength = 0;
        while (current != nullptr) {
            slotLength++;
            current = current->next;
        }
        cout << "Slot " << i << ": " << slotLength << endl;
    }

    //print the standard deviation of all slot lengths in the hash table
    //std deviation (LaTeX form): \sigma = \sqrt{\frac{1}{n}\sum_{i=1}^{N}(x_i-\mu)^2}
    cout << "==== Printing the standard variance ====" << endl;
    //calc avg slot length
    int totalSlots = 0;
    int totalLength = 0;
    for (int i = 0; i < MAX_SLOTS; i++) {
        Node* current = hashTable[i];
        while (current != nullptr) {
            totalLength++;
            current = current->next;
        }
        if (totalLength > 0) {
            totalSlots++;
        }
    }
    float averageLength = static_cast<float>(totalLength) / totalSlots;
    //calc sum of squared differences
    float sumSquaredDifferences = 0.0;
    for (int i = 0; i < MAX_SLOTS; i++) {
        Node* current = hashTable[i];
        int slotLength = 0;
        while (current != nullptr) {
            slotLength++;
            current = current->next;
        }
        if (slotLength > 0) {
            sumSquaredDifferences += pow(slotLength - averageLength, 2.0f);
        }
    }
    float standardDeviation = sqrt(sumSquaredDifferences / totalSlots);

    cout << fixed << setprecision(4) << standardDeviation << endl;
}
