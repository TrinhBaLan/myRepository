#include <iostream>
#include<vector>
#include<fstream>
using namespace std;
void insertionSort( vector<int> &v){ // sap xep theo thu tu tang dan
	for( int i = 1; i< v.size(); i++){
		int j = i;
		while( j>0 && v.at(j) < v.at(j-1)){
			swap(v.at(j-1),v.at(j));
			j--;
		}
	}
}

int main()
{
	vector<int> v ;
	fstream f;
	f.open("exx2.in");
    while ( !f.eof()){
        int x;
        f >> x;
        v.push_back(x);
    }
	f.close();

	insertionSort(v);

	f.open("exx2.out");
	for( int i = 0; i< v.size(); i++){
        f << v.at(i)<< endl;
	}
	f.close();
 	return 0;
}

