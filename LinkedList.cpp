
#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

LinkedList::~LinkedList() { clear(); }

void LinkedList::clear() {
  Node* current = head;
  Node* next = nullptr;

  while (current) {
    next = current->next;
    delete current;
    current = next;
  }

  list_size = 0;
}

int LinkedList::getSize() { return list_size; }

Tile* LinkedList::getFront() { return head->getTile(); }

bool LinkedList::contains(Tile* tile) {
  bool found = false;
  Node* current = head;

  while (!found && current) {
    if (current->getTile()->equals(tile)) {
      found = true;
    }
    current = current->next;
  }

  return found;
}

void LinkedList::addTile(Tile* tile) {
  Node* temp = new Node(tile, nullptr);

  if (list_size == 0) {  // if list is empty
    tail = temp;
    head = tail;
  } else {
    tail->next = temp;
    tail = temp;  // set new tail pointer
  }

  list_size++;
}

void LinkedList::deleteFront() {
  if (list_size > 0) {
    if (list_size == 1) {  // if there's only one element in the list
      delete head;
      head = nullptr;
      tail = nullptr;
    } else {
      Node* prevHead = head;
      head = head->next;
      delete prevHead;
      list_size--;
    }
  } else {
    // error: list is empty
  }
}

void LinkedList::replaceTile(Tile* tile, Tile* newTile) {
  if (list_size == 0) {
    // error: list is empty
  } else {
    bool found = false;
    Node* newNode = new Node(newTile, nullptr);

    if (tile->equals(head->getTile())) {  // if tile to delete is at head
      deleteFront();
    } else {  // if tile to delete is at the end or in the middle
      Node* current = head;
      Node* prev = nullptr;

      while (!found && current) {
        if (current->getTile()->equals(tile)) {
          found = true;
        } else {
          prev = current;
          current = current->next;
        }
      }

      if (found) {
        prev->next = newNode;
        newNode->next = current->next;
        delete current;
        list_size--;
      }
    }
  }
}

void LinkedList::displayContents() {
  if (list_size > 0) {  // if list is not empty
    Node* current = head;
    int i = 0;

    while (i < list_size) {
      std::cout << current->getTile()->toString();

      if (i != list_size - 1) std::cout << ",";

      current = current->next;
      i++;
    }

    std::cout << std::endl;
  }
}