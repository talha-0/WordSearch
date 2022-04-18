#include <iostream>
#include <cstdlib>
#include<fstream>
#include<string.h>
using namespace std;
void wordsearch(char** grid, int r,int c,string word) {
	ofstream fout;
	fout.open("output.txt",ios::app);
	int size=word.size();

	for (int i = 0; i < r; i++){//horizontal ltor
		for (int j = 0; j+size-1 < c; j++){
			if (grid[i][j] == word.at(0)){
				int k;
				for (k = 1; k < size && grid[i][j + k] == word.at(k);k++);
				if (k == size) {
					fout << "{" << i << "," << j << "}" << "{" << i << "," << j + k-1 << "}\n";
					fout.close();
					return;
				}
			}
		}
	}
	for (int i = 0; i < c; i++) {//vertical from up to down
		for (int j = 0; j + size-1 < r; j++) {
			if (grid[j][i] == word.at(0)) {
				int k;
				for (k = 1; k < size && grid[j+k][i] == word.at(k); k++);
				if (k == size) {
					fout << "{" << j << "," << i << "}" << "{" << j+k-1 << "," << i << "}\n";
					fout.close();
					return;
				}
			}
		}
	}
	for (int i = 0; i < r; i++) {//horizontal rtol
		for (int j = size - 1; j < c; j++) {
			if (grid[i][j] == word.at(0)) {
				int k;
				for (k = 1; k < size && grid[i][j - k] == word.at(k); k++);
				if (k == size) {
					fout << "{" << i << "," << j << "}" << "{" << i << "," << j - k+1 << "}\n";
					fout.close();
					return;
				}
			}
		}
	}
	for (int j = 0; j < c; j++) {//vertical from down to up
		for (int i = size - 1; i < r; i++) {
			if (grid[i][j] == word.at(0)) {
				int k;
				for (k = 1; k < size && grid[i-k][j] == word.at(k); k++);
				if (k == size) {
					fout << "{" << i << "," << j << "}" << "{" << i - k+1 << "," << j << "}\n";
					fout.close();
					return;
				}
			}
		}
	}
	for (int i = 0; i +size-1< r; i++) {//diagonal from top left
		for (int j = 0; j + size-1 < c; j++) {
			if (grid[i][j] == word.at(0)) {
				int k;
				for (k = 1; k < size && grid[i+k][j + k] == word.at(k); k++);
				if (k == size) {
					fout << "{" << i << "," << j << "}" << "{" << i+k-1 << "," << j + k - 1 << "}\n";
					fout.close();
					return;
				}
			}
		}
	}
	for (int i = 0; i + size-1 < r; i++) {//diagonal from top right
		for (int j = size - 1; j < c; j++) {
			if (grid[i][j] == word.at(0)) {
				int k;
				for (k = 1; k < size && grid[i + k][j - k] == word.at(k); k++);
				if (k == size) {
					fout << "{" << i << "," << j << "}" << "{" << i + k - 1 << "," << j - k + 1 << "}\n";
					fout.close();
					return;
				}
			}
		}
	}
	for (int i = size - 1; i < r; i++) {//diagonal from bottom left
		for (int j = 0; j +size-1< c; j++) {
			if (grid[i][j] == word.at(0)) {
				int k;
				for (k = 1; k < size && grid[i - k][j + k] == word.at(k); k++);
				if (k == size) {
					fout << "{" << i << "," << j << "}" << "{" << i - k + 1 << "," << j + k - 1 << "}\n";
					fout.close();
					return;
				}
			}
		}
	}
	for (int i = size - 1; i < r; i++) {//diagonal from bottom right
		for (int j = size - 1; j < c; j++) {
			if (grid[i][j] == word.at(0)) {
				int k;
				for (k = 1; k < size && grid[i - k][j - k] == word.at(k); k++);
				if (k == size) {
					fout << "{" << i << "," << j << "}" << "{" << i - k + 1 << "," << j - k + 1 << "}\n";
					fout.close();
					return;
				}
			}
		}
	}
	fout << "Not found\n";
	fout.close();
}

int main() {
	ifstream fin("input.txt");
	if (!fin) {
		cout << "No Such File As Input.txt\n";
		exit(1);
	}
	int row,col;
	fin >> row >> col;
	char** grid = new char* [row];
	for (int i=0; i<row&&!fin.eof();i++) {
		grid[i] = new char[col];
		for (int j = 0; j < col && !fin.eof(); j++) {
			fin >> grid[i][j];
			if (grid[i][j] >= 'a' && grid[i][j] <= 'z')
				grid[i][j] -= 32;
		}
	}
	int n;
	string word;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> word;
		for (int j = 0; j < word.size(); j++) {
			if (word.at(j) >= 'a' && word.at(j) <= 'z')
				word.at(j) -= 32;
		}
		wordsearch(grid, row, col, word);
	}
	fin.close();
	cout << "done finding\n";
	return 0;
}