//============================================================================
// Name        : TextQuery.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;
using line_no = std::vector<std::string>::size_type;

class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f):
		sought(s), lines(p), file(f)
	{ }
private:
	string sought; // word this query represents
	shared_ptr<set<line_no>> lines; // lines it's on
	shared_ptr<vector<string>> file; // input file
};

ostream& print(std::ostream& os, const QueryResult& result)
{
	for (auto line: *(result.lines))
	{
		os << "(" << line + 1 << ") " << (*result.file)[line] << endl;
	}
	return os;
}

class TextQuery {
public:

	TextQuery(ifstream &infile);
	void print(int type);
	QueryResult query(string searchString);
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> word_map;
};

TextQuery::TextQuery(ifstream &infile): file(new vector<string>){
	{
		if(infile.is_open())
		{
			string text;
			long line_num = 0;
			while(getline (infile, text) )
			{
				file->push_back(text);
				istringstream line(text);
				string word;
				while (line >> word)
				{
					auto &lines = word_map[word]; //
					if (!lines)
					{
						lines.reset(new set<line_no>);
					}
					lines->insert(line_num);
				}
				line_num++;
			}
		}
	}
}

QueryResult TextQuery::query(string searchString) {
	// we'll return a pointer to this set if we don't find sought
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto it = word_map.find(searchString);
	if(it != word_map.end())
	{
		return  QueryResult(searchString, it->second, file);
	}
	else
	{
		return QueryResult(searchString, nodata, file);
	}
}

void TextQuery::print(int type)
{
	switch(type)
	{
		case 1:
			for (auto line: *file)
			{
				cout << line << endl;
			}
			cout << "Number Of lines:" << file->size() << endl;
			break;
		case 2:
			for (auto wordDetails: word_map )
			{
				cout << wordDetails.first << ": ";
				for (auto line_no: *(wordDetails.second))
				{
					cout << line_no << " ";
				}
				cout << endl;
			}
			break;
		default:
			cout << "No action" << endl;
	}
}



void runQueries(ifstream &infile);

int main() {
	string fileName("/Users/sidd/dev/cpp/workspace/TextQuery/src/TextQuery.cpp");
	ifstream infile(fileName);
	if (infile.is_open())
	{
		runQueries(infile);
	}
	return 0;
}


void runQueries(ifstream &infile)
{
	// infile is an ifstream that is the file we want to query
	TextQuery tq(infile); // store the file and build the query map
	// iterate with the user: prompt for a word to find and print results
	//tq.print(2);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		// stop if we hit end-of-file on the input or if a 'q' is entered
		if (!(cin >> s) || s == "q") break;
		// run the query and print the results
		print(cout, tq.query(s)) << endl;
	}
}
