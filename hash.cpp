#include <iostream>
#include <string>
#include "hash.h"
#include <list>
using namespace std;

int hash_function(string text) {
private:
    list<int> *tbl;
    int fetch_hash(int k){
        return k % all_ele;
    }
public:
    hash_table(int a) {
        all_ele = a;
        tbl = new list<int>[all_ele];
    }
    void inst_ele(int k){
        tbl[fetch_hash(k)].push_back(k);
    }
    void dsp(){
        for (int i = 0; i < all_ele; i++) {
            cout << "The Index of item is " << i "\n " << endl;
            for (int j : tbl[i]) {
                cout << "The value for the index " << i << " is " << j << endl;
                cout << endl;
            }
        }
    }
    return 1;
}
