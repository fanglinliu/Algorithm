//
//  BFS.cpp
//  Tests
//
//  Created by fanglliu on 2018/10/6.
//  Copyright © 2018 zto. All rights reserved.
//

#include "BFS.hpp"
#include <vector>
#include <iostream>
using namespace std;



void __BFS(vector<Node *> queue) {
    if (queue.empty()) {
        return;
    }
    
    for (auto it = queue.begin(); it != queue.end(); it++) {
        std::cout << (*it)->value << " ";
    }
    
    cout << endl;
    
    
    vector<Node *> vec;
    for (auto it = queue.begin(); it != queue.end(); it++) {
        if ((*it)->left) {
            vec.push_back((*it)->left);
        }
        
        if ((*it)->right) {
            vec.push_back((*it)->right);
        }
    }
    
    __BFS(vec);
}

void TBFS(Node *root) {
    vector<Node *> queue;
    queue.push_back(root);
    __BFS(queue);
}

Node* createTree() {
    Node *node1 = new Node;
    node1->value = 1;
    
    Node *node2 = new Node;
    node2->value = 2;
    node1->left = node2;

    Node *node3 = new Node;
    node3->value = 3;
    node1->right = node3;

    
    Node *node4 = new Node;
    node4->value = 4;
    node2->left = node4;

    Node *node5 = new Node;
    node5->value = 5;
    node2->right = node5;
    
    

    Node *node6 = new Node;
    node6->value = 6;
    node3->left = node6;

    Node *node7 = new Node;
    node7->value = 7;
    node3->right = node7;
    
    return node1;
}
