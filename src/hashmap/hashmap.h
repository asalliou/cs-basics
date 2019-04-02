#include "hashnode.h"

const int mapSize = 20;

template < typename K, typename V, typename F>
class HashMap {
public:
    HashMap() {
        table = new HashNode<K, V> *[mapSize]();
    }
    
    ~HashMap() {
        for (int i = 0; i < mapSize; i++) {
            HashNode<K, V> *node = table[i];
            delete node;
        }
        delete [] table;
    }

    void put(const K &key, const V &value) {
        int index = hashFunc(key);
        HashNode<K, V> *newNode = new HashNode<K, V>(key, value);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            HashNode<K, V> *currentNode = table[index];          
            
            while (currentNode->getKey() != key && currentNode->getNext() != nullptr) {
                currentNode = currentNode->getNext();
            }
            if (currentNode->getKey() != key) {
                currentNode->setNext(newNode);
            } else {
                currentNode->setValue(value);
            }
            
        }
    }

    V get(const K &key) {
        int index = hashFunc(key);
        HashNode<K, V> *node = table[index];

        while (node->getKey() != key) {
            node = node->getNext();
        }
        return node->getValue();
    }

private:
    HashNode<K, V> **table;
    F hashFunc;
};
