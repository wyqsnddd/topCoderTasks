#include <iostream>
#include <stdlib.h>
#include "customUnionFind.h"

using namespace std;

void printElementSets(const customUnionFind & s)
{
  for (int i = 0; i < s.nodeNumber(); ++i)
    cout << s.findID(i) << "  ";
  cout << endl;
}

int main()
{

  int nodeNumber(10);
  customUnionFind test(nodeNumber);
  // std::cout<<"Union done"<<std::endl;
    
  printElementSets(test);
  // std::cout<<"Union done"<<std::endl;


  /* initialize random seed: */
  srand (time(NULL));

  /* generate secret number between 0 and nodeNumber: */

  
  int round = 8;
  while(round>0){
    int iSecretOne = rand() % nodeNumber;
    int iSecretTwo = rand() % nodeNumber;
    std::cout<<"iSecretOne is: "<<iSecretOne<<" iSecretTwo is: "<<iSecretTwo<<std::endl;
    test.mergeUnion(iSecretOne, iSecretTwo);
    std::cout<<"After the merge, the union numbers are: "<<test.unionNumber()<<std::endl;
    printElementSets(test);
    round--;
  }
  return 0;
}
