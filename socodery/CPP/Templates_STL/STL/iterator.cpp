#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector <vector <int> > v2d_matrix; //Declare 2 dimensional array
	vector <int> A,B;
	vector <vector <int> > :: iterator iter_ii;
	vector <int> :: iterator iter_ij;
	A.push_back(10);
	A.push_back(20);
	A.push_back(30);
	B.push_back(100);
	B.push_back(200);
	B.push_back(300);
	
	v2d_matrix.push_back(A);
	v2d_matrix.push_back(B);
	cout << endl << "Using Iterator " << endl;
	for(iter_ii =v2d_matrix.begin(); iter_ii != v2d_matrix.end(); iter_ii++)
	{
		for(iter_ij = (*iter_ii).begin(); iter_ij != (*iter_ii).end(); iter_ij++)
		{
			cout << *iter_ij << endl;
		}
	}
	return 0;
}


