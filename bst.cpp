/** Implemented a "sorted" binary tree and a traversal algorithm, using smart pointers
 *	
 *	@author Arsalan Azmi
 *  @version 1.2, 18th March 2019
 */

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Node{
    
    private:
    int data;
    //left and right nodes
    Node*left;
    Node*right;
    
    public:
    //initialize left and right nodes as nullptrs
    Node(){
        left = nullptr;
        right = nullptr;
    }
    
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
    
    /**
     * Sets the value of the node
     *
     * @param val Value to set
     */
    void set_value(int val){
        data = val;
    }
    
    /**
     * Insert a leaf in the binary tree according to given value.
     *
     * @param val Value to insert
     */
    void insert(int val){
        if(val < data){
            if(left != nullptr) left->insert(val); //if node exists, insert in that node
            else left = new Node(val); //else, create node with given value
        }
        else{
            if(right != nullptr) right->insert(val);
            else right = new Node(val);
        }
    }
    
    /**
     * Traverses the binary tree and prints in-order.
   	 *
	 */
    void printTree(){
    	//check if this node has value
        if(this == nullptr){
            return;
        }
        left->printTree(); //go to left node
        cout << this->data << " "; //print root
        right->printTree(); //go to right node
    }
};

//makes an array of given size, fills it, inserts every element in a bst and prints the tree.
void fill_and_print(unsigned int size){
  int values[size]; //empty array of given size
  unique_ptr<Node> root(new Node(values[0])); //make a unique pinter for our root node.
  srand((unsigned)time(0)); //generate random ints
  
  for(unsigned int i=0; i<size; i++){ 
      values[i] = (rand()%100)+1; //fill array
      if(i == 0) root->set_value(values[i]); //set root value
      else root->insert(values[i]); //insert other values in our tree
  }
  
  root->printTree();
  delete[] values; //delete the array
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
