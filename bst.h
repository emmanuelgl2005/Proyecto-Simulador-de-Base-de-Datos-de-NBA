/*
 * bst.h
 *
 *  Created on: 24/10/2025
 *      Author: Emmanuel Garcia Lopez
 */
#include <string>

using namespace std; 

class TreeNode {
public:
    int rk;
    string team;
    float _3Ppercent;
    float _2Ppercent;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int ranking, const string& equipo, float p3, float p2);
};

class BST {
public:
    TreeNode* root;

    BST();

    void insert(int ranking, const string& equipo, float p3, float p2);

    TreeNode* searchByRanking(int ranking);

};
