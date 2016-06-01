# include <vector>
// Union-find data structure (with weighted union and path compression). 
// Author: Yuquan Wang
// Date: 2016-06-01
// According to the slides: https://www.cs.princeton.edu/~rs/AlgsDS07/01UnionFind.pdf

class customUnionFind{
  // weighted quick-union
  
public:
  customUnionFind();
  customUnionFind(int nodeNumber);
  ~customUnionFind();


  // Find the set ID of a node 
  int findID(int nodeID) const;

  // Merge the two sets that contain the two nodes respectively into one set. 
  void mergeUnion(const int nodeOneID, const int nodeTwoID);

  // return number of nodes
  int nodeNumber() const{
    return nodeNumbers_;
  }
  // return number of unions
  int unionNumber() const{
    return unionNumbers_;
  }
  
  // Add nodeNumber nodes, (0) default parent is itself (1) rank starts from 0  (2) its ID starts from the first-never-used one
  void addNodes(int nodeNumber);

private:
  int unionNumbers_;
  int nodeNumbers_;

  struct node{
    /* The ID of the node is its position in the vector  */
    /* *node next; // track the nodes in the same set */
    short int rank;
    int ID;
    node * parent;// points to the representative of the set
  };
  
  std::vector<node*> nodes_;
  
  void metaMerge(const int nodeOneID, const int nodeTwoID, node* parentOne, node* parentTwo);
  
  bool properNodeNumber(int nodeID)const{
    return (nodeID>=0) && (nodeID<nodeNumber());
    /* return true; */
  }
  
  node* findParent(int nodeID) const;


};
