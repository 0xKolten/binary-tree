#include "node.h"
#include <iostream> 
using namespace std; 

class BinarySearchTree {
  private:
    int numNodes;
    node* root;

  public:
    BinarySearchTree(node* root = nullptr, int numNodes = 0) : root(root), numNodes(numNodes) {}

    bool is_empty() { return root == nullptr; }

    node* get_root() {
        return root; 
    }

    int get_numNodes() {
        return numNodes; 
    }

    void remove(int x) { 
        root = remove(x, root); 
    }
    node *remove(int x, node *n);

    node *find_min(node *n) {
        while (n->left != nullptr)
            n = n->left;
        return n;
    }
    node *remove_min(node *n);

    void new_cost(node *n, int i);
    void total_cost(node *root, int &total);
    double avg_cost(BinarySearchTree t);

    void insert(int k) {
        int cost = 0;
        root = insert(k, root, cost);
    }
    node *insert(int x, node *n, int &cost);

    void InOrderTraversal(node *n);
    void PreOrderTraversal(node *n);
    void PostOrderTraversal(node *n);

    void OutputTree(string filename); 
};