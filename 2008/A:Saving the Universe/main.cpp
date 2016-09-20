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



int main() {
  //cout << readFile("Input.txt").split("\n"));
  vector<string> arr = split(readFile("input.txt"), "\n");
  for(int i = 0; i < sizeof(arr); i++){
    cout << "Line: "<< arr[i] << "\n";
  }
  return 0;
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
