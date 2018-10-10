//
//  permute.cpp
//  Tests
//
//  Created by fanglliu on 2018/10/7.
//  Copyright © 2018 zto. All rights reserved.
//

#include "permute.hpp"
#include <vector>
#include <iostream>

using namespace std;


void print(vector<int> vec) {
//    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    
//    cout << "]";
    cout << endl;
}



void __permuate(vector<int> & vec, int i) {
    if (i == 0) {
        print(vec);
        return;
    }
    
    for (int j = 0; j < i; j++) {
        swap(vec[j], vec[i - 1]);
        __permuate(vec, i - 1);
        swap(vec[j], vec[i - 1]);
    }
}


void permuate(int n) {
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        vec.push_back(i + 1);
    }
    
    __permuate(vec, n);
}
