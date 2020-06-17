/* Lila Zayed
Z1838117
CSCI340-3
I certify that this is my own work and where appropriate an extension
of the starter code provided for the assignment.
*/

#include <algorithm>
#include <map>
#include <utility> 
#include <stdio.h>
#include <cstdio>
#include <ctype.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

using std::cin;
using std::map;
using std::string;
using std::pair;

const int NO_ITEMS =3;
const int ITEM_W =16;
//#define FILE1 "./assignment04.in"

//print_words
//args: const map<string, int>& mappy
//returns: nothing
//purpose: prints words in columns
void print_words(const map<string, int>& mappy){
	int cnt=0;
	int wrd=0;
	
	for(auto i: mappy){
		
		wrd+=i.second;
		cout << std::left << setw(ITEM_W)<< i.first; 
		cout << std::right <<  ":"  << setw(5) << std::left <<i.second ; 
		cnt++;
		
		if (cnt == NO_ITEMS){
			cout << endl;
			cnt=0;
		}
		
		
	}


	cout << endl << "no of words in input stream  : " << wrd;
	cout << endl << "no of words in output stream : " << mappy.size() << endl;
}

//clean_entry
// args: const string& dirty, string& clean
//returns: nothing
//purpose: cleans an entry from leading/following punctuation
void clean_entry(const string& dirty, string& clean){
	
	unsigned int start = 0;
	unsigned int end =0;

	while( !isalnum(dirty[start]) && start < dirty.length() ){ // 
		start++;
		end = start;
	}
	
	while(isalnum(dirty[end]) && (end < dirty.length()))
	
		end++;
		
		if( end == start ){
			clean = "";}

		else {
		
			clean = dirty.substr(start, end-start);
			std::for_each(clean.begin(),clean.end(),[] (char & c){
				c = ::tolower(c);
				});
			return;	
		}
	
}
//	cout << dirty << " " << clean;
	
	

//get_words
// args: map<string, int>& m
//returns: nothing
//purpose: get words from input file, clean them with clean_entry, then add to map if not empty
void get_words(map<string, int>& m){

//	freopen("assignment04.in", "r", stdin);
	
	string dirty;
	string clean;
	
	while(cin) 
	{
	
	cin >> dirty; 
	
	clean_entry( dirty, clean ); //its cleanin time
	
	
	if( clean.size() > 0 ){
	
		m[clean]++; }
	clean.clear();
	}
	
}


int main(){

	map<string,int> mappy;

	get_words(mappy);
	
	print_words(mappy);
	
	return 0;
}


