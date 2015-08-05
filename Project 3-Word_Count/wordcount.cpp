Upload: wordcount.cpp
Type: text/x-c++src
Size: 1.9765625 Kb
Upload complete. Save this receipt for your records:

Receipt: f940080c2d7b3fa3b6b594789e8723a2aeec8567

Below is the content of your submission

========== START OF FILE ==========

/*ROBIN NAG
 * CSc103 Project 3: wordcount++
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: C++ book, instructor office, youtube.
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 20
 */

#include <iostream>
using namespace std;
#include <string>
using std::string;
#include <set>
using std::set;

// write this function to help you out with the computation
unsigned long countWords(const string& s, set<string>& wl) {
int count = 0;
int alpha;
string s1;
bool x = false; //false when white space

for(alpha = 0; alpha <= s.length()-1 ; alpha++){
	
		if(s[alpha] == ' '|| s[alpha]== '\t'){
		
			if(x == true ){
			
				wl.insert(s1);//insert in set
					count++;//up count of word
		}
		
		x = false;//false
	}

		else{
				if(x==false){
					s1 = s[alpha];
		}
			else{
					s1 += s[alpha];
				}
					x = true;
	}
	
		if(alpha==s.length()-1 && x == true){
				wl.insert(s1);
					count++;
	}

}

return count;// returns number of words
}



int main() {

	unsigned long linecount=0;
	unsigned long wcount = 0;
	unsigned long chcount = 0;
	unsigned long n = 0;
	string s;
	set <string> lines, words;
	bool newLine = true;
	char c;
	
	while (getline(cin,s)){
		
		if(s.empty()){
			linecount++;
				chcount++;
		
		if(newLine){
			newLine=false;
			n++;
			}
		}
			else{
			
				linecount++; //add new line
				lines.insert(s);
				chcount = chcount + s.length();
				chcount++;
				wcount = countWords(s,words)+wcount;// call function 
		}
	}	
	
	cout<<linecount<<"\t";//line count
	cout<<wcount<<"\t"; //word count;
	cout<<chcount<<"\t";//character count
	cout<<lines.size()+n<<"\t";//unique lines
	cout<<words.size()<<endl;//unique word
	
	
	return 0;

}


========== END OF FILE ========== 