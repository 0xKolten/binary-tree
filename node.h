class node {

  private:
    int key;
    int search_cost;
    node *left; 
    node *right;
    friend class BinarySearchTree;

  public:
    node(int key = 0, int cost = 0, node *left = nullptr, node *right = nullptr) : key(key), search_cost(cost), left(left), right(right) {}
    node *get_left() { 
        return left; 
    }
    node *get_right() { 
        return right; 
    }
};