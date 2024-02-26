#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>


using namespace std;

int main()
{
	string filename = "tobeornottobe.txt";
	ifstream ifile(filename);
	if (!ifile)
	{
		cout << "error opening file...";
		exit(1);
	}

	vector<string> hamlet;
	set<string> hamletS;
	map<string, int> hamletM;

	string word;
	while (true)
	{
		ifile >> word;
		if (!ifile)
			break;

		/*	bool found = false;
			for (auto x:hamlet)  //look at every word in the vector
				if (x == word)  //if the word is located
				{
					found = true;
					break;
				}
			if (!found)
				hamlet.emplace_back(word);
		*/

		//	hamletS.insert(word);  //insert into the set

		auto it = hamletM.find(word);  //search for word in keys

		if (it == hamletM.end())  //word is not found
			hamletM[word] = 1;
		else
			hamletM[word]++;
	}

	/*for (auto x : hamlet)
		cout << x << "\t";
	*/
	/*for (auto x : hamletS)
		cout << x << "\t";
		*/
	cout << "Frequency\tWord" << endl;
	for (auto x : hamletM)
		cout << x.second << "\t" << x.first << endl;

	system("pause");
	return 0;
}