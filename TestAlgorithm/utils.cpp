//
//  utils.cpp
//  TestAlgorithm
//
//  Created by fanglliu on 3/23/16.
//  Copyright © 2016 fanglliu. All rights reserved.
//

#include "utils.hpp"
#include <vector>
#include <iostream>
using namespace std;

vector<int> create_vector(int cnt)
{
    vector<int> vec;
    for ( int i = 0 ; i < cnt; i++ )
    {
        vec.push_back(i + 1);
    }
    
    return vec;
}

void print(vector<int> vec)
{
    if ( vec.empty() )
    {
        cout << "empty" << endl;
        return;
    }
    
    for ( int i = 0; i < vec.size(); i++ )
    {
        cout << vec[i] << "\t" ;
    }
    
    cout << endl;
}