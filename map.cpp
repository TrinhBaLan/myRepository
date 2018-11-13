#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
using std::string;
using std::map;
using std::cout;
using std::fstream;
struct lexicographic_order{
	bool operator()(const string &s0, const string &s1) const{

		string str0(s0.length(),' ');
        string str1(s1.length(),' ');
        transform(s0.begin(), s0.end(), str0.begin(), tolower);
        transform(s1.begin(), s1.end(), str1.begin(), tolower);

        if( !str0.empty() && !str1.empty() && str0.at(0) == str1.at(0) ){
            return s0 < s1;
        }
        else {
            return str0 < str1;
        }
	}
};
typedef map<string, int, lexicographic_order> word_count;

int main(){
    word_count wc;
    fstream f;
    f.open("test.in");
    string x;
    while( !f.eof()){
        f >> x;
        wc[x]++;
    }

    word_count::iterator it;

    f.open("test.out");

    for( it = wc.begin(); it != wc.end(); it++){
        cout << it->first << "\t" << it->second<< "\n";
        f << it->first << "\t" << it->second<< "\n";
    }
    f.close();

	return 0;
}
