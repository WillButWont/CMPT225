/*
 * Name: William The
 * Student ID: 301586358
 * Login ID: wta57
 * Copyright: William The, 2025
 * Assignment: Assignment 4
 * Purpose: Test file for comparing three search trees
 */

#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "RedBlackTree.h"

using namespace std;

const int N1 = 10;  // For Set 1 (smaller size)
const int N2 = 20; // For Set 2 (larger size)

// Returns elapsed time in milliseconds
double elapsed_time(clock_t start, clock_t finish) {
    return (finish - start) / (double)(CLOCKS_PER_SEC / 1000);
}

// Inserts given keys into the tree
template <typename TreeType>
void insert_keys(TreeType &tree, const vector<int>& keys) {
    for (int key : keys) {
        tree.insert(key);
    }
}

// Times the insertion and counteven calls for the tree
template <typename TreeType>
void benchmark_tree(TreeType &tree, const vector<int>& keys, const string &tree_name) {
    clock_t start, finish;

    // Insertion timing
    start = clock();
    insert_keys(tree, keys);
    finish = clock();
    double insert_time = elapsed_time(start, finish);

    // Even count timing
    start = clock();
    int even_count = tree.counteven();
    finish = clock();
    double even_time = elapsed_time(start, finish);

    cout << "Tree Type: " << tree_name << endl;
    cout << "Nodes inserted: " << keys.size() << endl;
    cout << "Insert Time: " << insert_time << " ms" << endl;
    cout << "Even Count: " << even_count << endl;
    cout << "Even Count Time: " << even_time << " ms" << endl;
    cout << "Tree Display:" << endl;
    tree.tdisplay();
    cout << "-----------------------------" << endl;
}

int main() {
    // Hardcoded sets of keys (random example sets)
    vector<int> set1 = {19, 1, 12, 11, 18, 4, 17, 5, 7, 6};  // Set 1 (n1 = 10)
    vector<int> set2 = {20, 15, 9, 19, 12, 5, 10, 13, 17, 16, 18, 1, 8, 11, 4, 2, 7, 14, 3, 6};  // Set 2 (n2 = 20)

    BinarySearchTree<int> bst1, bst2;
    AvlTree<int> avl1, avl2;
    RedBlackTree<int> rbt1(-1), rbt2(-1);  // Assume -1 as a default negInf value for Red-Black Tree

    cout << "Testing Binary Search Tree:" << endl;
    benchmark_tree(bst1, set1, "Binary Search Tree 1");
    benchmark_tree(bst2, set2, "Binary Search Tree 2");

    cout << "\nTesting AVL Tree:" << endl;
    benchmark_tree(avl1, set1, "AVL Tree 1");
    benchmark_tree(avl2, set2, "AVL Tree 2");

    cout << "\nTesting Red Black Tree:" << endl;
    benchmark_tree(rbt1, set1, "Red Black Tree 1");
    benchmark_tree(rbt2, set2, "Red Black Tree 2");

    return 0;
}
