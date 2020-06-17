/* Lila Zayed	
Z1838117
Csci340-11
I certify that this is my own work and where appropriate an extension
of the starter code provided for the assignment.
*/

#include "assignment01.h"
#include <iostream>
#include <iomanip>  
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::setw;
using std::sort;

// Add needed constants
const int LOW = 1;
const int HIGH = 10000;
const int VEC_SIZE = 200;
const int SEED = 1;
const int NO_ITEMS = 12;
const int ITEM_W = 5; 

// Add code for genRndNums
 void genRndNums(vector<int> &v){
 	srand(SEED); // seeding srand
 	
 	for (int i =0; i < VEC_SIZE; i++){ 
	 v.push_back((rand() % HIGH + LOW)); // pushing new random num into vector
	 }
 }

// Add code for printVec

 void printVec(const vector<int> &v){
 	int cnt=0;
     
 	for (unsigned int i = 0; i < v.size(); i++){
 	
 		cout << setw(ITEM_W) << v[i] << " "; //printing the vector index with specified space
 		
 		cnt++;
 		
 		if (cnt == NO_ITEMS){ // adding newline every 12 numbers
 			cout << endl;
 			cnt =0;
		 }
	}
 	cout << endl;	
 }

int main() 
{
// Declare vector v
	vector<int> v;

// Generate random numbers to fill vector v	
	genRndNums(v);
// Using STL sort sort v
	sort(v.begin(), v.end());
// Print vector of sorted random numbers
	printVec(v);
    return 1;
}


