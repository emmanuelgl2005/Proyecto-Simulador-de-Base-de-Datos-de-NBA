/*
 * bst.cpp
 *
 *  Created on: 24/10/2025
 *      Author: Emmanuel Garcia Lopez
 */
#include "bst.h"

TreeNode::TreeNode(int ranking, const string& equipo, float p3, float p2)
    : rk(ranking), team(equipo), _3Ppercent(p3), _2Ppercent(p2), left(nullptr), right(nullptr) {
}

BST::BST() : root(nullptr) {}

void BST::insert(int ranking, const string& equipo, float p3, float p2) {
    TreeNode* newNode = new TreeNode(ranking, equipo, p3, p2);

    if (root == nullptr) {
        root = newNode;
        return;
    }

    TreeNode* current = root;
    while (true) {
        if (ranking < current->rk) {
            if (current->left == nullptr) {
                current->left = newNode;
                return;
            } else {
                current = current->left;
            }
        } else {
            if (current->right == nullptr) {
                current->right = newNode;
                return;
            } else {
                current = current->right;
            }
        }
    }
}

TreeNode* BST::searchByRanking(int ranking) {
    TreeNode* current = root;
    while (current != nullptr) {
        if (ranking == current->rk) {
            return current;
        } else if (ranking < current->rk) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;
}

