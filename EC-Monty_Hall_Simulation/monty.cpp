Upload: monty.cpp
Type: text/x-c++src
Size: 2.78125 Kb
Upload complete. Save this receipt for your records:

Receipt: 043c611020c9f471a989b5e6ef216493fbeb8c0f

Below is the content of your submission

========== START OF FILE ==========

/*Robin Nag Spring 2015
 * CSc103 Project EC
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: Youtube videos on rand and srand. Also use CPP book. Also looked at explination of Monty Hall Math Problem before writing. 
 *
 */

// for rand(), srand(), and time()
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Randomize(int randnum); // prototype
int AlternateDoor(int D1, int D2) // Doors 1 and 2
{
  int D3;
  if (D1 == D2){
        D3 = Randomize(2);
        if (D3 >= D1)
            D3++;}
  else{
    for (D3 = 0; (D3 == D1) || (D3 == D2); D3++){
    } //
  }
  return D3;
}
int Randomize(int randnum){
  return ((1.0*randnum*rand())/(1.0+RAND_MAX));
}
int main(){
  int win, lose, totalgames,wins_alternate;
  win = 0; lose = 0; totalgames = 1500;
  bool alternate = false;

  for (int i = 1; i <= totalgames; i++){
    cout<<"-------------------------------"<<endl;
	cout<<"Game "<<i<<endl;

    int const WINDOOR = Randomize(3);
	cout<<"Winning door: "<< WINDOOR <<endl;

    int const firstChoice = Randomize(3);
	cout<<"Player picks: "<< firstChoice <<endl;

    int doorOpen = AlternateDoor(firstChoice, WINDOOR);
	cout<< "Host opens door: " <<doorOpen<<endl;
	
		cout<<"If you switch: "<<endl;
    
	int const doorPicked = alternate? AlternateDoor(doorOpen, firstChoice) : firstChoice;

    if (doorPicked == WINDOOR){
		win = win +1;
	  cout<<"You WIN!"<<endl;}
    else{
        cout<<"You Lose!"<<endl;}
  }

  int wins_stay = win; alternate = true; lose = 0; win = 0;
  for (int i = 1; i <= totalgames; i++){
    cout<<"-------------------------------"<<endl;
	cout<<"Game "<< i<<endl;

    int const WINDOOR = Randomize(3);
	cout<<"Winning door: "<<WINDOOR<<endl;

    int const firstChoice = Randomize(3);
	cout<<"Player picks: "<<firstChoice<<endl;

    int doorOpen = AlternateDoor(firstChoice, WINDOOR);
	cout<< "Host Opens Door: " <<doorOpen<<endl;

		cout<<"If you switch: "<<endl;

    int const doorPicked = alternate? AlternateDoor(doorOpen, firstChoice) : firstChoice;

    if (doorPicked == WINDOOR){
        win = win + 1;
        cout<<"You WIN!"<<endl;}
    
	else{
        cout<<"You Lose!"<<endl;}

				wins_alternate = win; // new count
  }
    cout << "====================" << endl;
		cout<<"Total wins when staying: " << wins_stay << " a wining chance of " << (100.0*wins_stay)/totalgames<< "%, "<<endl;
		cout<<"Total wins when switching: " << wins_alternate << " a wining chance of " << (100.0*wins_alternate)/totalgames << "%" <<endl;

    return 0;
}




========== END OF FILE ========== 