#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void bubbleSort( vector<int> &v){ // sap xep theo thu tu giam dan
	for ( int i = 0; i< v.size()-1; i++){
		for( int j = 0; j< v.size()-i -1; j++){
			if( v.at(j)< v.at(j+1) ){
				swap(v.at(j),v.at(j+1));
			}
		}
	}
}
int main()
{
	vector<int> v ;
	fstream f;
	f.open("exx1.in");
    while ( !f.eof()){
        int x;
        f >> x;
        v.push_back(x);
    }
	f.close();

	bubbleSort(v);

	f.open("exx1.out");
	for( int i = 0; i< v.size(); i++){
        f << v.at(i)<< endl;
	}
	f.close();
 	return 0;
}

