#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Tree.h"

template<class T>
class BinaryTree : public Tree<T> {
    private:
        void destroy_tree(TreeNode<T> *leaf) {
            if(leaf!=nullptr)
            {
                destroy_tree(leaf->left);
                destroy_tree(leaf->right);
                delete leaf;
            }
        }
        void insert(T key, TreeNode<T> *leaf) {
            if(key < leaf->key_value)
            {
                if(leaf->left != nullptr)
                    insert(key, leaf->left);
                else {
                    leaf->left= new TreeNode<T>;
                    leaf->left->key_value = key;
                    leaf->left->left = nullptr;    //Sets the left child of the child node to null
                    leaf->left->right = nullptr;   //Sets the right child of the child node to null
                }  
            }
            else if(key >= leaf->key_value)
            {
                if(leaf->right!=nullptr)
                    insert(key, leaf->right);
                else {
                    leaf->right = new TreeNode<T>;
                    leaf->right->key_value = key;
                    leaf->right->left = nullptr;  //Sets the left child of the child node to null
                    leaf->right->right = nullptr; //Sets the right child of the child node to null
                }
            }
        }
        TreeNode<T> *search(T key, TreeNode<T> *leaf) {
            if(leaf != nullptr)
            {
                if(key == leaf->key_value)
                   return leaf;
                if(key<leaf->key_value)
                   return search(key, leaf->left);
                else
                   return search(key, leaf->right);
            }
            else return NULL;
        }

        void preOrderPrint(TreeNode<T> *leaf) {
            printf("%d, ", leaf->key_value);
            if(leaf->left != nullptr)
                this->preOrderPrint(leaf->left);
            if(leaf->right != nullptr)
                this->preOrderPrint(leaf->right);
        }

        void orderPrint(TreeNode<T> *leaf) {
            if(leaf->left != nullptr)
                this->orderPrint(leaf->left);
            printf("%d, ", leaf->key_value);
            if(leaf->right != nullptr)
                this->orderPrint(leaf->right);
        }

        void postOrderPrint(TreeNode<T> *leaf) {
            if(leaf->left != nullptr)
                this->postOrderPrint(leaf->left);
            if(leaf->right != nullptr)
                this->postOrderPrint(leaf->right);
            printf("%d, ", leaf->key_value);
        }
         
        TreeNode<T> *root;
    public:
       BinaryTree() {
           this->root = nullptr;
       }
       ~BinaryTree() {
           this->destroy_tree();
       }
       void insert(T obj) {
           if(this->root!=nullptr)
                this->insert(obj, this->root);
            else
            {
                this->root=new TreeNode<T>;
                this->root->key_value=obj;
                this->root->left=NULL;
                this->root->right=NULL;
            }
       }
       TreeNode<T>* search(T obj) {
           this->search(obj, this->root);
       }
       void destroy_tree() {
           this->destroy_tree(this->root);
       }
       void print() {
           this->preOrderPrint(this->root);
           printf("\n");
           this->orderPrint(this->root);
           printf("\n");
           this->postOrderPrint(this->root);
           printf("\n");
       }
};

#endif