#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> final_ans;
        vector<string>::iterator curr_word = words.begin();
        
        int counter = 0;
        int vector_pos = 0;

        vector<vector<string>> curr_line;
	new_line(curr_line);

        while (curr_word != words.end()) {
		string curr_string = *curr_word;

            if (curr_string.length() + 1 + counter <= maxWidth) {
                counter += curr_string.length() + 1;
                curr_line[vector_pos].push_back(curr_string + " ");
                curr_word++;

		continue;
            }

	    else if (curr_string.length() + counter == maxWidth) {
		    counter = 0;
		    curr_line[vector_pos].push_back(curr_string);

		    vector_pos++;
		    new_line(curr_line);
		    curr_word++;

		    continue;
	    }

	    else {
		    counter = curr_string.length() + 1;
		    vector_pos++;
		    new_line(curr_line);
		    curr_line[vector_pos].push_back(curr_string + " ");
		    curr_word++;

		    continue;
	    }
            
        }

	final_ans = vec_to_str(curr_line);

	vector<string> justified = justify(final_ans, curr_line, maxWidth);

	return justified;
    }

    void new_line(vector<vector<string>>& input) {
	    vector<string> newline;
	    input.push_back(newline);
    }

    vector<string> vec_to_str(vector<vector<string>>& input) {
	    vector<string> output;

	    for (auto &i : input) {
		    string s;
		    for (auto &word : i) s += word;

		    output.push_back(s);
	    }
	    return output;
    }

    vector<string> justify(vector<string>& input, vector<vector<string>>& reference, int line_width) {
	    vector<string> output;
	   int x, k, j = 0;

	    for (auto &i : input) {
		    k = 0;
		    string temp;

		    for (x = 0; x < i.size(); x++) {
			    if (i[x] != ' ') {
				    k++;
			    }
		    }

		    if (i == *(input.end() - 1) ) {
			    if (k > 0) {

				    int difference = line_width - i.size();
				    if (difference > 0) {
					    string extra = whitespace(difference);
					    i += extra;
				    }

				    else {
					    i.resize(i.size() + difference);
				    }

				    output.push_back(i);
			    }
		    }

		    else {
			    //justify
			    int num_spaces = max((reference[j].size() - 1), 1);

			    int space_size = (line_width - k) / num_spaces;
			    int leftover = (line_width - k) % num_spaces;

			    string space = whitespace(space_size);

			    stringstream stream(i);
			    string temp2;

			    int l = 0;
			    while (getline(stream, temp2, ' ')) {
				    if (l == 0) {
					    if (l < leftover) {
						    temp += temp2 + " ";
					    }
					    else {
						    temp += temp2;
					    }
				    }
				    else {
					    if (l < leftover) {
						    temp += space + temp2 + " ";
					    }
					    else {
						    temp += space + temp2;
					    }
				    }
				    l++;
			    }
			     if (temp.length() != line_width) {
				     space = whitespace(line_width - temp.length());
				     temp += space;
			     }

			    output.push_back(temp);
		    }


		    j++;
	    }

	    return output;
    }

    int max(int num1, int num2) {
	    if (num1 >= num2)
		    return num1;
	    else
		    return num2;
    }

    string whitespace(int num) {
	    int x;
	    string output;

	    for (x = 0; x < num; x++) {
		    output += " ";
	    }

	    return output;
    }

};
