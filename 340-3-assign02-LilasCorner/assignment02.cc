/* Lila Zayed
Z1838117
CSCI340-3
I certify that this is my own work and where appropriate an extension
of the starter code provided for the assignment.
*/

#include "assignment02.h"
#include <fstream>
#include <vector>

using std::vector;
using std::ifstream;
/*
   This program opens two data files for reading. If either file can't
   be opened, it prints an error message on stderr and aborts the
   program. It generates two input matrices from the data in data
   files, then generates a new matrix by multiplying the numbers in
   two input matrices. Finally, it prints all three matrices on
   stdout.
*/

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
void read_data(ifstream &is, vector <vector<int>> &v){
	
	while (!is.eof()){ //while program has not reached end of file,
		is >> v; //and append necessary data
	
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

int main ( )
{
    ifstream is1, is2;          // input file streams
    open_files(is1, is2);    // open input files

    // number of rows and colums in matrices A, B and C
    unsigned nrowsA, ncolsA, nrowsB, ncolsB, nrowsC, ncolsC;

    // read number of rows and colums for input matrices from data
    // files and assign number of rows and colums to resulting
    // matrix from values of input matrices; first two values in
    // data file are number rows and colums of a matrix
    is1 >> nrowsA >> ncolsA; 
    is2 >> nrowsB >> ncolsB;
    nrowsC = nrowsA; 
    ncolsC = ncolsB;

    // define matrices as two-dimensional vectors
    vector<vector<int> > A(nrowsA, vector<int>(ncolsA));
    vector<vector<int> > B(nrowsB, vector<int>(ncolsB));
    vector<vector<int> > C(nrowsC, vector<int>(ncolsC));
    
    // read input values from data files
    read_data(is1, A); 
    read_data(is2, B);

    // generate values for matrix C by multiplying values in
    // matrices A and B, where C = AB
    gen_data(A, B, C);

    // print contents of all matrices on stdout
    cout << "\nMatrix1: "; print_data(A);
    cout << "\nMatrix2: "; print_data(B);
    cout << "\nMatrix3: "; print_data(C);
    cout << endl;

    return 0;
}
