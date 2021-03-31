// Copyright (c) 2020 [Your Name]. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cs126linkedlist/ll.h>


using cs126linkedlist::LinkedList;

// Read more on SECTIONs here:
// `https://github.com/catchorg/Catch2/tree/master/docs`
// in the "Test Cases and Sections" file.

TEST_CASE("Constructors") {
  const std::vector<int> &values = {1, 2, 3, 4, 5};

  SECTION("Default Constructor") {
    auto *list = new LinkedList<int>();
    REQUIRE(list->size() == 0);
  }

  SECTION("Constructor using vector") {
    auto *list = new LinkedList<int>(values);
    REQUIRE(list->size() == 5);
    REQUIRE(list->size() != 7);
  }

  SECTION("Constructor using another list") {
    const auto *source = new LinkedList<int>(values);
    auto list(source);
    REQUIRE(list->size() == 5);
    REQUIRE(source->size() == 5);
  }

  SECTION("Move constructor") {
    const auto source = new LinkedList<int>(values);
    REQUIRE(source->size() == 5);
    LinkedList<int> list(std::move(*source));
    REQUIRE(list.size() == 5);
  }

}/*
TEST_CASE("Push Back", "[constructor][push_back][size][empty]") {
  LinkedList<int> list;

  REQUIRE(list.size() == 0);
  REQUIRE(list.empty());

  SECTION("Push back one element") {
    list.push_back(1);
    REQUIRE(list.size() == 1);
  }

  SECTION("Push back two elements") {
    list.push_back(-1);
    list.push_back(10000);
    REQUIRE(list.size() == 2);
  }
}
*/
