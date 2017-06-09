#include "main.h"


void main(int arc, char* argv[]) {

	
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);

	cout << "Start" << endl;
	container c;
	ClearContainer(c);
	In(c, fin);
	fout << "Filled container. " << endl;
	Sort(c, 0);
	Out(c, fout);
	OutSpheres(c, fout);
	ClearContainer(c);
	fout << "Empty container. " << endl;
	Out(c, fout);
	cout << "Stop" << endl;
}