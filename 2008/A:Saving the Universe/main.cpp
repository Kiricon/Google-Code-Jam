#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;


vector<string> split(string str, string sep);
string readFile(string fileName);

class Case {
public:
  vector<string> engines, queries;
};
void findMatches(vector<Case>);
vector<Case> parse(vector<string> arr);
string solve(vector<Case>);



int main() {
  //cout << readFile("Input.txt").split("\n"));
  vector<string> arr = split(readFile("input.txt"), "\n");
  vector<Case> runs = parse(arr);
  //string output = solve(runs);
  findMatches(runs);
  /*
  for(int i = 0; i < sizeof(arr); i++){
    cout << "Line: "<< arr[i] << "\n";
  } */
  return 0;
}

//Solve the problem and return a string with output
string solve(vector<Case> Cases){

  string answer = "";



  return answer;
}

void findMatches(vector<Case> Cases){

  for(int i = 0; i < Cases.size(); i++){

    Case set = Cases[i];
    vector<int> matches;

    for(int e = 0; e < set.engines.size(); e++){
      int match = 0;
      for(int q = 0; q < set.queries.size(); q++){
        if(set.queries[q] == set.engines[e]){
          match++;
        }
      }

      matches.push_back(match);

    }


    cout << "Match: "<< i << "[";

    for(int m = 0; m < matches.size(); m++){
      cout << matches[m] << ", ";
    }

    cout << "]\n";



  }

}



//Parse out the array of string delemited by line in to cases, queries and engines
vector<Case> parse ( vector<string> arr){

  //int cases = atoi(arr[0].c_str());
  int cases = atoi(arr[0].c_str());
  int index = 1;
  int curr, no;
  vector<Case> run(2);

  for(int c = 0; c < cases; c++){

    //Find Search engines for specific case
    curr = index;
    no = atoi(arr[index].c_str()) +1;
    for(int i = curr+1; i <= no; i++ ){
      run[c].engines.push_back(arr[i]);
      index = i;
    }

    //Find Search queries for specific case
    curr = index;
    no = atoi(arr[index].c_str()) +1;
    for(int i = curr+1; i <= no; i++ ){
      run[c].queries.push_back(arr[i]);
      index = i;
    }

  }
  return run;
}

// Read file and return a string
string readFile(string fileName) {
  ifstream t(fileName);
  string str((istreambuf_iterator<char>(t)),
                  istreambuf_iterator<char>());

  return str;
}
// Splits a string by a delimeter
vector<string> split(string str, string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current != NULL){
        arr.push_back(current);
        current=strtok(NULL, sep.c_str());
    }
    return arr;
}
