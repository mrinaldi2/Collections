#include "List.h"
#include "Structs.h"

template<class T>
class LinkedList : public List<T> {
    private:
        int n;
        Node<T>* HEAD;
        Node<T>* TAIL;
        Node<T>* findBy(int index) {
            if(this->HEAD == nullptr) {
                throw "IndexOutBoundExcpetion";
            }
            Node<T>* current = this->HEAD;
            for(int i = 1; i <= index; i++) {
                if(current->next == nullptr) {
                    throw "IndexOutBoundException";
                }
                current = current->next;
            }
            return current;
        }
    public:
    LinkedList() {
        this->n = 0;
        this->HEAD = nullptr;
        this->TAIL = nullptr;
    }
    T pop() {
       if(this->TAIL == nullptr) {
           throw "EmptyListException";
       }
       T obj = this->TAIL->val;
       if(this->HEAD == this->TAIL) {
           delete this->HEAD;
           delete this->TAIL;
           this->HEAD = nullptr;
           this->TAIL = nullptr;
           return obj;
       }
       Node<T>* previous = this->findBy(this->n - 2);
       delete this->TAIL;
       delete previous->next;
       previous->next = nullptr;
       this->TAIL = previous;
       return obj;
    };
    void push(T obj) {
        Node<T> *newNode = new Node<T>();
        newNode->val = obj; 
        this->n++;
        if(this->TAIL == nullptr) {
            this->TAIL = newNode;
            this->HEAD = newNode;
            return;
        }
        this->TAIL->next = newNode;
        this->TAIL = newNode;
    };
    void push(int index, T obj) {
        Node<T>* current = this->findBy(index - 1);
        Node<T>* newNode = new Node<T>();
        newNode->val = obj;
        newNode->next = current->next;
        current->next = newNode;
        this->n++;
    };
    void replace(int index, T obj) {
        Node<int>* current = this->findBy(index);
        current->val = obj;
    };
    int size() {
        return this->n;
    };
    void print() {
        Node<T>* current = this->HEAD;
        int index = 0;
        while(current != nullptr) {
            printf("Value at index: %d is: %d\n", index, current->val);
            index++;
            current = current->next;
        }
    };
    T get(int index) {
        Node<int>* current = this->findBy(index);
        return current->val;
    };
    T remove(int index) {
        Node<T>* previous;
        Node<T>* current = this->findBy(index);
        if(index != 0) {
            previous = this->findBy(index - 1);
            previous->next = current->next;
        }
        if(index == this->n - 1) {
            this->TAIL = previous;
        }else if (index == 0) {
            this->HEAD = current->next;
        }
        T obj = current->val;
        this->n--;
        delete current;
        return obj;
    };
    ~LinkedList() {
        if(this->HEAD != nullptr) {
            delete this->HEAD;
        }
        if(this->TAIL != nullptr) {
            delete this->TAIL;
        }
    }
};