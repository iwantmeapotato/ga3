#include<iostream>
#include<fstream>
using namespace std;

class node {
public:
  int data;
  node *left, *right;
  node(int data = 0, node *l = 0, node *r = 0) : data(data), left(l), right(r) {
  }
};


class tree {
public:
  node *root;
  tree() {

  }

node *rotate_r(node *oldroot) {
  node *newroot = oldroot->right;
  newroot->left = oldroot;
  newroot->right->left = oldroot->left->right;

  return newroot;
}

node *rotate_l(node *oldroot) { //bring up branch on right
  node *newroot = oldroot->right;
  newroot->left = oldroot;
  newroot->left->right = oldroot->right->left;

  return newroot;
}

//double rotation if inserted node in interval of violation & prev
//single left rotation prev,
//single right rotation violated
node *rotate_rl(node *old) {
  rotate_r(old->right);
  rotate_l(old);
  return old;
}

node *rotate_lr(node *old) {
  rotate_l(old->left);
  rotate_r(old);
  return old;
}


};
