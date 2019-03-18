// Implemented a "sorted" binary tree and a traversal algorithm
#include <iostream>
#include <string>

using namespace std;

class Node{
    public:
    
    int data;
    Node*left;
    Node*right;
    
    Node(){
        left = nullptr;
        right = nullptr;
    }
    
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
    
    void set_value(int val){
        data = val;
    }
    
    void insert(int val){
        if(val < data){
            if(left != nullptr) left->insert(val);
            else left = new Node(val);
        }
        else{
            if(right != nullptr) right->insert(val);
            else right = new Node(val);
        }
    }
    
    void printTree(){
        if(this == nullptr){
            return;
        }
        left->printTree();
        cout << this->data << " ";
        right->printTree();
    }
};

int main()
{
  Node root(15);
  root.insert(12);
  root.insert(15);
  root.insert(16);
  root.insert(13);
  root.insert(19);
  root.insert(21);
  root.insert(0);
  root.printTree();
}
