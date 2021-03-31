// Copyright (c) 2020 CS126SP20. All rights reserved.

#include "ll.h"

#include <cassert>
#include <utility>
#include <vector>

namespace cs126linkedlist {

template <typename ElementType>
LinkedList<ElementType>::LinkedList() {
  head->element = nullptr;
  head->nextItem = nullptr;
  head->previousItem = nullptr;
}

template <typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType>& values) {
  Node *last_node = head;
  head->previousItem = nullptr;
  head->element = values.at(0);
  if (values.size() <= 1) {
    head->nextItem = nullptr;
  } else {
    for (size_t i = 1; i < values.size(); i++) {
      Node* current_node = new Node();
      last_node->nextItem = current_node;
      current_node->element = values.at(i);
      current_node->previousItem = last_node;
      if (i + 1 == values.size()) {
        current_node->nextItem = nullptr;
      }
      last_node = current_node;
    }
  }
}

// Copy constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {}

// Move constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {

}

// Destructor
template <typename ElementType>
LinkedList<ElementType>::~LinkedList() {}

// Copy assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    const LinkedList<ElementType>& source) {}

// Move assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    LinkedList<ElementType>&& source) noexcept {}

template <typename ElementType>
void LinkedList<ElementType>::push_front(const ElementType& value) {}

template <typename ElementType>
void LinkedList<ElementType>::push_back(const ElementType& value) {}

template <typename ElementType>
ElementType LinkedList<ElementType>::front() const {}

template <typename ElementType>
ElementType LinkedList<ElementType>::back() const {}

template <typename ElementType>
void LinkedList<ElementType>::pop_front() {

}

template <typename ElementType>
void LinkedList<ElementType>::pop_back() {}

template <typename ElementType>
size_t LinkedList<ElementType>::size_helper(Node *node) const{
  if (node->nextItem == nullptr) {
    return 1;
  }
  return 1 + size_helper(node->nextItem);
}

template <typename ElementType>
size_t LinkedList<ElementType>::size() const {
  if (head->nextItem == nullptr) {
    return 0;
  }
  std::cout << head->nextItem->element;
  return 1 + size_helper(head->nextItem);
}

template <typename ElementType>
bool LinkedList<ElementType>::empty() const {}

template <typename ElementType>
void LinkedList<ElementType>::clear() {

}

template <typename ElementType>
std::ostream& operator<<(std::ostream& os,
                         const LinkedList<ElementType>& list) {}

template <typename ElementType>
void LinkedList<ElementType>::RemoveNth(size_t n) {}

template <typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {}

template <typename ElementType>
bool LinkedList<ElementType>::operator==(
    const LinkedList<ElementType>& rhs) const {}

template <typename ElementType>
bool LinkedList<ElementType>::operator!=(
    const LinkedList<ElementType>& rhs) const {}

template <typename ElementType>
typename LinkedList<ElementType>::iterator& LinkedList<ElementType>::iterator::
operator++() {}

template <typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() const {}

template <typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(
    const typename LinkedList<ElementType>::iterator& other) const {}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator&
LinkedList<ElementType>::const_iterator::operator++() {}

template <typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() const {}

template <typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(
    const typename LinkedList<ElementType>::const_iterator& other) const {}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator
LinkedList<ElementType>::begin() const {}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end()
    const {}

}  // namespace cs126linkedlist
