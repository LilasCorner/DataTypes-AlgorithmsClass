/* 
Lila Zayed
z1838117
CSCI340-3
I certify that this is my own work and where appropriate an extension
of the starter code provided for the assignment.
*/


/***********************************************************
I arranged with Dr. Papka for a 4/2 due date due to a misunderstanding 
with the Github representation of the due date - I apologize for
any inconvienience this may cause & hope you have a nice day!
************************************************************/

#ifndef H_BINTREE
#define H_BINTREE
#include <stdlib.h>
#include <stdio.h> 
#include "node.h"

using namespace std;

template <typename T> class binTree{

public:
    binTree();                                      // default constructor
    unsigned size() const;                          // returns size of tree
    unsigned height() const;                        // returns height of tree
    virtual void insert(const T&);                  // inserts node in tree
    void inorder(void (*)(const T&));               // inorder traversal of tree

protected:
    Node<T> *root;                                  // root of tree
    
private:
    unsigned size(Node<T> *) const;                 // private version of size()
    unsigned height(Node<T> *) const;               // private version of height() 
    void insert(Node<T> *&, const T&);              // private version of insert() 
    void inorder(Node<T> *, void (*)(const T&));    // private version of inorder()
};

//Random tree selection RNG
typedef enum {left_side, right_side } SIDE;

SIDE rnd(){ 
    return rand()%2 ? right_side : left_side;
}// End of rnd()


/****************************PUBLIC METHODS**********************/

//binTree Constructor
template <class T> binTree<T>::binTree(){
	root = 0;
}

/*
Public Method: unsigned size() const
Purpose - start recursive call into private version of size method
*/
template <class T> unsigned binTree <T>::size() const{
  return size(root); 
}


/*
Public Method: unsigned height() const
Purpose - start recursive call into private version of height method
*/
template <class T> unsigned binTree <T>::height() const{
	return height(root); 
}

/*
Public Method: void insert(const T& temp)
Purpose - Purpose - start recursive call into private version of insert method
*/
template <class T> void binTree <T>::insert(const T& temp){
	return insert(root, temp);
}

/*
Public Method: void inorder(void (*print)(const T&))
Purpose - start recursive call into private version of inorder method
*/

template <class T> void binTree <T>::inorder(void (*print)(const T&)){
	inorder(root, print);
}


/**************************PRIVATE METHODS******************************/



/* 
Private Method: unsigned size(Node <T> * N) const
Purpose: Recursivley calls itself to count every node in the tree, 
	     returning 0 if the tree is empty but making progress to the 
	     base case otherwise
*/
template <class T> unsigned binTree<T>::size(Node<T> * N) const { 
  if (N == NULL) 
  	return(0); // base case
  else { 
    return(size(N->left) + 1 + size(N->right)); 
  } 
} 


/* 
Private Method: unsigned height(Node<T> * N)
Purpose: Returns height of tree by recursivley calling whichever subtree is longer
Assumption: a tree with 1 node = size 1
*/
template <class T> unsigned binTree <T>::height(Node<T> * N) const{
	 if( N == NULL )
   {
       return 1;
   }
   else
   {
   		int leftH = height(N->left);  
        int rightH = height(N->right); 
   	
   	   	if (leftH < rightH){
            return(rightH + 1);}  
        else{
			return(leftH + 1);}
   }
}

/* 
Method: void insert( Node <T>* & N, const T& temp)
Purpose: Inserts node (temp) into tree by two rules:
		 if the tree is empty, new node is root of the tree
		 otherwise, left/right subtree is randomly selected and 
		 temp is inserted in that side
*/
template <class T> void binTree <T>::insert( Node <T>* & N, const T& temp){
	
     if( N == NULL )
   {
       Node <T> * newN;
       newN = new Node <T>(temp);
       N = newN;
   }     
   else
   {
  
       if(rnd())
       {
            insert(N->right, temp);
       }
       else
       {
          insert(N->left, temp);
       }
   }	

}


/* 
Method: void inorder( Node <T>* N, void(*print) (const T&))
Purpose: recursivley sorts a tree according to inorder traversal by traveling to 
		 the left node, root, then right node
*/
template <class T> void binTree <T>::inorder( Node <T>* N, void(*print) (const T&)){
	if( N != NULL )
   {
       inorder( N->left, print);
       print( N->data);
       inorder( N->right, print);
   }
}

#endif
