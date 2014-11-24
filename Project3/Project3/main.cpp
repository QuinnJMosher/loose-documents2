#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

void main() {

	fstream inFile = fstream("AesopsFables.txt", fstream::in);
	if (!inFile.is_open()) {
		throw("input file not found");
	}

	fstream outFile = fstream("wordcounter.txt", fstream::out);
	if (!outFile.is_open()) {
		throw("output file open failure");
	}

	map<string, unsigned int> wordCount = map<string, unsigned int>();
	set<string> wordList = set<string>();

	string currentWord = "";
	inFile >> currentWord;
	int i = 0;

	while (!inFile.eof()) {
		if (wordCount.find(currentWord) == wordCount.end()) {
			wordCount[currentWord] = 1;
		} else {
			wordCount[currentWord]++;
		}

		if (wordList.find(currentWord) == wordList.end()) {
			wordList.insert(currentWord);
		}

		i++;
		cout << i << " " << currentWord << endl;

		inFile >> currentWord;
	}

	system("cls");

	for (int i = 0; i < wordCount.size(); i++) {
		//cout << wordList.find(wordList.begin() + i) << " " << wordCount.at(wordList.find(wordList.begin() + i)) << endl;
	}

	system("pause");
}