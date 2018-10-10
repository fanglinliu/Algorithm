//
//  BFS.m
//  Tests
//
//  Created by fanglliu on 2018/10/6.
//  Copyright © 2018 zto. All rights reserved.
//

#import <XCTest/XCTest.h>

#import "BFS.hpp"
#include "permute.hpp"


@interface BFS : XCTestCase

@end

@implementation BFS

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testBFS {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
    Node *tree = createTree();
    TBFS(tree);
}

- (void)testPermuate {
    permuate(3);
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
