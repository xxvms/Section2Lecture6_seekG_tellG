#include <iostream>
#include <fstream>

using namespace std;

int main() {

	/*
	 * tellg - tell get - tell where is the reading pointer
	 * seekg - seek get - set reading pointer at specific position
	 *
	 *
	 * seekg(How_many_bytes_from_the_flag_place, flag);
	 *
	 * flags:
	 * iso::beg - BEGIN - set from beginning (DEFAULT)
	 * iso::end - END - set from the end
	 * iso::cur - CURRENT - set from current position
	 *
	 */

	fstream file;
	file.open("sample.txt", ios::in | ios::binary);
	if (file.is_open())
	{
		string buffer;

		file.seekg(0, ios::end);
		streampos sizOfFile;
		sizOfFile = file.tellg();

		cout << "the size of the file is " << sizOfFile << " bytes " << endl;

		file.seekg(ios::beg);
		//cout << "how many elements " << sizOfFile/ sizeof(buffer) << endl;

		// our poistion is 15
		file.seekg(-5, ios::cur);
		// our position is 10 after above statement

		do{
			file >> buffer;
			cout << buffer << endl;
		}while (!file.eof());

		cout << file.rdstate() << endl;
		if (file.rdstate() == 2)
		{
			cout << "end of FILE" << endl;
			file.clear();
			cout << "I am " << file.tellg() << " bytes away from beggining of the file" << endl;
			cout << endl;
			file >> buffer;
			cout << buffer << endl;
		}

	}


	//cin.get();
	return 0;
}