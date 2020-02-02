#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include "List"

template<class T>
class ArrayList : public List<T> {
    private:
        int n;
        int current = 0;
        static const int MAX_SIZE = 100;
        T array[MAX_SIZE];
    public:
    ArrayList(int n) {
        this->n = n;
    }
    T pop() {
        T obj = this->array[this->current];
        this->current--;
        this->n--;
        return obj;
    };
    void push(T obj) {
        if(this->current == this->n) {
            this->n++;
        }
        if(this->n == MAX_SIZE) {
            printf("OVERFLOW: Sirul este plin nu se mai poate mari");
            return;
        }
        this->array[this->current] = obj;
        this->current++;
    };
    void push(int index, T obj) {
        if(this->n == MAX_SIZE) {
            printf("OVERFLOW: Sirul este plin nu se mai poate mari");
            return;
        }
        for(int i = this->n - 1; i >= index; i--) {
            this->array[i+1] = this->array[i];
        }
        this->array[index] = obj;
        this->n++;
        this->current++;
    };
    void replace(int index, T obj) {
        if(index >= this->n) {
            throw "IndexOutBoundException";
        }
        this->array[index] = obj;
    };
    int size() {
        return this->n;
    };
    void print() {
        for(int i = 0; i < this->n; i++) {
            printf("x[%d] = %d\n", i, this->array[i]);
        }
    };
    T get(int index) {
        if(index >= this->n) {
            throw "IndexOutBoundException";
        }
        return this->array[index];
    };
    T remove(int index) {
        T obj = this->array[index];
        for(int i = index; i < this->n; i++) {
            this->array[i] = this->array[i+1];
        }
        this->n--;
        this->current--;
        return obj;
    };
};

#endif