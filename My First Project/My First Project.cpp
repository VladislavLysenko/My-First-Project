//the program read words from text file and return by word in random order using Fisher Algorithm
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using std::vector;
using std::string;

void create_file(void);
void check_file(void);

int read_file(vector<string>& words);
int* shuffle(int);


int main(void) {

	vector<string> words; //create vector to words, which to be read from text file.
	check_file();
	read_file(words); //read words from file
	int size = words.size(); //find out the size of the vector
	std::cout << "SIZE: " << size << '\n';
	int* indexes; //create int type pointer
	indexes = shuffle(size); //pointer point to array, which mixed by Fisher algorithm
	std::cout << "Want to start? Y/N\n";
	char answer;
	std::cin.get(answer).get(); //read the answer, which user entered
	while (answer == 'Y' || answer == 'y') {
		for (int i = 0; i < size; i++) {
			std::cout << "Word: " << i + 1 << " from " << size << '\n'; //read words from array
			std::cout << words[indexes[i]] << '\n';
			std::cin.get(); //waiting to user input
		}
		std::cout << "Want repead? Y/N\n";
		std::cin.get(answer).get(); //read answer from user, after, read \0 character, generaterated with button <Enter>
		delete[] indexes;
		indexes = shuffle(size);

	}
	//clear dedicated memory
	return 0;
}

void create_file(void) {
	std::ofstream File;
	File.open("Words.txt");
	File.close();
}

void check_file(void) {
	std::ifstream File;
	File.open("Words.txt");
	if (!File) {
		create_file();
		std::cout << "File created\n";
	}
	File.close();
}

int read_file(vector<string>& words) {
	string word; //varriable, where will stored words from file

	std::ifstream fwords; //create object fword, ifstream classe
	int size = 0; //count of words
	fwords.open("Words.txt"); //open file Words.txt
	if (!fwords) { //open file check
		std::cout << "File created\n";
	}
	while (fwords.good()) {
		fwords >> word; //read words from file
		words.push_back(word); //add a word to the end of the vector
		size++; //increase counter of words
	}

	if (fwords.eof()) { //if end of file reached
		std::cout << "End of file reached\nWord readed: " << size << '\n';
		fwords.close();
		return 0;
	}
	else { //if uknow error
		std::cout << "Total error, reading is stoped\n";
		fwords.close();
		return 1;
	}
}

int* shuffle(int size) {
	//Fisher algorithm
	srand(time(NULL));
	int* arr = new int[size]; //create arr fro 0 to size (0, 1, 2...)
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	for (int i = size - 1; i >= 1; i--) { //start loop from end of arr
		int tmp = arr[i]; //create the varriable, where save the arr item
		int rnd = rand() % (i + 1); //random value from 0 to i
		//swith elements
		arr[i] = arr[rnd];
		arr[rnd] = tmp;
	}
	return arr;
}
