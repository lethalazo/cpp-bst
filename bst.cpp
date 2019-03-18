// Implemented a "sorted" binary tree and a traversal algorithm
#include <iostream>
#include <string>
#include <memory>

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

//makes an array of given size, fills it, inserts every element in a bst and prints the tree.
void fill_and_print(unsigned int size){
  int values[size];
  unique_ptr<Node> root(new Node(values[0]));
  srand((unsigned)time(0));
  
  for(unsigned int i=0; i<size; i++){ 
      values[i] = (rand()%100)+1;
      if(i == 0) root->set_value(values[i]);
      else root->insert(values[i]);
  }
  
  root->printTree();
  delete[] values;
}

int main()
{
  unique_ptr<Node> root(new Node(15));
  root->insert(12);
  root->insert(15);
  root->insert(16);
  root->insert(13);
  root->insert(19);
  root->insert(21);
  root->insert(0);
  root->printTree();
  cout << "\n" << "Printing a random sorted binary tree: ";
  fill_and_print(30); //prints a sorted tree of 30 elements
}
