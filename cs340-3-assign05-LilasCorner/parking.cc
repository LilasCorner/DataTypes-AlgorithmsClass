/* Lila Zayed
Z1838117
CSCI340-3
I certify that this is my own work and where appropriate an extension
of the starter code provided for the assignment.
*/


#include <string>
#include <stdio.h>
#include <string.h>
#include<iostream>
#include <deque> 
#include <stack>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;


typedef struct 
{ 
    int id;         // id starts at 1
    string lp;      // license plate of car
    int no_mv;      // number times the car has been moved
}CAR; 

int cnt =1;

/*
method: arrival
arguments: const CAR &car, deque<CAR> &D
returns: nothing
purpose: Signifies arrival of car in garage, checks to see if theres 
		space in the deque and adds it/lets it drive away based on space
*/
void arrival(const CAR &car, deque<CAR> &D){
	
	cout << "Car " << car.id << " with license plate " << "\"" << car.lp << "\"" << " is arrived." << endl ;
	
	if (D.size() < 10){ //check and see if theres space in garage
		D.push_front(car);
		cout << endl;
	}
	else 
	{
		cout << "    But the garage is full!" << endl << endl;
	}
}

/*
method: departure
arguments: const string &lp, deque<CAR> &D, stack<CAR> &S
returns: nothing
purpose: checks to see if car is present in garage (prints error if its not) then
		 moves all cars ahead of departing car into stack S so it can exit. Cars
	     in stack S are then re-entered into the deque D
*/
void departure(const string &lp, deque<CAR> &D, stack<CAR> &S){
	

	bool carFlag = false;
	int pos =0;
	
	for (auto i: D){
		if (i.lp==lp){ //if license plate is in garage
			carFlag = true;
			break;
		}
		pos++; //incremement parking spot position
	}
	
	if (carFlag ==false){
		cout << "No car with license plate " << "\"" << lp << "\"" << " in garage." << endl << endl;
		return;
	}
	
	for (unsigned int i =pos; i < D.size(); i++){ //increment number ot times moved for  cars ahead of departing vehicle
		D[i].no_mv++;
	}
	
	for (auto i: D){
		S.push(i); //push cars onto stack so vehicle can depart
	}
	
	D.clear(); // empty deque
	
	while(!S.empty()){ //push cars back into deque
		D.push_front(S.top());
		S.pop();
		
	}
	
	
	string s = "";
	
	if(D[pos].no_mv>1){ //if no_mv is more than 1, make cout statement below plural by adding "s"
		s="s";
	}
	
	cout << "Car " << D[pos].id << " with license plate " << "\"" << D[pos].lp << "\"" << " is departed," << endl ;
	cout << "    car was moved " << D[pos].no_mv << " time" << s << " in the garage." << endl << endl; 
	
	D.erase(D.begin()+pos); // remove car from garage

}


/*
method: get_input_vals
arguments: const string &line, char &act, string &lp
returns: nothing
purpose: takes a string (line) from stdinput and tokenizes it 
	 	 into a character (act) and a license plate number (lp)
*/
void get_input_vals(const string &line, char &act, string &lp){
	
	string delim = ":"; // establish delimeter
	
	string action = line.substr(0, line.find(delim)); //find position where delimeter is located and substring up to that position
	
	string tempLP = line.substr(line.find(delim)+1); // find location of next delimeter and substring the rest of the string
	
	tempLP.pop_back(); //remove trailing colon
	
	lp = tempLP; //copy over values
	
	act = action[0]; //copy over values
}



int main () {

//	freopen("parking.in", "r", stdin); // ignore for putty - for windows testing only
	
	deque<CAR> D;
	stack<CAR> S;
	string line;
	char action;
	string license;
 	
	while (getline(cin,line)){ //while recieving from stdinput
		
		
		get_input_vals(line, action, license);	

		
		if (action!='A' && action !='D'){ //checking to see if action is valid
			cerr << '\'' << action << '\'' << ": " << "invalid action!" << endl <<endl;
		continue;}	
		

		CAR arr;
		arr.id = cnt;
		
		bool carFlag = false;
		
		for (auto i: D){ // find out if license plate is already in garage
		if (i.lp==license){
			carFlag = true;
			break;
			}
		}
	
		if (carFlag ==false){ //if license plate NOT in garage, its a new car and needs incrememnted ID
			cnt++;
		}
		
		arr.lp = license;
		arr.no_mv = 0;

		if (action == 'A'){ //if A, arriving
			arrival(arr, D);
		}
		else{ //else has to be a departure since already verified the action is valid
			departure(arr.lp, D, S);
		}
		
	}//end of while
		
	
}

