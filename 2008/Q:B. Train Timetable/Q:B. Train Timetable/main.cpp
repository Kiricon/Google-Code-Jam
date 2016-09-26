//
//  main.cpp
//  Q:B. Train Timetable
//
//  Created by Dominic Valenciana on 9/25/16.
//  Copyright © 2016 Dominic Valenciana. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

class Case {
public:
    int turnaround, starta, startb;
    vector<string> na, nb;
};

vector<string> readFileByLine(string);
vector<Case> parse(vector<string>);
vector<string> split(string, string);

// ###### MAIN  ##########
int main(int argc, const char * argv[]) {
    
    parse(readFileByLine("input.txt"));
    return 0;
}


//####### Parse the lines in to cases ######
vector<Case> parse(vector<string> lines){
    
    int noCases = atoi(lines[0].c_str());
    vector<Case> cases(noCases);
    int index = 1;
    int curr;
    
    for(int c = 0; c < cases.size(); c++){
        
        cases[c].turnaround = atoi(lines[index].c_str());
        index++;
        
        vector<string> timeSlots = split(lines[index], " ");
        int naNum = atoi(timeSlots[0].c_str());
        int nbNum;
        if(timeSlots.size() == 1){
            nbNum = 0;
        }else{
            nbNum = atoi(timeSlots[1].c_str());
        }
        int total =  naNum + nbNum;
        index++;
        
        curr = index;
        for(int i = curr; i < curr+total; i++){
            
            if(i < curr+naNum){
                cases[c].na.push_back(lines[i]);
            }else{
                cases[c].nb.push_back(lines[i]);
            }

            index = i;
        }
        index++;
        
        
    }
    
    
    
    return cases;
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
