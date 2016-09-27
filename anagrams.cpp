// anagrams.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class anagrams {
public: 
	anagrams()
	{
	}

	// Load Dictionary
	bool LoadDictionary(string strDic)
	{
		std::ifstream infile(strDic);
		string word;

		if (infile.fail())
		{
			return false;
		}
		
		while (!infile.eof())
		{
			infile >> word;
			string sortedWord = word;
			sort(sortedWord.begin(), sortedWord.end());
			
			m_dict[sortedWord].push_back(word);
		}

		return true;
	}

	// return all anagrams wor
	vector<string> RetriveAllAnagrams(string key)
	{
		string sortedKey = key;
		sort(sortedKey.begin(), sortedKey.end());
		auto it = m_dict.find(sortedKey);
		if (it != m_dict.end())
		{ 
			return it->second;
		}
		
		return vector<string>();
	}
private:
	map<string, vector<string>> m_dict;
};


int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "anagrams.exe dictory.txt word" << endl;
	}
	else
	{
		string strDict(argv[1]);
		string word(argv[2]);


		anagrams a;
		if (!a.LoadDictionary(strDict))
		{
			cout << " this is no dictionary, please check if file name is correct? " << endl;
			return 0;
		}

		vector<string> rVec = a.RetriveAllAnagrams(word);
		if (rVec.empty())
		{
			cout << " there is no Anagrams for " << word << endl;
		}
		else
		{
			for each(string elem in rVec)
			{
				cout << elem << endl;
			}
		}
	}

    return 0;
}

