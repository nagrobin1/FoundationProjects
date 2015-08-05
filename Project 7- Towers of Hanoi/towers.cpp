/*
 * CSc103 Project 7: Towers of Hanoi
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 15
 *
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> // to parse long arguments.
#include <cstdlib> // for atoi function
using namespace std;

void towers(int Dnum, int primaryPeg, int finalPeg, bool baseCase){
int interm_Peg;

	if (Dnum == 1 && baseCase) {
	cout <<"Move disk "<<Dnum<<" from "<<primaryPeg<<" to "<<finalPeg<<endl;
	return;
	}
	
	if (Dnum == 1) {
	cout<<primaryPeg<<'\t'<<finalPeg<< endl;
	}
	
	else {
	interm_Peg = 6 - primaryPeg - finalPeg;
	towers(Dnum - 1, primaryPeg, interm_Peg, baseCase);
	
	if (baseCase) {
	cout <<"Moving disk "<<Dnum<<" from "<<primaryPeg<<" to "<<finalPeg<<endl;
	}
	
	else {
	cout<<primaryPeg<<endl;
	cout<<finalPeg<< endl;
	}
	
	towers(Dnum - 1, interm_Peg, finalPeg, baseCase);
}
}

int main(int argc, char *argv[]) {
	// define long options
	static struct option optsLong[] = {
		{"pegBeg",        required_argument, 0, 's'},
		{"end",          required_argument, 0, 'e'},
		{"num-disks",    required_argument, 0, 'n'},
		{"interactive",  no_argument,       0, 'i'},
		{"baseCase",      no_argument,       0, 'v'},
		{0,0,0,0} // this denotes the end of our options.
	};

int optIndex = 0;
int pegBeg = 0;
int pegFin = 0;
int disks = 0;
bool base = false;
char c;

while ((c = getopt_long(argc, argv, "s:e:n:iv", optsLong, &optIndex)) != -1) {
	switch (c) {
		case 's':
		pegBeg = atoi(optarg);
		break;
		
	case 'e':
		pegFin = atoi(optarg);
	break;
	
	case 'n':
		disks = atoi(optarg);
	break;
	
	case 'i':
		cout << "How many disks?"<<endl;
		cin >> disks;
		cout << "From which peg?"<<endl;
		cin>> pegBeg;
		cout << "To which peg?"<<endl;
		cin >> pegFin;
	break;
	
	case 'v':
		base = true;
		cout << "Solution: "<<endl;
		towers(disks,pegBeg,pegFin,base);
	break;
	
	case '?':
	return 1;
		}
	}
towers(disks,pegBeg, pegFin, base);
return 0;
}

