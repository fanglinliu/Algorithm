//
//  main.m
//  TestAlgorithm
//
//  Created by fanglliu on 3/19/16.
//  Copyright © 2016 fanglliu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <iostream>

typedef struct tagNode
{
    int value;
    struct tagNode* next;
} Node;


Node* create_list()
{
    Node* head = NULL;
    Node* tail = NULL;
    for ( int i = 0; i < 5; i++) {
        Node* tmp = new Node;
        tmp->value = i;
        tmp->next = NULL;
        
        if ( tail != NULL )
        {
            tail->next = tmp;
        }
        
        tail = tmp;
        
        if ( i == 0 )
        {
            head = tmp;
        }
        
    }
    
    return head;
}

void print_list(Node* list)
{
    Node* p = list;
    while (p) {
        int value = p->value;
        std::cout << value << std::endl;
        
        p = p->next;
    }
}


Node* reverse_list(Node* list)
{
    Node* orginHead = list;
    Node* reverseHead = NULL;
    while ( orginHead )
    {
        Node* tmp = orginHead;
        orginHead = orginHead->next;
        
        tmp->next = reverseHead;
        reverseHead = tmp;
    }
    
    return reverseHead;
}

Node recursive_reverse_list(Node* list)
{
    Node reversed_list;
    Node* head = list;
    Node* next = head->next;
    
    if ( next )
    {
        reversed_list = recursive_reverse_list(next);
        head->next = NULL;
        next->next = head;
        
    }
    else
    {
        head->next = NULL;
    }
    
    return reversed_list;
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        Node* p = create_list();
        print_list(p);
        
        NSLog(@"Hello, World!");

//        Node* reversed_list = reverse_list(p);
//        print_list(reversed_list);
        
        List reversed_list = recursive_reverse_list(p);
        print_list(reversed_list.head);
        
    }
    return 0;
}


