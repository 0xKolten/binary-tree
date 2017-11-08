#include "bst.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<int> readFile(string filename); 

int main() {

    string filename;
    cout << "Enter file name: " << endl; 
    cin >> filename;
    cout << endl;

    vector<int> input = readFile(filename);

    cout << endl;
    cout << "Creating tree... " << endl;
 
    BinarySearchTree tree;
    for (int i = 0; i < input.size(); ++i) {
        tree.insert(input[i]); 
    } 

    int numNodes = tree.get_numNodes(); 
    cout << endl; 
    cout << "Total nodes: " << numNodes << endl;

    if (numNodes < 17) {
        cout << "Pre Order traversal: " << endl;
        tree.PreOrderTraversal(tree.get_root());

        cout << endl; 

        cout << "In Order traversal: " << endl;
        tree.InOrderTraversal(tree.get_root());

        cout << endl; 

        cout << "Post Order traversal: " << endl; 
        tree.PostOrderTraversal(tree.get_root());

        cout << endl; 
    } 
    else 
        cout << "Not printing: Total nodes larger than 16" << endl; 

    cout << endl; 
    cout << "Average search cost: " << endl; 
    double avg = tree.avg_cost(tree); 
    cout << avg << endl; 


    if (numNodes < 17) {
        cout << endl; 
        cout << "Outputting tree to file..." << endl;
        tree.OutputTree(filename + "_output.txt");
    }
    
    cout << endl;
    int remove;
    cout << "Enter key to remove: ";
    cin >> remove;
    tree.remove(remove);
    numNodes = tree.get_numNodes(); 

    cout << endl; 
    cout << "Total nodes: " << numNodes << endl;

    if (numNodes < 17) {
        cout << "Pre Order traversal: " << endl;
        tree.PreOrderTraversal(tree.get_root());

        cout << endl; 

        cout << "In Order traversal: " << endl;
        tree.InOrderTraversal(tree.get_root());

        cout << endl; 

        cout << "Post Order traversal: " << endl;
        tree.PostOrderTraversal(tree.get_root());

        cout << endl; 
    }
    else
        cout << "Not printing: Total nodes larger than 16" << endl;

    cout << endl; 
    double newAvg = tree.avg_cost(tree);
    cout << "Average search cost: " << endl;
    cout << newAvg << endl; 
    cout << endl;
    

}

vector<int> readFile(string filename) {
    ifstream read;
    read.open(filename);
    int data;
    vector<int> input;
    if (read.is_open()) {
        cout << "Input data: " << endl; 
        while (read >> data) {
            input.push_back(data);
            cout << data << endl;
        }
        read.close();
    }
    else
        cout << "File not opened" << endl;
    return input; 
}
