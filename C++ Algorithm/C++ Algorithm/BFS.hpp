//
//  BFS.hpp
//  Tests
//
//  Created by fanglliu on 2018/10/6.
//  Copyright © 2018 zto. All rights reserved.
//

#ifndef BFS_hpp
#define BFS_hpp

#include <stdio.h>

class Node {
public:
    int value = 0;
    int access_time = 0;
    bool already_pushed = false;
    Node *left = nullptr, *right = nullptr;
};

void TBFS(Node *root);
Node* createTree();

#endif /* BFS_hpp */
