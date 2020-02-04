#ifndef STRUCTS_H
#define STRUCTS_H

template<class T>
struct Node {
   T val;
   Node* next;
};

template<class T>
struct TreeNode
{
  T key_value;
  TreeNode *left;
  TreeNode *right;
};

#endif