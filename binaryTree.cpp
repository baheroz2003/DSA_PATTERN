#include <bits/stdc++.h>
using namespace std;
//lca in binary tree
//k sum paths
//height of tree most time in bst log (base 2) n
//bst L < N < R sorted inorder traversal

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node(int data){
        this->data = data;
        left = right = nullptr;
    }
};

void preOrder(Node* node){
    //base case
    if(node == NULL) return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node* node){
    //base case
    if(node == NULL) return;
    
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void postOrder(Node* node){
    //base case
    if(node == NULL) return;
    
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        for(int i=0; i<size; i++){
            Node* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

vector<int> preOrderTraversal(Node* root){
    vector<int> preOrder;
    if(root == NULL) return preOrder;

    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        preOrder.push_back(node->data);

        if(node->right != NULL) s.push(node->right);
        if(node->left != NULL) s.push(node->left);
    }
    return preOrder;
}

vector<int> inOrderTraversal(Node* root){
    vector<int> inOrder;
    if(root == NULL) return inOrder;

    stack<Node*> s;
    Node* node = root;

    while(true){
        if(node != NULL){
            s.push(node);
            node = node->left;
        }
        else{
            if(s.empty()) break;

            node = s.top();
            s.pop();
            inOrder.push_back(node->data);
            node = node->right;
        }
    }
    return inOrder;
}

vector<int> postOrderTraversal(Node* root){
    vector<int> postOrder;
    if(root == NULL) return postOrder;

    stack<Node*> s1, s2;
    s1.push(root);

    while(!s1.empty()){
        Node* node = s1.top();
        s1.pop();
        s2.push(node);

        if(root->left != NULL) s1.push(root->left);
        if(root->right != NULL) s1.push(root->right);
    }
    while(!s2.empty()){
        postOrder.push_back(s2.top()->data);
        s2.pop();
    }
    return postOrder;
}

vector<int> postOrderTraversal1stack(Node* root){
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
}