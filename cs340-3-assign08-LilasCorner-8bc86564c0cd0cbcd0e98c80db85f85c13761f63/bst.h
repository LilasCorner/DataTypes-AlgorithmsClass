/* 
Lila Zayed
z1838117
CSCI340-3
I certify that this is my own work and where appropriate an extension
of the starter code provided for the assignment.
*/

/***********************************************************
Small heads up: the code doesn't produce the correct output upon 
compiling - quarantine life has been troublesome,
and I preferred submitting code that compiled rather than code that crashed
while trying to submit it on time. Have a nice evening!
************************************************************/

#ifndef BST_H
#define BST_H
#include "binTree.h"
#include <iostream>

template <typename T>
class binSTree : public binTree<T>
{
public:
    void insert(const T &x);       // inserts node with value x
    bool search(const T &x) const; // searches leaf with value x
    bool remove(const T &x);       // removes leaf with value x
   
private:
    void insert(Node<T> *&, const T &);      // private version of insert
    bool search(Node<T> *, const T &) const; // private version of search
    void remove(Node<T> *&, const T &);      // private version of remove
    bool leaf(Node<T> *node) const;          // checks if node is leaf
  //  Node<T> minValueNode( Node<T>* node);
};

//public - void insert(const T &x)
//takes data value x and starts recursive call to
//private version of insert to insert the value
template<class T>
void binSTree<T>::insert(const T &x){
	return insert(this->root, x);
}

//public bool search(const T &x)const
//takes data value x and starts recursive call to
//private version of search to verify the value exists
//returns true if the value exists, false if not
template<class T>
bool binSTree<T>::search(const T &x)const{
	if(search(this->root, x)){

		return true;
	}
	return false;
}

//public  bool remove(const T &x)
//First verifies if data value x exists in the Tree by calling the search
//method, and if true, calls the private version of remove to delete the node
//that matches. Returns false otherwise.
template<class T>
bool binSTree<T>::remove(const T &x){
	if(search(x)){
		remove(this->root,x);
		return true;
	}
	return false;
}

/************************PRIVATE METHODS****************************/


//private insert
//Adds data value x into its proper place in the tree, starting at the 
// root Node<T>*&node and workingn downward to find it's proper place.
template <class T>
void binSTree<T>::insert(Node<T> *&node, const T &key){
Node <T>* t = new Node<T>(key,NULL,NULL);
Node<T> * parent;
parent = NULL;

if(node == NULL) node = t; //new tree, establish t as root
else
{
  Node<T>* curr = new Node<T>();
  curr = node;
  while(curr!=NULL)
  {
    parent = curr;

    if(key > curr->data) {
    curr = curr->right;}
    else {
      curr = curr->left;
  }
  }

  if(key < parent->data){
    parent->left = t;
  }
  else{
   parent->right = t;
  }
}

}

//private bool search(Node<T> *node, const T &x) const
//loops through the tree's branches depending on if the data value of the current node
//is greater than or less than the data value we're searching for
//returns true if that data value is found, false otherwise
template<class T>
bool binSTree<T>::search(Node<T> *node, const T &x) const{
	bool found = false;

	Node<T>* curr;
	Node<T>* parent;
	curr = node;
	parent = (Node<T>*)NULL;
	while(curr != NULL)
	{
		if(curr->data == x)
		{
			found = true;
			break;
		}
		else
		{
			parent = curr;
			if(x>curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}


	return found;
}

//private void remove(Node<T> *&root, const T &data)
//traverses tree to find node that needs to be deleted, then determines
//which of the three deletion cases (leaf, one child, two children) to apply
template<class T>
void binSTree<T>::remove(Node<T> *&root, const T &data){
	
Node<T>* parent;
parent = root;

Node<T>* prev;

	
	while(parent != NULL)
	{
	  //leaf deletion
	    if( parent->data == data && leaf(parent)){
	      delete parent;
	      parent = NULL;
	  }
	  //left single child
	  else if(parent->data == data && parent->right == NULL ){
	  	if((prev->right)->data == parent->data){
	  		prev->right = parent->left; //repair right side
		  }
	   	 else {	
	   	 	prev->left = parent->left; //repair left
		}
	   	 
	    delete parent;
	    parent = NULL;
	  }
	  //right single child
	  else if(parent->data == data && parent->left == NULL ){
	   if((prev->right)->data == parent->data){
	  		prev->right = parent->right; //repair right side
		  }
	   	 else {	
	   	 	prev->left = parent->right; // repair left
		} 

	    delete parent;
	    parent = NULL;
	  }
	
	  //two children
	  else if(parent->data == data && parent->right != NULL && root->left != NULL){
	  	
	    Node<T>* temp;
		temp = root;
		
	    while(temp->left != NULL) //find largest leftmost node
	      {
	          temp = (temp->left); 
	      }
	      
	      	root->data = temp->data; //replace root val with largest leftmost node
	      	
	    	delete temp;
		}
		else{ //moving down the tree to find the node
			if (data < parent->data){
				prev = parent;
				parent = parent->left;
			}
			else{
				prev=parent;
				parent=parent->right;
			}
			
		}
	}
}

//private bool leaf(Node<T> *node) const
//checks if a node has children at all, and if it does
//have children, returns false because its not a leaf. 
//returns true otherwise
template <class T>
bool binSTree<T>::leaf(Node<T> *node) const{
	
	if (node == NULL)       
        return false;
        
    if (node->left == NULL && node->right == NULL)      
        return true; 
        
    leaf(node->left); 
    leaf(node->right);

}          

 	

#endif
