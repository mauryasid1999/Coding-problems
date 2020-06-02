#include<stack>

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here

    if(root==NULL){return;}

    stack<BinaryTreeNode<int>*>s1;
    stack<BinaryTreeNode<int>*>s2;

    s1.push(root);
    while(s1.empty()==false || s2.empty()==false){

    while(s1.empty()==false){

        BinaryTreeNode <int> *temp=s1.top();
        s1.pop();

        cout<<temp->data<<" ";

        if(temp->left){
            s2.push(temp->left);
        }
        if(temp->right!=NULL){
            s2.push(temp->right);
        }

    }
    cout<<endl;
    while(s2.empty()==false){
        BinaryTreeNode<int> *temp1=s2.top();
        s2.pop();
        cout<<temp1->data<<" ";
        if(temp1->right!=NULL){
            s1.push(temp1->right);
        }
        if(temp1->left!=NULL){
            s1.push(temp1->left);
        }

    }
    cout<<endl;

    }
}
#include <iostream>
#include <queue>
#include <stack>

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}

