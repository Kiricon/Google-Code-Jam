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
void writeFile(string);
int format(string str);

// ###### MAIN  ##########
int main(int argc, const char * argv[]) {
    
    vector<Case> cases = parse(readFileByLine("B-large-practice.in"));
    writeFile(solve(cases));
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
            vector<int> used;
            
            for(int i = 0; i < temp; i++){
                
                int smallestTime = 2500;
                int smallest = -1;
                for(int x = 0; x < cases[c].nb.arrival.size(); x++){
                    
                    bool alreadyUsed = false;
                    for(int z = 0; z < used.size(); z++){
                        if( used[z] == x){
                            alreadyUsed = true;
                        }
                    }
                    
                    int departure = cases[c].na.departure[i];
                    int min, hr;
                    min = cases[c].nb.arrival[x] % 100;
                    hr = cases[c].nb.arrival[x] /100;
                    
                    min += cases[c].turnaround;
                    if(min > 60){
                        min -= 60;
                        hr++;
                    }
                    if(hr > 23){
                        hr -= 24;
                    }
                    int arrival = (hr *100)+min;
                    if(departure >= arrival  && !alreadyUsed){
                        if(departure - arrival < smallestTime){
                            smallestTime = departure - arrival;
                            smallest = x;
                        }
                    }
                    
                }
                
                if(smallest > -1){
                    used.push_back(smallest);
                    naStart--;
                }
                
            }
            
            
            //Find the number of B starts
            temp = nbStart = int(cases[c].nb.departure.size());
            used = {};
            for(int i = 0; i < temp; i++){
                
                int smallestTime = 2500;
                int smallest = -1;
                for(int x = 0; x < cases[c].na.arrival.size(); x++){
                    
                    bool alreadyUsed = false;
                    
                    for(int z = 0; z < used.size(); z++){
                        if( used[z] == x){
                            alreadyUsed = true;
                        }
                    }
                    
                    int departure = cases[c].nb.departure[i];
                    int arrival = cases[c].na.arrival[x]+cases[c].turnaround;
                    
                    
                    if(departure >= arrival && !alreadyUsed){
                        if(departure - arrival < smallestTime){
                            smallestTime = departure - arrival;
                            smallest = x;
                        }
                    }
                    
                    
                }
                
                if(smallest > -1){
                    used.push_back(smallest);
                    nbStart--;
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
                cases[c].na.departure.push_back(format(temp[0]));
                cases[c].na.arrival.push_back(format(temp[1]));
            }else{
                vector<string> temp = split(lines[i], " ");
                cases[c].nb.departure.push_back(format(temp[0]));
                cases[c].nb.arrival.push_back(format(temp[1]));
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

// remove :
int format(string str){
    string sep = ":";
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current != NULL){
        arr.push_back(current);
        current=strtok(NULL, sep.c_str());
    }
    string temp = arr[0]+arr[1];
    return atoi(temp.c_str());
}
