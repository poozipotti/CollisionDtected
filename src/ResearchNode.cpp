#include "ResearchNode.hh"

ResearchNode::ResearchNode (string _name,string _description,float completionTime){
    name = _name;
    description = _description;
    estimatedTime = completionTime;
}

bool ResearchNode::CheckFailure(int i){
    if((rand()%100 + 1)<Failures[i]->getChance()){
        isActiveFailure = true;
        ActiveFailState = Failures[i];
        return true;
    }
    return false;
}
void ResearchNode::addFailState(string failText,string fixText, int timeStart, int timeEnd, vector<ResearchNode *> dependecies){
    /*when you add a time for a failure it is how much time is left, so a higher number will happen sooner*/

}
void ResearchNode::complete(){

}
int ResearchNode::update(){
    if(estimatedTime != -1){
        estimatedTime --;
    }
    for(int i =0; i< timesToFailures.size();i++){
        if(timesToFailures[i]=completionTime){
        if(CheckFailure(i)){
            /*display a failure*/
        }
            break;
        }

    }
}
