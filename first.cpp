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


//------------que-2---------------------------


/*

find the minimum value in the binary tree


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
 int minValueInBinaryTree(Node *root){

  if(root == NULL ) return INT_MAX;

      int a = minValueInBinaryTree(root->left);
      int b = minValueInBinaryTree(root->right);

    return min(root->val, min(a,b));
 }
int main(){

 Node *root = new Node(22);
 root->left = new Node(2);
 root->right = new Node(3);
 root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  root->right->right->left = new Node(91);


  cout<<minValueInBinaryTree(root);
  return 0;
}
//--------------------------que-3----------------------------
/*

lc_110
*/


class Solution {
public:
    int mod( int a){
           if(a >= 0) return a;
           return -1 * a;
    }
    int levels(TreeNode *root){
        if(root == NULL ) return 0;
        return 1 + max (levels(root->left), levels(root->right) );
    }
    bool isBalanced(TreeNode* root) {
          if(root == NULL) return true;
          int lstDepth = levels(root->left) -1;
          int rstDepth = levels(root->right)-1;
          if( mod ( lstDepth - rstDepth ) > 1 ) return false;
          bool lst =  isBalanced(root->left);
          bool rst = isBalanced(root->right);
       return (lst && rst);

    }
};


//   ---------------------------------que-4


/* lc_101*/

class Solution {
public:
   bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p == NULL && q == NULL ) return true;
         else if( p == NULL || q == NULL ) return false;
         else if( p->val != q->val ) return false;
         bool lst = isSameTree(p->left, q->left);
           if( lst == false ) return false;
         bool rst = isSameTree(p->right, q->right);
         if( rst == false) return false;
         return true;
    }
  void  InvertTree( TreeNode *root){
         if( root == NULL ) return ;
           swap(root->left,root->right);
            InvertTree(root->left);
            InvertTree(root->right);
  }
    bool isSymmetric(TreeNode* root) {
         
         TreeNode *lst = root->left;
         TreeNode *rst  = root->right;
              InvertTree(rst);
           
          if( isSameTree(lst,rst) ) return true;

           return false;

    }

    
};
