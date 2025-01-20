/*

find the product of all the nodes in a binary tree


*/

#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
  	int val;
  	Node *left;
  	Node *right;

  	Node (int val){
  		 this-> val = val;
  		 this->left = NULL;
  		 this->right = NULL;
  	}
};
 int Product (Node *root){
    if(root == NULL) return 1;
 	return root->val * Product(root->left) * Product(root->right);
 }
int main(){

 Node *root = new Node(1);
 root->left = new Node(2);
 root->right = new Node(3);
 root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  cout<<Product(root);
	return 0;
}