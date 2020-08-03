#include <iostream>
using namespace std;

class BinarySearchTree {
  int data;
  BinarySearchTree* left;
  BinarySearchTree* right;

 public:
  BinarySearchTree(int);
  static BinarySearchTree* Insert(BinarySearchTree*, int);
  static void Inoder(BinarySearchTree*);
};
using BST = BinarySearchTree;

BST::BinarySearchTree(int data) : data(data) { left = right = NULL; }
BST* BST::Insert(BST* root, int data) {
  if (root == NULL) {
    return new BinarySearchTree(data);
  }

  if (data <= root->data) {
    root->left = Insert(root->left, data);
  } else {
    root->right = Insert(root->right, data);
  }

  return root;
}

void BST::Inoder(BST* root) {
  if (root == NULL) return;

  if (root->left != NULL) Inoder(root->left);
  cout << root->data << endl;
  if (root->right != NULL) Inoder(root->right);
  return;
}

int main() {
  BST* root = new BinarySearchTree(10);
  BST::Insert(root, 20);
  BST::Insert(root, 80);
  BST::Insert(root, 60);
  BST::Insert(root, 40);
  BST::Insert(root, 30);
  BST::Insert(root, 50);
  BST::Insert(root, 90);

  BST::Inoder(root);
}