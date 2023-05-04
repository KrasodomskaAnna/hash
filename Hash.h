#ifndef HASH_HASH_H
#define HASH_HASH_H

#include <iostream>

#include "Record.h"
#include "List.h"

class Hash {
public:
    Hash() = default;
    void addWord(std::string word);
    void deleteRecord(std::string word);
    void getOccurNumber(std::string word);
    ~Hash() {
        for(auto & i : hashtable)
            i.deleteAll();
    }
private:
    const static int p = 31;
    const static int m = 1019;
    List<Record*> hashtable[m];
    int generateHash(std::string word);
    Node<Record*>* getRecord(int id, std::string key);
};


#endif //HASH_HASH_H
