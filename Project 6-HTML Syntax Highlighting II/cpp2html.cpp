Upload: cpp2html.cpp
Type: text/x-c++src
Size: 6.142578125 Kb
Upload complete. Save this receipt for your records:

Receipt: 3fd813972be7910b460a2eed01db9d7f6bbded2d

Below is the content of your submission

========== START OF FILE ==========

/*Robin Nag
 * CSc103 Project 5: Syntax highlighting, part two.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *OUtside tutor to help with the map implementation. C++ reference. Youtube videos from NewBoston on HTML and CSS
	also used c++ books.
	I tried numerous methods but the comment syntax did not work. I only get / not //
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 20 hours or more. This was a long project.
 */




#include "fsm.h"
using namespace cppfsm;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <set>
using std::set;
#include <map>
using std::map;
#include <initializer_list> // for setting up maps without constructors.

// enumeration for our highlighting tags:
enum {
	hlstatement,  // used for "if,else,for,while" etc...
	hlcomment,    // for comments
	hlstrlit,     // for string literals
	hlpreproc,    // for preprocessor directives (e.g., #include)
	hltype,       // for datatypes and similar (e.g. int, char, double)
	hlnumeric,    // for numeric literals (e.g. 1234)
	hlescseq,     // for escape sequences
	hlerror,      // for parse errors, like a bad numeric or invalid escape
	hlident       // for other identifiers.  Probably won't use this.
};

// usually global variables are a bad thing, but for simplicity,
// we'll make an exception here.
// initialize our map with the keywords from our list:
map<string, short> hlmap = {
#include "keywords.txt"
};
// note: the above is not a very standard use of #include...

// map of highlighting spans:
map<int, string> hlspans = {
	{hlstatement, "<span class='statement'>"},
	{hlcomment, "<span class='comment'>"},
	{hlstrlit, "<span class='strlit'>"},
	{hlpreproc, "<span class='preproc'>"},
	{hltype, "<span class='type'>"},
	{hlnumeric, "<span class='numeric'>"},
	{hlescseq, "<span class='escseq'>"},
	{hlerror, "<span class='error'>"}
};
// note: initializing maps as above requires the -std=c++0x compiler flag,
// as well as #include<initializer_list>.  Very convenient though.
// to save some typing, store a variable for the end of these tags:
string spanend = "</span>";

string translateHTMLReserved(char c) {
	switch (c) {
		case '"':
			return "&quot;";
		case '\'':
			return "&apos;";
		case '&':
			return "&amp;";
		case '<':
			return "&lt;";
		case '>':
			return "&gt;";
		case '\t': // make tabs 4 spaces instead.
			return "&nbsp;&nbsp;&nbsp;&nbsp;";
		default:
			char s[2] = {c,0};
			return s;
	}
}

string HTMLCSS(string markup); // prototype

int main() {
	// TODO: write the main program.
	// It may be helpful to break this down and write
	// a function that processes a single line, which
	// you repeatedly call from main().
	
string line;
	
while(getline(cin, line)){
        cout << HTMLCSS(line) << endl; // call function
}
	
	return 0;
}

string HTMLCSS(string markup){ // function to process for html

string recallLine = "";// blank string

int STATE = start; // starting point

	for(unsigned long i = 0; i < markup.length(); i++){
			string temp = ""; // blank
			
			updateState(STATE,markup[i]); // call function from fsm.cpp

        switch(STATE){
		
				case scanid: //Case 1
				
                        while(STATE == scanid){
                                temp = temp + markup[i] ;
									i++; // update counter
                                updateState(STATE,markup[i]);
                        }
						
                        if (STATE!= 1){
                               
							    map<string, short>::iterator it; //to search through map
								
                                it = hlmap.find(temp);
									if (it != hlmap.end()) { // FOUND so now alter
                                        recallLine += hlspans[hlmap[temp]] + temp + spanend + translateHTMLReserved(markup[i]);
                                }
										else {
											recallLine += temp + translateHTMLReserved(markup[i]);
								 }
						 }
                        break;
		
				case readesc: // Case 2
                        temp = temp + translateHTMLReserved(markup[i]);
							i++;
                        if(markup[i]== 'n'){
                                temp = temp + markup[i];
                                recallLine += hlspans[hlescseq] + temp + spanend;
								
                                temp.clear(); // delete content
                                STATE = strlit;
                        }
							 else{
                                temp = temp + markup[i];
                                recallLine += hlspans[hlerror]+ temp + spanend;
                                temp.clear();
                        }
										temp.clear();
                        break;
		
                case start:// Case 3
					
					if(markup[i]!='"')
                        recallLine += translateHTMLReserved(markup[i]);

						if(markup[i]=='"'){
						
							temp = temp + translateHTMLReserved(markup[i]);
							
							recallLine += hlspans[hlstrlit]+temp+spanend;
						}
                       
					    break;



                case strlit: // Case 4
                        temp = temp + markup[i];
						
                        recallLine += hlspans[hlstrlit] + temp + spanend;
						
                        break;


                case scannum: // Case 5
                        
						recallLine += hlspans[hlnumeric] + markup[i] + spanend;
                        
						break;

                case comment: // Case 6
                       
					    recallLine += hlspans[hlcomment] + markup[i] + spanend;
                        
						break;

                case error: // Case 7 of ERR
				
                        temp = temp + markup[i];
                        recallLine += hlspans[hlerror] + temp + spanend;
						
                        break;
						
					case readfs:
                       
					    STATE = comment; // initialize
	        }
	
		}
return recallLine;// process again

}


========== END OF FILE ========== 