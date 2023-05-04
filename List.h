#ifndef HASH_LIST_H
#define HASH_LIST_H

template<class T>
class Node {
public:
    Node* next = nullptr;
    Node* prev = nullptr;
    T value;
    Node() = default;
};

template<class T>
class List {
public:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

    void addAfter(T element) {
        if(head == nullptr) {
            head = new Node<T>();
            head->value = element;
            tail = head;
        }
        else {
            tail->next = new Node<T>();
            tail->next->value = element;
            tail->next->prev = tail;
            tail = tail->next;
        }
    }

    void remove(Node<T>* node) {
        if(node == head) {
            head = node->next;
            if(head == nullptr) tail = head;
            else head->prev = nullptr;
        }
        else {
            node->prev->next = node->next;
            if (node == tail) tail = node->prev;
            else node->next->prev = node->prev;
        }
        delete node;
    }

    Node<T>* getNext(Node<T>* currentNode) {
        if (currentNode == nullptr) return this->head;
        return currentNode->next;
    }

    void deleteAll() {
        if (this->head != nullptr) {
            while (true) {
                if (this->head != nullptr && this->head->next == nullptr) break;
                remove(this->head);
            }
            remove(this->head);
        }
    }
};

#endif //HASH_LIST_H
