#include <iostream>

#include "Hash.h"

int main() {
    Hash* hash = new Hash();
    std::string command, word;
    while(std::cin >> command) {
        word = command;
        word.erase(0,1);
        if (command[0] == '-')
            hash->deleteRecord(word);
        else if (command[0] == '?')
            hash->getOccurNumber(word);
        else if (command[0] == 'q')
            break;
        else hash->addWord(command);
    }
    return 0;
}