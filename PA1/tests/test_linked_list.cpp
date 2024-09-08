/*
Name: Group 12
Class: CPSC223, Fall 2024
Date: September 7, 2024
Programming Assignment: Project 1
Description: This cpp linked list unit tests
*/

#include "unit_test.hpp"

void testAppend() {
    StreetLinkedList list("Sharp");

    Node node1(1, "Cincinnati", "Dakota");
    Node node2(2, "Dakota", "Standard");

    list.append(node1);
    list.append(node2);

    assert(list.findSize() == 2);
    assert(list.head->approachingStreet == "Cincinnati");
    assert(list.tail->leavingStreet == "Standard");
    std::cout << "testAppend passed successfully!" << std::endl;
}


void testInsertNode() {
    StreetLinkedList list("Sharp");

    Node node1(1, "Cincinnati", "Dakota");
    Node node2(2, "Dakota", "Standard");
    Node node3(3, "Standard", "Astor");

    list.append(node1);
    list.append(node2);
    list.insertNode(node3, 1);

    assert(list.findSize() == 3);
    assert(list.head->next->approachingStreet == "Standard");
    assert(list.head->next->next->approachingStreet == "Dakota");
    std::cout << "testInsertNode passed successfully!" << std::endl;
}


void testDeleteNode() {
    StreetLinkedList list("Sharp");

    Node node1(1, "Cincinnati", "Dakota");
    Node node2(2, "Dakota", "Standard");

    list.append(node1);
    list.append(node2);

    list.deleteNode("Cincinnati", "Dakota");
    assert(list.findSize() == 1);
    assert(list.head->approachingStreet == "Dakota");
    assert(list.tail->leavingStreet == "Standard");

    list.deleteNode("Dakota", "Standard");
    assert(list.findSize() == 0);
    assert(list.head == nullptr);
    assert(list.tail == nullptr);
    std::cout << "testDeleteNode passed successfully!" << std::endl;
}

void testSearchNode() {
    StreetLinkedList list("Sharp");

    Node node1(1, "Cincinnati", "Dakota");
    Node node2(2, "Dakota", "Standard");

    list.append(node1);
    list.append(node2);

    Node* result = list.searchNode("Dakota", "Standard");
    assert(result != nullptr);
    assert(result->approachingStreet == "Dakota");

    result = list.searchNode("Non-existent", "Street");
    assert(result == nullptr);
    std::cout << "testSearchNode passed successfully!" << std::endl;
}


void testPrintList() {
    StreetLinkedList list("Sharp");

    Node node1(1, "Cincinnati", "Dakota");
    Node node2(2, "Dakota", "Standard");

    list.append(node1);
    list.append(node2);

    list.printList();
    std::cout << "testPrintList passed successfully!" << std::endl;
}


void testCopyConstructor() {
    StreetLinkedList list1("Sharp");

    Node node1(1, "Cincinnati", "Dakota");
    Node node2(2, "Dakota", "Standard");

    list1.append(node1);
    list1.append(node2);

    StreetLinkedList list2 = list1;

    assert(list2.findSize() == 2);
    assert(list2.head->approachingStreet == "Cincinnati");
    assert(list2.tail->leavingStreet == "Standard");

    assert(list2.head != list1.head);
    assert(list2.tail != list1.tail);
    std::cout << "testCopyConstructor passed successfully!" << std::endl;
}


void testCopyAssignmentOperator() {
    StreetLinkedList list1("Sharp");
    StreetLinkedList list2("Sinto");

    Node node1(1, "Cincinnati", "Dakota");
    Node node2(2, "Dakota", "Standard");

    list1.append(node1);
    list1.append(node2);

    list2 = list1;

    assert(list2.findSize() == 2);
    assert(list2.head->approachingStreet == "Cincinnati");
    assert(list2.tail->leavingStreet == "Standard");
    assert(list2.head != list1.head);
    assert(list2.tail != list1.tail);
    std::cout << "testCopyAssignmentOperator passed successfully!" << std::endl;
}



