// Copyright (c) 2020 CS126SP20. All rights reserved.

#include "ll.h"

#include <cassert>
#include <utility>
#include <vector>

namespace cs126linkedlist {

// Default Constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList() {
  head->element = NULL;
  head->nextItem = nullptr;
  head->previousItem = nullptr;
}

// Vector to List constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType>& values) {
  Node *previous = head;
  head->previousItem = nullptr;
  head->element = values.at(0);
  if (values.size() <= 1) {
    head->nextItem = nullptr;
  } else {
    for (size_t i = 1; i < values.size(); i++) {
      Node *current_node = new Node();
      previous->nextItem = current_node;
      current_node->element = values.at(i);
      current_node->previousItem = previous;
      if (i + 1 == values.size()) {
        current_node->nextItem = nullptr;
      }
      previous = current_node;
    }
  }
}

// Copy constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {
  Node *previous = head;
  head->previousItem = nullptr;
  head->element = source.head->element;
  if (source.size() <= 1) {
    head->nextItem = nullptr;
  } else {
    Node *source_node = source.head->nextItem;
    for (size_t i = 1; i < source.size(); i++) {
      Node* current_node = new Node();
      previous->nextItem = current_node;
      current_node->element = source_node->element;
      current_node->previousItem = previous;
      previous = current_node;
      if (i + 1 == source.size()) {
        current_node->nextItem = nullptr;
      }
      source_node = source_node->nextItem;
      previous = current_node;

    }
  }
}

// Move constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {
  head = source.head;
  source.head = nullptr;
}

// Destructor
template <typename ElementType>
LinkedList<ElementType>::~LinkedList() {
  clear();
  delete head;
}

// Copy assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    const LinkedList<ElementType>& source) {
  Node *previous = head;
  head->previousItem = nullptr;
  head->element = source.head->element;
  if (source.size() <= 1) {
    head->nextItem = nullptr;
  } else {
    Node *source_node = source.head->nextItem;
    for (size_t i = 1; i < source.size(); i++) {
      Node* current_node = new Node();
      previous->nextItem = current_node;
      current_node->element = source_node->element;
      current_node->previousItem = previous;
      previous = current_node;
      if (i + 1 == source.size()) {
        current_node->nextItem = nullptr;
      }
      source_node = source_node->nextItem;
      previous = current_node;

    }
  }
  return *this;
}

// Move assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    LinkedList<ElementType>&& source) noexcept {
  head = source.head;
  source.head = nullptr;
  return *this;
}

template <typename ElementType>
void LinkedList<ElementType>::push_front(const ElementType& value) {
  Node *new_node = new Node();
  new_node->nextItem = head;
  new_node->previousItem = nullptr;
  new_node->element = value;
  head->previousItem = new_node;
  head = new_node;
}

template <typename ElementType>
void LinkedList<ElementType>::push_back(const ElementType& value) {
    Node *new_node = new Node();
    new_node->nextItem = nullptr;
    new_node->element = value;
    Node *current_node = head;
    while (current_node->nextItem != nullptr) {
      current_node = current_node->nextItem;
    }
    current_node->nextItem = new_node;
    new_node->previousItem = current_node;
}

template <typename ElementType>
ElementType LinkedList<ElementType>::front() const {
  return head->element;
}

template <typename ElementType>
ElementType LinkedList<ElementType>::back() const {
  Node *current_node = head;
  while (current_node->nextItem != nullptr) {
    current_node = current_node->nextItem;
  }
  return current_node->element;
}

template <typename ElementType>
void LinkedList<ElementType>::pop_front() {
  Node *next_node = head->nextItem;
  next_node->previousItem = nullptr;
  delete head;
  head = next_node;
}

template <typename ElementType>
void LinkedList<ElementType>::pop_back() {
  Node *current_node = head;
  while (current_node->nextItem != nullptr) {
    current_node = current_node->nextItem;
  }
  current_node->previousItem->nextItem = nullptr;
  delete current_node;
}

