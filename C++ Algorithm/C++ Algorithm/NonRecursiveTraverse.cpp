//
//  NonRecursiveTraverse.cpp
//  C++ Algorithm
//
//  Created by fanglliu on 2018/10/7.
//  Copyright © 2018 zto. All rights reserved.
//

#include "NonRecursiveTraverse.hpp"

#include "BFS.hpp"
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

void preNonRecursiveTraverse(Node *node) {
    vector<Node *> stack;
    stack.push_back(node);
    
    while (!stack.empty()) {
        Node *node = stack.back();
        stack.pop_back();
        if (node == nullptr) {
            continue;
        }
        
        cout << node->value << endl;
        stack.push_back(node->right);
        stack.push_back(node->left);
    }
}

void midNonRecursiveTraverse(Node *node) {
    vector<Node *> stack;
    stack.push_back(node);
    
    while (!stack.empty()) {
        Node *node = stack.back();
        stack.pop_back();
        if (node == nullptr) {
            continue;
        }
        
        if (node->right == stack.back()) {
            cout << node->value << endl;
        } else {
            stack.push_back(node->right);
            stack.push_back(node);
            stack.push_back(node->left);
        }
    }
}


void postNonRecursiveTraverse(Node *node) {
    vector<Node *> stack;
    stack.push_back(node);
    bool backtrace = false;
    
    while (!stack.empty()) {
        Node *node = stack.back();
        stack.pop_back();
        if (node == nullptr) {
            continue;
        }
        
        if (node->already_pushed) {
            cout << node->value << endl;
        } else {
            node->access_time++;
            node->already_pushed = true;
            stack.push_back(node);
            stack.push_back(node->right);
            stack.push_back(node->left);
        }
    }
}

void traverse(Node *node) {
    if (node == nullptr) {
        return;
    }
    
//    cout << node->value << endl;
    traverse(node->left);
    cout << node->value << endl;
    traverse(node->right);
}

void testNonRecursiveTraverse() {
/*
        1
    2        3
4      5   6   7
 
 
 */
    Node* tree = createTree();
//    traverse(tree);
//    preNonRecursiveTraverse(tree);
//    midNonRecursiveTraverse(tree);
    postNonRecursiveTraverse(tree);
    
}
