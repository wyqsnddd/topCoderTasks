# include <cassert> // for assert
# include <cstddef> // for NULL 
# include <iostream>
# include "customUnionFind.h"

customUnionFind::customUnionFind(){

  unionNumbers_ = 0;
  nodeNumbers_ = 0;
  
}
customUnionFind::customUnionFind( int numberOfNodes){
  
  unionNumbers_ = 0;
  nodeNumbers_ = 0;
  addNodes(numberOfNodes);
}
customUnionFind::~customUnionFind( ){
  
  for(int i = 0; i < nodeNumber(); i++){
    delete nodes_[i];
  }
  nodes_.clear();
}

void customUnionFind::addNodes(int numberOfNodes){
  
  assert(numberOfNodes>0);
  
  nodes_.insert( nodes_.end(), numberOfNodes, (node*)NULL);

  for(int i = nodeNumber(); i < nodeNumber() + numberOfNodes; i++){
    node * newNode =  new node();
    nodes_[i] = newNode;
    // first never used ID
    newNode->ID = i;  
    // newNode->next = NULL;  
    newNode->rank = 1;
    // The new node is a set by itself
    newNode->parent = newNode;
  }

  // update the union and node numbers;
  unionNumbers_ += numberOfNodes;
  nodeNumbers_ += numberOfNodes;
}



int customUnionFind::findID(int nodeID) const{
  // In it's current version there is no path compression 
  assert(properNodeNumber(nodeID));
  
  return  findParent(nodeID)->ID; 
}


void customUnionFind::mergeUnion(const int nodeOneID, const int nodeTwoID){
  if(nodeOneID == nodeTwoID)
    return;

  assert( properNodeNumber(nodeOneID));
  assert( properNodeNumber(nodeTwoID));
    
  
  node* parentOne =   findParent(nodeOneID);
  node* parentTwo =   findParent(nodeTwoID);

  // 
  int oneID = parentOne->ID;
  int twoID = parentTwo->ID;

  if(oneID == twoID){
    std::cout<<"Two nodes are already in the same set"<<std::endl;
    return;
  }


  // If the group ID are different
  if(parentOne->rank >= parentTwo->rank)
    // One has a bigger rank, so one will be the parent of two. In other words, append the smaller list to the bigger one. 
    metaMerge(nodeOneID, nodeTwoID, parentOne, parentTwo);
  else
    metaMerge(nodeTwoID, nodeOneID, parentTwo, parentOne);
}

void customUnionFind::metaMerge(const int nodeOneID, const int nodeTwoID, node* parentOne, node* parentTwo){
  // quick union operation set one root to another 
  // (1) set parent (2) set rank
  
  
  // node* iterator = parentTwo;
  parentOne->rank += parentTwo->rank;

  assert(parentTwo==parentTwo->parent);
  assert(parentOne==parentOne->parent);

  std::cout<<"Merging "<< nodeTwoID <<" to "<< nodeOneID<<std::endl;
  
  std::cout<<"Node "<< nodeTwoID <<"'s parent will be  "<< parentOne->ID<<", instead of "<<parentTwo->ID <<std::endl;

  parentTwo->parent = parentOne;
  

  unionNumbers_ --;
}


customUnionFind::node* customUnionFind::findParent(int nodeID) const{
  node* parentNode = nodes_[nodeID];
  
  while(parentNode->parent != parentNode){
    // path compression 
    
    parentNode = parentNode->parent;
  }
  
  return parentNode;

}
