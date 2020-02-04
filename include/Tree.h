#ifndef TREE_H
#define TREE_H
#include "Structs.h"

template<class T>
class Tree {
    public:
        virtual void insert(T obj) = 0;
        virtual TreeNode<T>* search(T obj) = 0;
        virtual void destroy_tree() = 0;
        virtual void print() = 0; 
};

#endif //TREE_H