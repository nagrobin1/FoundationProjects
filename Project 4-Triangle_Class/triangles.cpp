Upload: triangles.cpp
Type: text/x-c++src
Size: 3.5849609375 Kb
Upload complete. Save this receipt for your records:

Receipt: a5b387c855a1315ca11102aabc1fad3ea42e296d

Below is the content of your submission

========== START OF FILE ==========

/*	Robin Nag
 * CSc103 Project 4: Triangles
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 * C++ book, TheNewBoston Youtube Channel
 *http://stackoverflow.com/questions/2155280/two-equality-operators-in-same-if-condition-are-not-working-as-intended
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 15 hours
 */

#include "triangles.h" // import the prototypes for our triangle class.
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

// note the "triangle::" part.  We need to specify the function's
// FULL name to avoid confusion.  Else, the compiler will think we
// are just defining a new function called "perimeter"
unsigned long triangle::perimeter() {
	return s1+s2+s3;//the sum of all 3 sides
}

unsigned long triangle::area() {
	// TODO: write this function.
	// Note: why is it okay to return an integer here?  Recall that
	// all of our triangles have integer sides, and are right triangles...
	unsigned long triangle_sides [3] = {s1,s2,s3};//array with the three sides of the triangle 
	sort(triangle_sides,triangle_sides+3);//sorts array in ascending order. The hypotnuse is the largest side.
	unsigned long triangle_area = (triangle_sides[0]*triangle_sides[1])/2; //Area using 2 smaller sides
	return triangle_area;
}

void triangle::print() {
	cout << "[" << s1 << "," << s2 << "," << s3 << "]";
}

bool congruent(triangle t1, triangle t2) {//objects t1,t2
	// TODO: write this function.
	unsigned long t1_Csides [3] = {t1.s1,t1.s2,t1.s3};// array of sides of triangle t1
	unsigned long t2_Csides [3] = {t2.s1,t2.s2,t2.s3};// array of sides of triangle t2
	
	sort(t1_Csides,t1_Csides+3);// sort the array of t1_Csides
	sort(t2_Csides,t2_Csides+3);// sort the array of t2_Csides
	
	for (unsigned long i = 0; i < 3; i++){ //loop to check if each side of t1 == side of t2
			
			if (t1_Csides [i] == t2_Csides[i]){ 
				} // empty body
			else {
					return false;}
	}
	return true;
}

bool similar(triangle t1, triangle t2) {//objects t1,t2
	// TODO: write this function.
	double t1_Ssides [3] = {t1.s1,t1.s2,t1.s3};// array of sides of triangle t1
	double t2_Ssides [3] = {t2.s1,t2.s2,t2.s3};// array of sides of triangle t2
	
	sort(t1_Ssides,t1_Ssides+3);// sort the array of t1_Ssides
	sort(t2_Ssides,t2_Ssides+3);// sort the array of t2_Ssides
	
	if ((t1_Ssides[0]/t2_Ssides[0] == t1_Ssides[1]/t2_Ssides[1]) && (t1_Ssides[1]/t2_Ssides[1] == t1_Ssides[2]/t2_Ssides[2])){ 
		return true;
	}
	return false;
}

vector<triangle> findRightTriangles(unsigned long l, unsigned long h) {
	// TODO: find all the right triangles with integer sides,
	// subject to the perimeter bigger than l and less than h
	vector<triangle> retval; // storage for return value.
	

	int restriction = h;// check integer
    for (int a=1; a <= restriction; a++ ) 
	{
        for (int b = a+1; b <= restriction; b++) 
		{
            for(int c = b+1; c<= restriction; c++){
				unsigned long perimeter_tri = a+b+c;
				if (perimeter_tri >= l && perimeter_tri <= h) {
					if(a*a + b*b == c*c){ // pythagorean theorem test
                                triangle eligible(a,b,c); // this triangle fits the requirements 
                                retval.push_back(eligible);
                         }
					}
				}
			}	        
    }
	return retval;
}


========== END OF FILE ========== 