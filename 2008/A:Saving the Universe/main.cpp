#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

string solve(vector<Case>);
vector<string> split(string str, string sep);
string readFile(string fileName);
class Case {
public:
  vector<string> engines, queries;
};

vector<Case> parse(vector<string> arr);



int main() {
  //cout << readFile("Input.txt").split("\n"));
  vector<string> arr = split(readFile("input.txt"), "\n");
  vector<Case> runs = parse(arr);
  solve(runs);
  /*
  for(int i = 0; i < sizeof(arr); i++){
    cout << "Line: "<< arr[i] << "\n";
  } */
  return 0;
}

string solve(<vector>Case Cases){

  string answer = "";

  for(in i = 0; i < Cases; i++){
    
  }

  return answer;
}

vector<Case> parse ( vector<string> arr){

  //int cases = atoi(arr[0].c_str());
  int cases = 1;
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
