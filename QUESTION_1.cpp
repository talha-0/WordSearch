//#include <iostream>
//#include <cstdlib>
//#include<fstream>
//#include<string.h>
//using namespace std;
//
//int maxSize(string* words,int totalWords); //returns maximum word length
//void setWords(string*& words, int totalWords);//makes every word uppercase
//char** grid(string* words,int totalWords,int& size);//complete grid randomly after adding words at random pos
//bool addWord(char**& grid, string word, int rc);//adds given word at random position in grid
//void fill(char**& grid, int rc);//generates random alphabets at empty spaces
//
//int main() {
//
//	fstream fin("words.txt");
//
//	int totalWords = 0;
//	for (; !fin.eof(); totalWords++) {
//		string word;
//		fin >> word;
//	}
//
//	fin.close();
//	fin.open("words.txt");
//	string *words=new string [totalWords];
//	for (int i = 0; !fin.eof() && i < totalWords; i++)
//		fin >> words[i];
//
//	setWords(words, totalWords);
//	int size=maxSize(words, totalWords);
//	cout << "Grid : \n\n";
//	char** game=grid(words,totalWords, size);
//
//	system("pause");
//
//	return 0;
//}
//int maxSize(string* words,int totalWords) {
//	int max = 0;
//	
//	for (int i = 0; i < totalWords; i++) {
//		int size = 0;
//		size=words[i].size();
//		if (size > max) 
//			max = size;
//	}
//	return max;
//}
//void setWords(string*& words, int totalWords) {
//	for (int i = 0; i < totalWords; i++) {
//		for (int j = 0; j < words[i].size(); j++) {
//			if (words[i].at(j) >= 'a' && words[i].at(j) <= 'z')
//				words[i].at(j) -= 32;
//		}
//	}
//}
//char** grid(string* words, int totalWords, int& size) {
//	if (totalWords > size)
//		size = totalWords;
//	size *= 2;
//	char** grid = new char* [size];
//	for (int i = 0; i < size; i++) {
//		grid[i] = new char[size];
//		for (int fill = 0; fill < size; fill++)
//			grid[i][fill] = 0;
//	}
//	srand((unsigned)time(0));
//	for (int i = 0; i < totalWords;) {
//		if (addWord(grid, words[i], size))
//			i++;
//	}
//	fill(grid, size);
//	ofstream fout;
//	fout.open("grid.txt");
//	fout << size << endl;
//	for (int row = 0; row < size; row++) {
//		for (int col = 0; col < size; col++) {
//			fout << grid[row][col] << " ";
//			cout << grid[row][col] << " ";
//		}
//		cout << endl;
//		fout << endl;
//	}
//	return grid;
//}
//bool addWord(char**& grid, string word,int rc) {
//	int type = rand() % 8;
//	int r, c;
//	int size = word.size();
//	
//	r = rand() % rc;
//	c = rand() % rc;
//	if (type == 0) {
//		while ((c + size) > rc) {
//			r = rand() % rc;
//			c = rand() % rc;
//		}
//		for (int i = 0; i < size; i++) {
//			if (grid[r][c + i] != 0 && grid[r][c + i] != word.at(i))
//				return false;
//		}
//		for (int i = 0; i < word.size(); i++)
//			grid[r][c + i] = word.at(i);
//	}
//	else if (type == 1) {
//		while ((c - word.size()) <0) {
//			r = rand() % rc;
//			c = rand() % rc;
//		}
//		for (int i = 0; i < word.size(); i++) {
//			if (grid[r][c - i] != 0 && grid[r][c - i] != word.at(i))
//				return false;
//		}
//		for (int i = 0; i < word.size(); i++)
//			grid[r][c - i] = word.at(i);
//	}
//	else if (type == 2) {
//		while ((r + word.size()) > rc) {
//			r = rand() % rc;
//			c = rand() % rc;
//		}
//		for (int i = 0; i < word.size(); i++) {
//			if (grid[r + i][c] != 0 && grid[r + i][c] != word.at(i))
//				return false;
//		}
//		for (int i = 0; i < word.size(); i++)
//			grid[r+i][c] = word.at(i);
//	}
//	else if (type == 3) {
//		 while ((r - size) < 0) {
//			 r = rand() % rc;
//			 c = rand() % rc;
//		 }
//		for (int i = 0; i < size; i++) {
//			if (grid[r - i][c] != 0 && grid[r -i][c] != word.at(i))
//				return false;
//		}
//		for (int i = 0; i < size; i++)
//			grid[r-i][c] = word.at(i);
//	}
//	else if (type == 4) {
//		while ((r + word.size()) > rc || (c + word.size() )> rc) {
//			r = rand() % rc;
//			c = rand() % rc;
//		}
//		for (int i = 0; i < word.size(); i++) {
//			if (grid[r + i][c + i] != 0 && grid[r + i][c + i] != word.at(i))
//				return false;
//		}
//		for (int i = 0; i < word.size(); i++)
//			grid[r + i][c+i] = word.at(i);
//	}
//	else if (type == 5) {
//		while (((r -size) <0 )|| ((c - size)<0)) {
//			r = rand() % rc;
//			c = rand() % rc;
//		}
//		for (int i = 0; i < size; i++) {
//			if (grid[r - i][c - i] != 0 && grid[r - i][c - i] != word.at(i))
//				return false;
//		}
//		for (int i = 0; i < word.size(); i++)
//			grid[r - i][c - i] = word.at(i);
//	}
//	else if (type == 6) {
//		while ((r + size) > rc || (c - size )< 0) {
//			r = rand() % rc;
//			c = rand() % rc;
//		}
//		for (int i = 0; i < word.size(); i++) {
//			if (grid[r + i][c - i] != 0 && grid[r + i][c - i] != word.at(i))
//				return false;
//		}
//		for (int i = 0; i < word.size(); i++)
//			grid[r + i][c - i] = word.at(i);
//	}
//	else if (type == 7) {
//		while (c + size > rc || r - size< 0) {
//			r = rand() % rc;
//			c = rand() % rc;
//		}
//		for (int i = 0; i <size; i++) {
//			if (grid[r - i][c + i] != 0 && grid[r - i][c + i] != word.at(i))
//				return false;
//		}
//		for (int i = 0; i < word.size(); i++)
//			grid[r - i][c + i] = word.at(i);
//	}
//	return true;
//}
//void fill(char**& grid, int rc) {
//	for (int r = 0; r < rc; r++) {
//		for (int c = 0; c < rc; c++) {
//			int letter = 0;
//			while (letter < 'A' || letter >'Z')
//				letter = rand() % 26 + 'A';
//			if (grid[r][c] == 0)
//				grid[r][c] = letter;
//		}
//	}
//}