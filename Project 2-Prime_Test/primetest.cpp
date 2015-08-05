Upload: primetest.cpp
Type: text/x-c++src
Size: 0.8779296875 Kb
Upload complete. Save this receipt for your records:

Receipt: bf2b8dac1d3693bffcbd9e880130b4fc262256e6

Below is the content of your submission

========== START OF FILE ==========

/*Robin Nag
 * CSc103 Project 2: prime numbers.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: newboston, learn cpp, and youtube
 *
 */

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

int prime(int n){//primetest function 
    int i;
    if(n == 1) return 0;//zero- not prime
    if(n == 2) return 1;//one- prime
    for(i= 2; i <= ceil(sqrt(n)); i++){
        if(n % i == 0) return 0; //remainder is zero
    }
    return 1;
}

int main()
{
    unsigned long n;
    while(cin >> n){
        cout << prime(n) << endl;
    }
	return 0;
}


========== END OF FILE ========== 