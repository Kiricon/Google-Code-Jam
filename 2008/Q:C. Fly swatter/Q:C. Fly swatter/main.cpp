//
//  main.cpp
//  Q:C. Fly swatter
//
//  Created by Dominic Valenciana on 9/28/16.
//  Copyright © 2016 Dominic Valenciana. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
Class Case {
    long f, R, t, r, g;
}

vector<Case> parse(vector<string> lines);
vector<string> readFileByLine(string name);
void writeFile(string output);
vector<string> split(string str, string sep)



int main(int argc, const char * argv[]) {
    // insert code here...
    readFileByLine("input.txt");
    return 0;
}


vector<Case> parse(vector<string> lines){
    
}

// ########## Read the Input file and return vector of lines ####
vector<string> readFileByLine(string name){
    vector<string> lines;
    ifstream fs(name);
    string line;
    while (getline(fs, line)) {
        lines.push_back(line);
    }
    return lines;
}

// ########## Write to file ####
void writeFile(string output){
    
    ofstream myfile;
    myfile.open("ouput.txt");
    myfile << output;
    myfile.close();
    
}

// Splits a string by a delimeter
vector<string> split(string str, string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current != NULL){
        arr.push_back(current);
        current=strtok(NULL, sep.c_str());
    }
    return arr;
}
