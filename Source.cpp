#include "main.h"


int main(int argc, char* argv[]) 
{

	if (argc != 3)
	{
		cout << "Error. Incorrect command line!" << endl;
		return 0;
	}
	ifstream fin(argv[1]);
	ChckInFile(fin);
	fin.seekg(0, std::ios::end);
	int fileSize = fin.tellg();
	fin.seekg(0, std::ios::beg);
	if (fileSize == 0)
	{
		cout << "Error. Input file is empty." << endl;
		system("pause");
		return 0;
	}

	ofstream fout(argv[2]);
	ChckOutFile(fout);

	cout << "Start" << endl;
	container c;
	ClearContainer(c);
	In(c, fin);
	fout << "Filled container. " << endl;
	Sort(c);
	Out(c, fout);
	OutSpheres(c, fout);
	MultiMethod(&c, fout);
	ClearContainer(c);
	fout << "Empty container. " << endl;
	Out(c, fout);
	cout << "Stop" << endl;
	return 0;
}