//
//  Main.cpp
//  Object Oriented Lab 1
//
//  Created by Sophia Danielsen on 9/8/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

// Notes: i = row       j = column

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ifstream in_file("life.txt");
    
    if (!in_file) {
        cerr << "Could not open file. \n";
        exit(1);
    }
    
    vector<string> vectorOfStrings;
    
    string line;
    bool start = true;
    string boundary = "";
    
    while (getline(in_file, line)){
        if(start == true){
            for (size_t i = 0; i < line.length() + 2; ++i){
                boundary += '-';
            }
            start = false;
            vectorOfStrings.push_back(boundary);     // upper boundary
        }
        vectorOfStrings.push_back('-' + line + '-');
    }
    vectorOfStrings.push_back(boundary);    // lower boundary
    
    in_file.close();
    
    cout << "Initial Generation" << endl;
    
    for (size_t i = 1; i < vectorOfStrings.size(); ++i){
        string row = "";
        for (size_t j = 1; j < vectorOfStrings[i].size(); ++j){
            if (vectorOfStrings[i][j] == '-'){
                row += " ";
            }
            else{
                row += vectorOfStrings[i][j];
            }
        }
        cout << row << endl;
    }
    
    for (size_t generation = 1; generation < 11; ++generation){
        vector<string> tempVector;
        tempVector.push_back(boundary);     // upper boundary
        
        cout << "Generation " << generation << endl;
        
        for (size_t i = 1; i < vectorOfStrings.size() - 1; ++i){
            string row = "-";
            for (size_t j = 1; j < vectorOfStrings[i].size(); ++j){
                int numOfNeighbors = 0;
                if (vectorOfStrings[i-1][j-1] == '*'){
                    numOfNeighbors += 1;
                }
                if (vectorOfStrings[i-1][j] == '*'){
                    numOfNeighbors += 1;
                }
                if (vectorOfStrings[i-1][j+1] == '*'){
                    numOfNeighbors += 1;
                }
                if (vectorOfStrings[i][j-1] == '*'){
                    numOfNeighbors += 1;
                }
                if (vectorOfStrings[i][j+1] == '*'){
                    numOfNeighbors += 1;
                }
                if (vectorOfStrings[i+1][j-1] == '*'){
                    numOfNeighbors += 1;
                }
                if (vectorOfStrings[i+1][j] == '*'){
                    numOfNeighbors += 1;
                }
                if (vectorOfStrings[i+1][j+1] == '*'){
                    numOfNeighbors += 1;
                }
                
                if (vectorOfStrings[i][j] == '*'){
                    if (numOfNeighbors > 3 || numOfNeighbors < 2){
                        row += '-';
                    }
                    else{
                        row += '*';
                    }
                }
                else{
                    if (numOfNeighbors == 3){
                        row += '*';
                    }
                    else{
                        row += '-';
                    }
                }
            }
            tempVector.push_back(row);
        }
        
        tempVector.push_back(boundary);     // lower boundary
        vectorOfStrings = tempVector;
        
        for (size_t i = 1; i < vectorOfStrings.size(); ++i){
            string row = "";
            for (size_t j = 1; j < vectorOfStrings[i].size(); ++j){
                if (vectorOfStrings[i][j] == '-'){
                    row += " ";
                }
                else{
                    row += vectorOfStrings[i][j];
                }
            }
            cout << row << endl;
        }
    }
}
