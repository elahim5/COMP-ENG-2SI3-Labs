/*
 * SLLSet.cpp
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */


#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet() {
    size = 0;
    head = NULL;
}

SLLSet::SLLSet(int sortedArray[], int arrSize) {
    size = arrSize;
    if (size >= 2){
        head = new SLLNode{sortedArray[0], nullptr};
        SLLNode * cnode = head;
        for (int i = 1; i < size; i++){
        	cnode -> next = new SLLNode(sortedArray[i], nullptr);
            cnode = cnode -> next;
        }
    }
}

int SLLSet::getSize() {
    return size;
}

SLLSet SLLSet::copy() {
    SLLSet * temp1 = new SLLSet{};
    temp1 -> size = size;

    if (head == nullptr) {
        return * temp1;
    }

    SLLNode* node = head;
    temp1 -> head = new SLLNode {
    	node -> value, nullptr
    };
    SLLNode * scrollCopy = temp1 -> head;
    node = node -> next;

    while (node != nullptr){
        scrollCopy -> next = new SLLNode {
        	node -> value, nullptr
        };
        scrollCopy = scrollCopy -> next;
        node = node -> next;
    }
    return * temp1;
}

bool SLLSet::isIn(int v) {
    if (size >= 1) {
        SLLNode * node = head;
        while (node -> next != nullptr)
        {
            if (node -> value == v){
                return true;
            }
            node = node -> next;
        }
        if (node -> value == v)
        {
            return true;
        }
    }
    return false;
}

void SLLSet::add(int v) {
    if (head == nullptr){
        head = new SLLNode{
            v, nullptr
        };
        ++size;
        return;
    }

    SLLNode * node = head;
    SLLNode * prev = nullptr;

    while (node != nullptr) {
        if (node -> value == v){
            return;
        }
        else if (node -> value > v) {
            break;
        }
        prev = node;
        node = node -> next;
    }
    //insert value
    if (prev == nullptr) {
        head = new SLLNode {
            v, node
        };
    }
    else {
        prev -> next =  new SLLNode {
            v, node
        };
    }
    ++size;
}

void SLLSet::remove(int v) {
    if (head == nullptr){
        return;
    }
    SLLNode * node = head;
    SLLNode * prev = nullptr;
    while (node != nullptr) {
        if (node -> value == v) {
            break;
        }
        else if (node -> value > v) {
            return;
        }
        prev = node;
        node = node -> next;
    }
    if (node == nullptr){
        return;
    }


    if (prev == nullptr) {
        head = node -> next;
    }
    else {
        prev -> next = node -> next;
    }
    --size;
}

SLLSet SLLSet::setUnion(SLLSet s) {
    SLLNode * node2 = s.head;
    SLLSet temp1 = copy();
    while (node2 != nullptr) {
    	temp1.add(node2 -> value);
        node2 = node2 -> next;
    }
    return temp1;
}

SLLSet SLLSet::intersection(SLLSet s) {
    SLLNode * node2 = s.head;
    SLLSet * temp1 = new SLLSet{};
    while (node2 != nullptr) {
        if (isIn(node2 -> value)) {
        	temp1 -> add(node2 -> value);
        }
        node2 = node2 -> next;
    }
    return * temp1;
}

SLLSet SLLSet::difference(SLLSet s) {
    SLLNode * node2 = s.head;
    SLLSet temp1 = copy();
    while (node2 != nullptr) {
        if (isIn(node2 -> value)) {
        	temp1.remove(node2 -> value);
        }
        node2 = node2 -> next;
    }
    return temp1;
}

SLLSet SLLSet::setUnion(SLLSet sArray[],int size) {
    if (size == 0) {
        return SLLSet{};
    }
    SLLSet temp1 = sArray[0].copy();
    for (int i = 1; i < size; ++i) {
    	temp1 = temp1.setUnion(sArray[i]);
    }
    return temp1;
}

string SLLSet::toString() {
    SLLNode * node2 = head;
    if (node2 == nullptr) {
        return "";
    }
    string temp1 = "";
    while (node2 -> next != nullptr){
    	temp1 += to_string(node2 -> value) + ", ";
        node2 = node2 -> next;
    }
    temp1 += to_string(node2 -> value);
    return temp1;
}
