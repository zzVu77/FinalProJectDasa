#pragma once
#include<iostream>
#include"Node.h"
Node* sortedMerge(Node* a, Node* b) {
    Node* result = NULL;
    if (a == NULL) {
        return b;
    }
    else if (b == NULL) {
        return a;
    }

    if (a->data.firstName <= b->data.firstName || (a->data.firstName == b->data.firstName && a->data.lastName <= b->data.lastName)) {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void frontBackSplit(Node* source, Node*& frontRef, Node*& backRef) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    frontRef = source;
    backRef = slow->next;
    slow->next = NULL;
}

void mergeSort(Node*& headRef) {
    Node* head = headRef;
    Node* a;
    Node* b;
    if (head == NULL or head->next == NULL) {
        return;
    }
    frontBackSplit(head, a, b);
    mergeSort(a);
    mergeSort(b);
    headRef = sortedMerge(a, b);
}