template <typename ElementType>
size_t LinkedList<ElementType>::size_helper(Node *node) const{
  if (node->nextItem == nullptr) {
    return 1;
  }
  return 1 + size_helper(node->nextItem);
}

template <typename ElementType>
size_t LinkedList<ElementType>::size() const {
  if (head == nullptr) {
    return 0;
  }
  if (head->nextItem == nullptr) {
    if (head->element != NULL) {
      return 1;
    }
    return 0;
  }
  return 1 + size_helper(head->nextItem);
}

template <typename ElementType>
bool LinkedList<ElementType>::empty() const {
  if (size() == 0) {
    return true;
  } else if (size() == 1 && head->element == NULL) {
    return true;
  }
  Node *current_node = head;
  while(current_node->nextItem != nullptr) {
    if (current_node->element != NULL) {
      return false;
    }
    current_node = current_node->nextItem;
  }
  return true;
}

template <typename ElementType>
void LinkedList<ElementType>::clear() {
  if (size() > 1) {
    Node *current_node = head->nextItem;
    head->nextItem = nullptr;
    while (current_node->nextItem != nullptr) {
      current_node = current_node->nextItem;
      delete current_node->previousItem;
    }
    delete current_node;
  }
  head->element = NULL;
}

template <typename ElementType>
std::ostream& operator<<(std::ostream& os,
                         const LinkedList<ElementType>& list) {
  cs126linkedlist::LinkedList<ElementType>::const_iterator iter = list.begin();
  for (size_t i = 0; i < list.size(); i++) {
    std::cout << iter.operator*();
    if(i + 1 == list.size()) {
      std::cout << ".";
    } else {
      std::cout << ", ";
    }
    *iter.operator++();
  }
  return os;
}

template <typename ElementType>
void LinkedList<ElementType>::RemoveNth(size_t n) {
  if (n == 0) {
    pop_front();
    return;
  } else if (n == size() - 1){
    pop_back();
    return;
  }
  Node *current_node = head;
  for (size_t i = 0; i < n; i++) {
    current_node = current_node->nextItem;
  }
  current_node->previousItem->nextItem = current_node->nextItem;
  current_node->nextItem->previousItem = current_node->previousItem;
  delete current_node;
}

template <typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {
  for (size_t i = 1; i < size(); i++) {
    RemoveNth(i);
  }
}

template <typename ElementType>
bool LinkedList<ElementType>::operator==(
    const LinkedList<ElementType>& rhs) const {
  Node *current_node = head;
  Node *current_rhs = rhs.head;
  if (size() != rhs.size()) {
    return false;
  }
  for (size_t i = 0; i < size(); i++) {
    if (current_node->element != current_rhs->element) {
      return false;
    }
    if (i + 1 != size()) {
      current_node = current_node->nextItem;
      current_rhs = current_rhs->nextItem;
    } else {
      return true;
    }
  }
  return false;
}

template <typename ElementType>
bool LinkedList<ElementType>::operator!=(
    const LinkedList<ElementType>& rhs) const {
  if (*this == rhs) {
    return false;
  }
  return true;
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator& LinkedList<ElementType>::iterator::operator++() {
  current_ = current_->nextItem;
  return *this;
}

template <typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() const {
  return current_->element;
}

template <typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(
    const typename LinkedList<ElementType>::iterator& other) const {}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {
  return iterator(this->head);
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {
  auto my_iterator = this->begin();
  for (size_t i = 1; i < size(); i++) {
    my_iterator++;
  }
  return my_iterator;
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator&
LinkedList<ElementType>::const_iterator::operator++() {
  current_ = current_->nextItem;
  return *this;
}

template <typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() const {
  return current_->element;
}

template <typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(
    const typename LinkedList<ElementType>::const_iterator& other) const {}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator
LinkedList<ElementType>::begin() const {
  return const_iterator(this->head);
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end()
    const {
  Node *current_node = this->head;
  for (int i = 0; i < size(); i++) {
    current_node = current_node->nextItem;
  }
  return iterator(current_node);
}

}  // namespace cs126linkedlist
