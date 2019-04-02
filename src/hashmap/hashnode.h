template <typename K, typename V>
class HashNode {
public:
    HashNode(const K &key, const V &value) :
    key(key), value(value), next(nullptr) {}

    K getKey() {
        return key;
    }

    V getValue() {
        return value;
    }
    
    void setValue(const V &newValue) {
        value = newValue;
    }

    void setNext(HashNode <K, V> *next) {
        this->next = next;
    }

    HashNode <K, V>* getNext() {
        return this->next;
    }

private:
    K key;
    V value;
    HashNode <K, V> *next;
};
