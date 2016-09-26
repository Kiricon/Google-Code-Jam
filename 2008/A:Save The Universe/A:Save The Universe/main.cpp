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
void writeFile(string);

class Case {
public:
  vector<string> engines, queries;
};

class Match {
public:
  int index;
  int matches;
};

vector<vector<int> > findMatches(vector<Case>);
vector<Case> parse(vector<string> arr);
string solve(vector<vector<int> > totalMatches, vector<Case> cases);
int pickEngine(vector<int>, int, vector<string>, string);


int main() {
  //cout << readFile("Input.txt").split("\n"));
  vector<string> arr = split(readFile("A-small-practice.in"), "\n");
  vector<Case> runs = parse(arr);
  //string output = solve(runs);
  vector<vector <int> > totalMatches = findMatches(runs);
  writeFile(solve(totalMatches, runs));

  return 0;
}

//Solve the problem and return a string with output
string solve(vector<vector<int> > totalMatches, vector<Case> cases){

  string answer = "";
  for(int i = 0; i < cases.size(); i++){
    
    int switches = 0;
    if(cases[i].queries.size() > 0){
    int engineIndex = pickEngine(totalMatches[i], int(totalMatches[i].size()), cases[i].engines, cases[i].queries[0]);
    
    string output = "";
    
    for(int q = 0; q < cases[i].queries.size(); q++){
      if(cases[i].queries[q] == cases[i].engines[engineIndex]){
        totalMatches[i][engineIndex]--;
        switches++;
        engineIndex = pickEngine(totalMatches[i], engineIndex, cases[i].engines, cases[i].queries[q]);
        
      }else{
        for( int z = 0; z < cases[i].engines.size(); z++){
          if(cases[i].engines[z] == cases[i].queries[q]){
            totalMatches[i][z]--;
          }
        }
      }
    }
    }
    
    
    
    answer += "Case #"+to_string(i+1)+": "+to_string(switches)+"\n";
  }


  return answer;
}

void writeFile(string output){
  
  ofstream myfile;
  myfile.open("ouput.txt");
  myfile << output;
  myfile.close();
  
}
int pickEngine(vector<int> matches, int last, vector<string> engines, string query){
  
  int index = 0;
  int bestPick = 30000;
  
  for(int i = 0; i < matches.size(); i++){
    if(matches[i] < bestPick && i != last  && engines[i] != query){
      index = i;
      bestPick = matches[i];
    }
  }
  
  return index;
  
}


//Find the number of matches per engine.
vector<vector<int> > findMatches(vector<Case> Cases){

  vector<vector<int> > allMatches;

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

    allMatches.push_back(matches);
    cout << "Match: "<< i << "[";

    for(int m = 0; m < matches.size(); m++){
      cout << matches[m] << ", ";
    }

    cout << "]\n";



  }

  return allMatches;

}



//Parse out the array of string delemited by line in to cases, queries and engines
vector<Case> parse ( vector<string> arr){
  
  //int cases = atoi(arr[0].c_str());
  int cases = atoi(arr[0].c_str());
  int index = 0;
  int curr, no;
  vector<Case> run(cases);
  
  for(int c = 0; c < cases; c++){
    
    //Find Search engines for specific case
    curr = index+1;
    no = atoi(arr[curr].c_str()) + curr;
    
    for(int i = curr+1; i <= no; i++ ){
      run[c].engines.push_back(arr[i]);
      index = i;
    }
    
    //Find Search queries for specific case
    curr = index+1;
    no = atoi(arr[curr].c_str()) + curr;
    
    for(int i = curr; i <= no; i++ ){
      if(i != curr){
      run[c].queries.push_back(arr[i]);
      }
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
