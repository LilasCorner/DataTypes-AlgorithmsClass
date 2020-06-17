/* Lila Zayed
Z1838117
CSCI340-3
I certify that this is my own work and where appropriate an extension
of the starter code provided for the assignment.
*/

#include "assignment02.h"

//Implementation for open_files
void open_files(ifstream &is1, ifstream &is2 ){
	
	is1.open(FILE1);//Open files
	is2.open(FILE2);
	
	//check to see if one failed to open, terminate if yes
	if (is1.fail() || is2.fail()){ 
		cerr << "File failed to open, exiting.";
		exit(-1);
	}
	
}

//Implementation for read_data
void read_data(ifstream &is, vector <vector<int>> &m){
	
	while (!is.eof()) //while program has not reached end of file,
		for(unsigned int r =0; r < m.size(); r++){ // iterate through rows, 
			for(unsigned int c =0; c < m[r].size(); c++){ // then columns
				is >> m[r][c]; //and append necessary data
			}
		}
}

//Implementation for print_data
void print_data(const vector<vector<int>> &m){
	
	cout << " " << m.size() << " x " << m[0].size();
	
	cout << endl << "----------------------------------------------------------------------" << endl;
	
	for(unsigned int r =0; r < m.size(); r++){ // iterate through rows, 
			for(unsigned int c =0; c < m[r].size(); c++){ // then columns
				cout << setw(ITEM_W) << m[r][c] << " "; //and print necessary data
			}
			cout << endl;
		}
}

//Implementation for gen_data
void gen_data(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C){
	
	for (unsigned int i =0; i < C.size(); i++){ //iterate thru rows of C...
		
		for (unsigned int j=0; j < C[i].size(); j++){ //then cols of C...
			
			for (unsigned int k=0; k < B.size(); k++){ // then rows of B...
				C[i][j] += A[i][k] * B[k][j]; //to multuply matrices :)	
			}
		}
	}
	
}
