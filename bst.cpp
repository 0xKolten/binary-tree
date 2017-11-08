#include "bst.h"
#include <queue> 
#include <iostream>
#include <fstream>

node *BinarySearchTree::insert(int k, node *n, int &cost) {
    cost++; 
    if (n == nullptr) {
        numNodes++;
        n = new node(k); 
        n->search_cost = cost;              
        cout << "Key = " << k << "  Search Cost = " << cost << endl;
    }
    else if (k < n->key) 
        n->left = insert(k, n->left, cost);
    else 
        n->right = insert(k, n->right, cost);
    return n;
}

node *BinarySearchTree::remove_min(node *n) {
    if (n->left != nullptr) 
        n->left = remove_min(n->left);
    else {
        node *node = n;
        n = n->right;
        delete node;
    }
    return n;
}

node *BinarySearchTree::remove(int x, node *n) {
    if (n == nullptr) return n; 
    if (x < n->key)                               
        n->left = remove(x, n->left);             
    else if (x > n->key)                          
        n->right = remove(x, n->right);           
    else if (n->left != nullptr && n->right != nullptr) { 
        n->key = find_min(n->right)->key;
        n->right = remove_min(n->right);
        numNodes--;
    }
    else { 
        node *node = n;
        if (n->left != nullptr) {
            n = n->left; 
        }
        else {
            n = n->right; 
        }
        numNodes--;
        delete node; 
    }
    new_cost(root, 1);
    return n;
}

void BinarySearchTree::new_cost(node *n, int i) {
    if (n == nullptr) return;
    new_cost(n->left, i+1);
    new_cost(n->right, i+1);
    n->search_cost = i; 
}

void BinarySearchTree::total_cost(node *root, int &total) {
    total = total + root->search_cost;
    if (root->get_left() != NULL)
        total_cost(root->get_left(), total);
    if (root->get_right() != NULL)
        total_cost(root->get_right(), total);
}

double BinarySearchTree::avg_cost(BinarySearchTree t) {
    int total = 0;
    total_cost(t.get_root(), total);
    double node_count = numNodes;
    return total / node_count;
}

void BinarySearchTree::InOrderTraversal(node *n) {
    if (n->left != nullptr)
        InOrderTraversal(n->left);
    if (numNodes < 17) { 
        cout << n->key << "[" << n->search_cost << "] ";
    }
    if (n->right != nullptr)
        InOrderTraversal(n->right); 
}

void BinarySearchTree::PreOrderTraversal(node *n) {
    if (numNodes < 17) {
        cout << n->key << "[" << n->search_cost << "] ";
    }
    if (n->left != nullptr)
        PreOrderTraversal(n->left);
    if (n->right != nullptr)
        PreOrderTraversal(n->right);
}

void BinarySearchTree::PostOrderTraversal(node *n) {
    if (n->left != nullptr)
        PostOrderTraversal(n->left);
    if (n->right != nullptr)
        PostOrderTraversal(n->right);
    if (numNodes < 17) {
        cout << n->key << "[" << n->search_cost << "] ";
    }
}

void BinarySearchTree::OutputTree(string filename) {
    ofstream ofs(filename);
    if (root == nullptr) return; 
    queue<node *> nq;
    vector<int> t;
    int lvl = 1;
    int itr = 0;
    node *x = new node(-1, 0, nullptr, nullptr);
    bool flag = true;
    nq.push(root);
    while (nq) {
        node *current = nq.front();
        nq.pop();
        lvl--;
        if (current) {
            t.push_back(current->key);
            if (current->left == nullptr) {
                nq.push(x);
            } 
            else {
                flag = false;
                nq.push(current->left);
            }
            if (current->right == nullptr) {
                nq.push(x);
            } 
            else {
                flag = false;
                nq.push(current->right);
            }
            itr += 2;
        }
        if (lvl == 0) {
            for (int i = 0; i < t.size(); i++) {
                if (t[i] == -1) {
                    ofs << "X "; 
                } 
                else {
                    ofs << t[i] << " ";
                } 
            }
            ofs << endl;
            if (flag) return;
            flag = true;         
            lvl = itr; 
            itr = 0;
        }
        t.clear();
    }
    delete x;
}