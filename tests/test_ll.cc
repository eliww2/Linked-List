// Copyright (c) 2020 [Your Name]. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cs126linkedlist/ll.h>


using cs126linkedlist::LinkedList;

TEST_CASE("Size") {
  const std::vector<int> &values = {1, 2, 3, 4, 5};
  auto *list = new LinkedList<int>(values);
  REQUIRE(list->size() == 5);
}

TEST_CASE("Constructors") {
  const std::vector<int> &values = {1, 2, 3, 4, 5};

  SECTION("Default Constructor") {
    auto *list = new LinkedList<int>();
    REQUIRE(list->size() == 0);
  }

  SECTION("Constructor using vector") {
    auto *list = new LinkedList<int>(values);
    REQUIRE(list->size() == 5);
    REQUIRE(list->begin().operator*() == 1);
  }

  SECTION("Constructor using another list") {
    const auto *source = new LinkedList<int>(values);
    auto list(source);
    REQUIRE(list->begin().operator*() == 1);
    REQUIRE(list->size() == 5);
  }

  SECTION("Move constructor") {
    const auto source = new LinkedList<int>(values);
    LinkedList<int> list(std::move(*source));
    REQUIRE(source->size() == 0);
    REQUIRE(list.size() == 5);
  }
}

TEST_CASE("Assignment Operators") {
  const std::vector<int> &values = {1, 2, 3, 4, 5};

  SECTION("Copy Assignment Operator") {
    LinkedList<int> list;
    auto *source = new LinkedList<int>(values);
    list = *source;
    REQUIRE(list.size() == 5);
    list.pop_front();
    REQUIRE(source->size() == 5);
    REQUIRE(list.size() == 4);
  }

  SECTION("Move Assignment Operator") {
    LinkedList<int> list;
    auto *source = new LinkedList<int>(values);
    list = std::move(*source);
    REQUIRE(list.size() == 5);
    REQUIRE(source->size() == 0);
  }
}

TEST_CASE("Insertion operators") {
  const std::vector<int> &values = {1, 2, 3, 4, 5};

  SECTION("Push front") {
    auto *list = new LinkedList<int>(values);
    list->push_front(9);
    REQUIRE(list->begin().operator*() == 9);
  }

  SECTION("Push back") {
    auto *list = new LinkedList<int>(values);
    list->push_back(9);
    auto my_it = list->begin();
    int i = 0;
    while(i < 5) {
      my_it.operator++();
      i++;
    }
    REQUIRE(my_it.operator*() == 9);
  }

}

TEST_CASE("Deletion operators") {
  const std::vector<int> &values = {1, 2, 3, 4, 5};

  SECTION("Pop front") {
    auto *source = new LinkedList<int>(values);
    source->pop_front();
    REQUIRE(source->size() == 4);
    REQUIRE(source->begin().operator*() == 2);
  }
  SECTION("Pop back") {
    auto *source = new LinkedList<int>(values);
    source->pop_back();
    REQUIRE(source->size() == 4);
    REQUIRE(source->begin().operator*() == 1);
  }

  SECTION("RemoveNth") {
    auto *source = new LinkedList<int>(values);
    source->RemoveNth(1);
    REQUIRE(source->begin().operator++().operator*() == 3);
  }

  SECTION("RemoveOdd") {
    auto *source = new LinkedList<int>(values);
    REQUIRE(source->size() == 5);
    source->RemoveOdd();
    REQUIRE(source->size() == 3);
    REQUIRE(source->begin().operator++().operator*() == 3);
  }
}

TEST_CASE("Front and Back") {
  const std::vector<int> &values = {1, 2, 3, 4, 5};

  SECTION("Front") {
    auto *list = new LinkedList<int>(values);
    REQUIRE(list->front() == 1);
  }

  SECTION("Back") {
    auto *list = new LinkedList<int>(values);
    REQUIRE(list->back() == 5);
  }

}

TEST_CASE("Override operators") {
  const std::vector<int> &values = {1, 2, 3, 4, 5};
  const std::vector<int> &other = {1, 2, 3, 4, 4};

  SECTION("operator==") {
    auto *list = new LinkedList<int>(values);
    auto *different = new LinkedList<int>(other);
    auto *same = new LinkedList<int>(values);
    REQUIRE(*list == *same);
    REQUIRE(!(*list == *different));
  }

  SECTION("operator!=") {
    auto *list = new LinkedList<int>(values);
    auto *different = new LinkedList<int>(other);
    auto *same = new LinkedList<int>(values);
    REQUIRE(!(*list != *same));
    REQUIRE(*list != *different);
  }

}

TEST_CASE("Iterator operators") {
  const std::vector<int> &values = {1, 2, 3, 4, 5};

  SECTION("Iterator++") {
    auto *list = new LinkedList<int>(values);
    auto my_it = list->begin();
    auto num = my_it.operator*();
    my_it.operator++();
    REQUIRE(my_it.operator*() != num);
  }

  SECTION("operator*") {
    auto *list = new LinkedList<int>(values);
    REQUIRE(list->begin().operator*() == 1);
  }

  SECTION("Begin") {
    auto *list = new LinkedList<int>(values);
    REQUIRE(list->begin().operator*() == 1);
    REQUIRE(list->begin().operator++().operator*() == 2);
  }

  SECTION("End") {
    auto *list = new LinkedList<int>(values);
    REQUIRE(!(list->begin().operator*() == 5));
  }

}






