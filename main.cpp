#include <iostream>

using namespace std;

template<typename T1, typename T2>
struct paired{
    T1 key;
    T2 value;
};

template<typename KeyType, typename ValueType>
class Node{
public:
    paired<KeyType, ValueType> Value;
    Node<KeyType, ValueType>* next;

    Node(paired<KeyType, ValueType> data) : Value(data), next(nullptr) {}

};

template<typename KeyType, typename ValueType>
class LinkList{
    Node<KeyType, ValueType>* head;
    Node<KeyType, ValueType>* tail;
public:
    bool contains(const KeyType& key){
        Node<KeyType, ValueType>* temp = head;
        if(head == nullptr){
            return false;
        }else{
            temp = head;
            while(temp != nullptr){
                if(temp->Value.key == key){
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
    }

    void printlist(){
        Node<KeyType, ValueType>* temp = head;
        while(temp != nullptr){
            cout << "Key=" << temp->Value.key << ", Value=" << temp->Value.value << endl;
            temp = temp->next;
        }
    }

    void insert(const paired<KeyType, ValueType>& p){
        if (!contains(p.key)) {
            Node<KeyType, ValueType>* newNode = new Node<KeyType, ValueType>(p);
            if (head == nullptr) {
                head = newNode;
            } else {
                tail->next = newNode;
            }
            tail = newNode;
        }else{
            Node<KeyType, ValueType>* newNode = find(p.key);
            newNode->Value.value = p.value;
        }
    }

    Node<KeyType, ValueType>* find(KeyType key){
        Node<KeyType, ValueType>* temp = head;
        while(temp != nullptr){
            if(temp->Value.key == key){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};

int main() {
    LinkList<int, string> list = {};
    list.insert(paired<int, string>{1,"one"});
    list.insert(paired<int, string>{2,"two"});
    list.insert(paired<int, string>{3,"one"});
    list.insert(paired<int, string>{4,"four"});
    list.printlist();
    cout << "---" << endl;
    list.insert(paired<int, string>{3,"three"}); //Overwriting value
    list.printlist();
    return 0;
}
