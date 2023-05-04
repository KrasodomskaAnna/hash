#include "Hash.h"


int Hash::generateHash(std::string word) {
    long long int sum = 0;
    for(int i = 0; i < word.size(); i++) {
        sum += word[i] * pow(p, i);
    }
    int hash = sum % m;
    return hash;
}

Node<Record*>* Hash::getRecord(int id, std::string key) {
    Node<Record*>* current = hashtable[id].getNext(nullptr);
    while(current != nullptr) {
        if(current->value->key == key)
            return current;
        current = hashtable[id].getNext(current);
    }
    return nullptr;
}

void Hash::addWord(std::string word) {
    int id = generateHash(word);
    Node<Record*>* node = getRecord(id, word);
    if(node == nullptr) hashtable[id].addAfter(new Record(word, 1));
    else node->value->useAmount++;
}

void Hash::deleteRecord(std::string word) {
    int id = generateHash(word);
    Node<Record*>* node = getRecord(id, word);
    if(node != nullptr) hashtable[id].remove(node);
}

void Hash::getOccurNumber(std::string word) {
    int id = generateHash(word);
    Node<Record*>* node = getRecord(id, word);
    if(node == nullptr) std::cout << "0" << std::endl;
    else std::cout << node->value->useAmount << std::endl;
}