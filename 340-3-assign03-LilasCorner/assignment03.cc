/* Lila Zayed	
Z1838117
CSCI340-3
I certify that this is my own work and where appropriate an extension
of the starter code provided for the assignment.
*/


#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>

using std::set;
using std::cout;
using std::endl;
using std::cin;
using std::setw;

const int NO_ITEMS = 16;
const int ITEM_W = 5;


//method name: sieve
//arguments passed: set<int>& s, int n
//return type: void
//purpose: sieves through a list of numbers according to the sieve of Eratosthenes 
//         to fill a set with only the prime numbers up to n
void sieve(set<int>& s, int n)
{
   std::vector<bool> bol;
    
      for (int i = 0; i < n; i++) {
         bol.push_back(true);
      }
      for (int i = 2; i< sqrt(n); i++) {
         if(bol[i] == true) {
            for(int j = (i*i); j<n; j = j+i) {
               bol[j] = false;
            }
         }
   }
   
   
   for (unsigned int i = 2; i< bol.size(); i++) {
         if(bol[i]==true) {
            s.insert(i);
		}
	}
}


//method name: print_primes
//arguments passed: set<int>& s
//return type: void
//purpose: print out the prime numbers stored in set s
void print_primes(const set<int>& s)
{
	cout << endl;
	
	int cnt =0;
	for (auto it=s.begin(); it != s.end(); ++it){
        cnt++;
		cout << setw(ITEM_W) << *it; 
			
		if (cnt ==16){
			cout << endl;
			cnt=0;
		}
		
	}
	
	cout << endl;
}

int
main()
{
	int lim;
	cout << "Upper limit for the set of primes: "; //2000
	cin >> lim;
	 
	set<int> setty;
	
	sieve(setty, lim);
	
	print_primes(setty);
	
	return 0;
}
