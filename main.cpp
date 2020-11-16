#include "justify.cpp"
#include <cstdlib>

int main(int argc, char *argv[]) {
	string curr_word;
	int lines;

	if (argc > 1 && atoi(argv[1]) > 0) {
		lines = atoi(argv[1]); 
	}

	else {
		lines = 80;
	}

	vector<string> input;

	while (cin >> curr_word) {
		input.push_back(curr_word);
	}

	Solution Justify;
	vector<string> output = Justify.fullJustify(input, lines);

	for (auto &i : output) {
		cout << i << endl;
	}
}
