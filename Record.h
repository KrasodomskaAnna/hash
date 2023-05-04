#ifndef HASH_RECORD_H
#define HASH_RECORD_H

#include <iostream>

class Record {
public:
    Record() = default;
    Record(std::string key, int useAmount) {
        this->key = key;
        this->useAmount = useAmount;
    }
    std::string key;
    int useAmount;
    ~Record() = default;
};

#endif //HASH_RECORD_H
