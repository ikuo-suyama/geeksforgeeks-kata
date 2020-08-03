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
  static BinarySearchTree* Delete(BinarySearchTree*, int);
  static BinarySearchTree* SearchMin(BinarySearchTree*);
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
  if (root == NULL) {
    return;
  }

  if (root->left != NULL) {
    Inoder(root->left);
  }
  cout << root->data << endl;
  if (root->right != NULL) {
    Inoder(root->right);
  }
  return;
}

BST* BST::SearchMin(BST* root) {
  if (root->left != NULL) {
    return SearchMin(root->left);
  }
  return root;
}

BST* BST::Delete(BST* root, int X) {
  // search the target node
  if (root->data < X) {
    root->right = BST::Delete(root->right, X);
  } else if (root->data > X) {
    root->left = BST::Delete(root->left, X);
  } else {
    if (root->left == NULL) {
      BST* tmp = root->right;
      free(root);
      return tmp;
    } else if (root->right == NULL) {
      BST* tmp = root->left;
      free(root);
      return tmp;
    } else {
      // 両方存在する時 - 右側の最小値ノードを 後継者 "inorder successor"
      // として自分と入れ替える
      BST* tmp = BST::SearchMin(root->right);
      root->data = tmp->data;
      root->right = BST::Delete(root->right, tmp->data);
    }
  }
  return root;
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

  printf("\nDelete 60--------------\n");
  BST::Delete(root, 60);
  BST::Inoder(root);
}