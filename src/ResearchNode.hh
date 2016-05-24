#ifndef _RESEARCHNODE_H_
#define _RESEARCHNODE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ResearchNode{

    protected:
        class FailState{
            public:
            FailState();
            int getChance(); /*out of 100*/
            int getTime();
            bool ignorable; /*failstates at the end of the process cannot be ignored*/
            protected:
            float time; /*how much time the failstate adds to the research(range between first and second number)*/
            string failText;
            string fixText;
            vector<ResearchNode *> dependecies;
            vector<int> dependecieWeight;
        };
        vector<FailState *> Failures;
        vector<FailState *> ignoredFailures;
        vector<int> timesToFailures;
    public:
        ResearchNode();
        bool CheckFailure(int); /*failures are checked at CertainIntervals, i is the place of the failure in the list*/
        void addFailState(string failText,string fixText, int timeStart, int timeEnd, vector<ResearchNode *> dependecies);/*dependecies must be added before FailStates!!*/
        void complete();
        int update(); /*returns the time left*/
        string name;
        string description;
        float completionTime;
        int currentTime;
        bool isActiveFailure;
        bool Completed;
        FailState * ActiveFailState;
        int estimatedTime; /*this is the displayed time to completion*/


};
#endif


