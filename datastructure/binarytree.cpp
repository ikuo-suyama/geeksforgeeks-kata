#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int data): data(data) {
    left = NULL;
    right = NULL;
  }
};

void depthFirstTraversal(Node *n) {
  cout << n->data << endl;
  if (n->left != NULL) {
    depthFirstTraversal(n->left);
  }
  if (n->right != NULL) {
    depthFirstTraversal(n->right);
  }
}

int main() {
  Node* root = new Node(0);
  root->left = new Node(1);
  root->right = new Node(2);
  root->right->left = new Node(3);
  root->right->right = new Node(4);

  depthFirstTraversal(root);
}