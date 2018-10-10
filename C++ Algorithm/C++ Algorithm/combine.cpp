//
//  combine.cpp
//  Tests
//
//  Created by fanglliu on 2018/10/7.
//  Copyright © 2018 zto. All rights reserved.
//

#include "combine.hpp"
#include <vector>
#include <iostream>
#include "permute.hpp"

using namespace std;

void __combine(vector<int> &vec, int i) {
    
    if (i == 0) {
        print(vec);
        return;
    }
    

    __combine(vec, i - 1);

    auto it = vec.begin() + i - 1;
    int value = *it;
//    cout << "erase: *it: " << *it << "  i - 1: "  << i - 1 << endl;
    vec.erase(it);

    __combine(vec, i - 1);
//    cout << "insert: *it: " << value << "  i - 1: "  << i - 1 << endl;
    vec.insert(vec.begin() + i - 1, value);
}

void combine(int n) {
    vector<int> vec;
    vec.reserve(n);
    for (int i = 0; i < n; i++) {
        vec.push_back(i + 1);
    }
    
    __combine(vec, n);
}
