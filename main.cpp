/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: Wooyoung
 *
 * Created on November 9, 2017, 2:50 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Graph.h"
#include "Subgraph.h"
#include "NautyLink.h"
#include "RandomGraphGenerator.h"
#include "ESU.h"
#include "SubgraphCount.h"
#include "SubgraphProfile.h"
#include "StatisticalAnalysis.h"
#include "RandomGraphAnalysis.h"
#include <ctime>

/*
 * Simple C++ Test Suite
 */

template<typename map_key, typename map_val>
void printmap(const unordered_map<map_key, map_val>& _map) {
        for (const auto& p : _map)
            cout << p.first << " => " << p.second << endl;

}


int main(int argc, char** argv) {
    
    std::clock_t begin = std::clock();
    
    double duration=0.0;
    
    // string filename = "test_input.txt";
    string filename = "exampleGraph.txt";
    Graph targetg(filename, false);
 
   //cout<<targetg<<endl; 
    
  //SubgraphProfile subc(targetg.getSize());
  
     SubgraphCount subc;
   int motifSize=4;
   int randomCount = 0;
   
    ESU::enumerate(targetg, subc, motifSize);
    
    unordered_map <graph64, double> targetLabelRelFreqMap =
		        subc.getRelativeFrequencies();
    printmap(targetLabelRelFreqMap);
    
  vector <double> probs;
    for (int i = 0; i < motifSize - 2; i++) {
        probs.push_back(1.0);
    }
    probs.push_back(0.5);
    probs.push_back(0.5);
    
    cout<<"Analyzing random graphs..."<<endl;
    
    unordered_map<graph64, vector<double>> randLabelRelFreqsMap=RandomGraphAnalysis::analyze(targetg, randomCount, motifSize, probs) ;
    
    cout<<"Comparing target graph to random graphs"<<endl;
    
    StatisticalAnalysis stat(targetLabelRelFreqMap, randLabelRelFreqsMap, randomCount);
    
    cout<<stat<<endl;
    
    duration = ( std::clock() - begin ) / (double) CLOCKS_PER_SEC;
     
     cout<<"Time = "<<duration*1000<<"ms"<<endl;
     cout<<"Time = "<<duration<<"s"<<endl;

    return (EXIT_SUCCESS);
}

