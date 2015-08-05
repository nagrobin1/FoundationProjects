Upload: fsm.cpp
Type: text/x-c++src
Size: 2.7265625 Kb
Upload complete. Save this receipt for your records:

Receipt: e384389d25abf73ded06181f5676e08f57982f0c

Below is the content of your submission

========== START OF FILE ==========

/*Robin Nag
 * CSc103 Project 5: Syntax highlighting, part one.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: Youtube, C++ book
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 17
 */

#include "fsm.h" // header file
using namespace cppfsm;// use of enum for states
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// make sure this function returns the old state.  See the header
// file for details.
int cppfsm::updateState(int& state, char c) {
	// TODO:  write this function.
	int initial_state = state; // first state stored here. will be returned later
	
	const int s1 = readesc;// just read backslash from strlit state (start of escape seq)
	const int s2 = readfs;	// just read forward slash while scanning a numeric constant
							// or identifier, or from the start state.
	const int s3 = start;//the start state
	const int s4 = strlit;// we're scanning a string literal (int quotes: "")
	const int s5 = scanid; // we are in the middle of scanning an identifier
	const int s6 = scannum; // in the middle of scanning a numeric constant
	const int s7 = comment; // we are scanning a comment
	const int s8 = error; // error state; read a messed up numeric or escape sequence.
	
	// use switch to alternate between fsm states
	//#define INSET(x,S) (S.find(x) != S.end()), will call function to check . Use INSET (with character)
	
	switch (state) { // states s1 thru s8
	
case s1:
	if(INSET(c,escseq)){
		state = s4;} 
		else{
			state = s8;}
	break;//exit
	
case s2:
	if(INSET(c,ident_st)){
		state = s5;}
		else{ 
			if(INSET(c,num)){
			state = s6; }
		else{ 
			if(c == '"'){
			state = s4;}
		else{
			if(c == '/'){
			state = s7;}
		}
	}
}
break;
	
case s3:
	if(c == '"'){
		state = s4;}
		else{ 
			if(INSET(c,num)){
			state = s6;}
		else{ 
			if(c == '/'){
			state = s2;}
		else{ 
			if(INSET(c,ident_st)){
			state = s5;}
		}
	}
}
		
	break;
			
case s4:
	if(c == '"'){
		state = s3;}
		else{ 
			if(c == '\\'){
		state = s1;}
		}
	break;
			
case s5:
	if(INSET(c,iddelim)){
		state = s3;}
		else{ 
			if(c == '"'){
		state = s4;}
		else{ 
			if(c == '/'){
		state = s2;}
	}
}
break;
			
case s6:
	if(c == '/'){
		state = s2;}
		else{ 
			if(INSET(c,iddelim)){
		state = s3;}
		else{ 
			if(INSET(c,num)){
		state = s6; }
		else{
		state = s8;}
	}
}
break;
			
case s7:
	break;
			default: 
	break;	
}
	
return initial_state;// original state value 
}


========== END OF FILE ========== 