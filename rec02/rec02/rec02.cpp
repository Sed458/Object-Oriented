//
//  rec02.cpp
//  rec02
//
//  Created by Sophia Danielsen on 9/14/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Hydrocarbon {
   vector<string> names;
    int carbonCount;
    int hydrogenCount;
};

void display(const vector<Hydrocarbon>& hydrocarbons, int maxCarbonCount);

size_t checkVector(const vector<Hydrocarbon>& molecularFormulas, const int& carbon, const int& hydrogen);



int main(){
    ifstream inFile ("formulas.txt");
    
    if (!inFile) {
        cerr << "Could not open file." << endl;
        exit(1);
    }
    
    string name;
    char c;
    char h;
    int carbon;
    int hydrogen;
    
    int maxCarbonCount = 0;
    
    vector<Hydrocarbon> hydrocarbons;
    
    while(inFile >> name >> c >> carbon >> h >> hydrogen){
        
        size_t index;
        index = checkVector(hydrocarbons, carbon, hydrogen);
        
        if (index == hydrocarbons.size()) {               //Create new Hydrocarbon if not found in molecularFormulas
            Hydrocarbon formula;
            formula.names.push_back(name);
            formula.carbonCount = carbon;
            formula.hydrogenCount = hydrogen;
            
            if (carbon > maxCarbonCount) {
                maxCarbonCount = carbon;
            }
            
            hydrocarbons.push_back(formula);
        }
        else {
            hydrocarbons[index].names.push_back(name);   //Add name if already in vector
        }
    }
    
    display(hydrocarbons, maxCarbonCount);
    
}


size_t checkVector(const vector<Hydrocarbon>& molecularFormulas, const int& carbon, const int& hydrogen) {
    for (size_t index = 0; index < molecularFormulas.size(); index++) {
        if (molecularFormulas[index].carbonCount == carbon && molecularFormulas[index].hydrogenCount == hydrogen){
            return index;
        }
    }
    return molecularFormulas.size();
}


void display(const vector<Hydrocarbon>& hydrocarbons, int maxCarbonCount){
    for (int carbonCount = 0; carbonCount < maxCarbonCount + 1; ++carbonCount){
        for (const Hydrocarbon& formula : hydrocarbons){
            if (formula.carbonCount == carbonCount){
                cout << 'C' << formula.carbonCount << 'H' << formula.hydrogenCount << " ";
                for (const string& name : formula.names){
                    cout << name << " ";
                }
                cout << endl;
            }
        }
    }
}
