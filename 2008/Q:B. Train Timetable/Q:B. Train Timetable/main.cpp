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

using namespace std;
class TrainTimes {
public:
    vector<int> departure, arrival;
};
class Case {
public:
    int turnaround, starta, startb;
    TrainTimes na, nb;
};

vector<string> readFileByLine(string);
vector<Case> parse(vector<string>);
vector<string> split(string, string);
string solve(vector<Case>);

// ###### MAIN  ##########
int main(int argc, const char * argv[]) {
    
    vector<Case> cases = parse(readFileByLine("input.txt"));
    solve(cases);
    return 0;
}

// ###### Solve ##########

string solve(vector<Case> cases){
    
    string answer = "";
    
    for(int c = 0; c < cases.size(); c++){
        
        int naStart = 0;
        int nbStart = 0;
        
        //Help with out easy answers. This will just filter out all the wild cards for our sake.
        if(cases[c].na.departure.size() == 0 && cases[c].nb.departure.size() != 0){
            nbStart = int(cases[c].nb.departure.size());
        }else if(cases[c].nb.departure.size() == 0 && cases[c].na.departure.size() != 0){
            naStart = int(cases[c].na.departure.size());
        }else if(cases[c].na.departure.size() != 0 && cases[c].nb.departure.size() != 0){
            
            //Find the number of A starts
            int temp = naStart = int(cases[c].na.departure.size());
            
            for(int i = 0; i < temp; i++){
                for(int x = 0; x < cases[c].nb.arrival.size(); x++){
                    
                    int depature = cases[c].na.departure[i];
                    int arrival = cases[c].nb.arrival[x]+cases[c].turnaround;
                    if(depature > arrival ){
                        naStart--;
                    }
                    
                }
                
            }
            
            
            //Find the number of B starts
            temp = nbStart = int(cases[c].nb.departure.size());
            
            for(int i = 0; i < temp; i++){
                for(int x = 0; x < cases[c].na.arrival.size(); x++){
                    
                    int depature = cases[c].nb.departure[i];
                    int arrival = cases[c].na.arrival[x]+cases[c].turnaround;
                    if(depature > arrival ){
                        nbStart--;
                    }
                    
                }
                
            }
            
            
            
            
        }
        
        
        answer += "Case #"+to_string(c+1)+": "+to_string(naStart)+" "+to_string(nbStart)+"\n";
    }
    
    cout << answer << endl;
    return answer;
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
            
            int it;
            it = 2;
            
            if(i < curr+naNum){
                vector<string> temp = split(lines[i], " ");
                cases[c].na.departure.push_back(atoi(temp[0].erase(it,1).c_str()));
                cases[c].na.arrival.push_back(atoi(temp[1].erase(it,1).c_str()));
            }else{
                vector<string> temp = split(lines[i], " ");
                cases[c].nb.departure.push_back(atoi(temp[0].erase(it,1).c_str()));
                cases[c].nb.arrival.push_back(atoi(temp[1].erase(it,1).c_str()));
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
