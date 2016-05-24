#include"ResearchNode.hh"
ResearchNode::FailState::FailState(string _failText,string _fixText,float _time, vector<ResearchNode *> _dependecies){
    time = _time;
}
int ResearchNode::FailState::getTime(){

    return time;
}
int ResearchNode::FailState::getChance(){
    return 0;
}
