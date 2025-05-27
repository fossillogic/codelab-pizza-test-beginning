/*
 * -----------------------------------------------------------------------------
 * Project: Codelab by Fossil Logic
 *
 * This file is part of the Codelab project, an educational initiative by Fossil
 * Logic to teach and demonstrate software development best practices. The code
 * contained herein is subject to the terms and conditions defined in the project
 * license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2014-2025 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include <fossil/pizza/framework.h>

// TODO: Note to myself, must add a clean way to call mock functions to avoid the tag in next release.

// Define the test suite and add test cases
FOSSIL_SUITE(cpp_mocking_test_suite);

FOSSIL_MOCK_STRUCT(ShoppingCart) {
    int id;
    const char *name;
    double total_price;
};

ShoppingCart cpp_cart;

FOSSIL_MOCK_STRUCT(Item) {
    int id;
    const char *name;
    double price;
};

Item cpp_item;

// Mock function to add an item to the shopping cart
FOSSIL_MOCK_FUNC(void, cpp_add_item_to_cart, ShoppingCart *cart, Item *item) {
    cart->total_price += item->price;
}

// Mock function to calculate the total price of the shopping cart
FOSSIL_MOCK_FUNC(double, cpp_calculate_total_price, ShoppingCart *cart) {
    return cart->total_price;
}

// Mock function to clear the shopping cart
FOSSIL_MOCK_FUNC(void, cpp_clear_cart, ShoppingCart *cart) {
    cart->total_price = 0.0;
}


// Setup function for the test suite
FOSSIL_SETUP(cpp_mocking_test_suite) {
    // Initialize the ShoppingCart mock structure
    cpp_cart.id = 1;
    cpp_cart.name = "Test Cart";
    cpp_cart.total_price = 0.0;

    // Initialize the Item mock structure
    cpp_item.id = 1;
    cpp_item.name = "Test Item";
    cpp_item.price = 10.0;

    // Add the item to the cart
    fossil_mockup_cpp_add_item_to_cart(&cpp_cart, &cpp_item);
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(cpp_mocking_test_suite) {
    // Reset the ShoppingCart mock structure
    cpp_cart.id = 0;
    cpp_cart.name = NULL;
    cpp_cart.total_price = 0.0;

    // Reset the Item mock structure
    cpp_item.id = 0;
    cpp_item.name = NULL;
    cpp_item.price = 0.0;

    // Clear the cart
    fossil_mockup_cpp_clear_cart(&cpp_cart);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(cpp_mocking_test_add_item_to_cart) {
    GIVEN("an empty shopping cart and an item") {
        ShoppingCart cart = {1, "Test Cart", 0.0};
        Item item = {1, "Test Item", 10.0};

        WHEN("the item is added to the cart") {
            fossil_mockup_cpp_add_item_to_cart(&cart, &item);

            THEN("the total price of the cart should be updated") {
                ASSUME_ITS_EQUAL_F64(10.0, cart.total_price, FOSSIL_TEST_DOUBLE_EPSILON);
            }
        }
    }
}

FOSSIL_TEST(cpp_mocking_test_calculate_total_price) {
    GIVEN("a shopping cart with items") {
        ShoppingCart cart = {1, "Test Cart", 20.0};

        WHEN("calculating the total price") {
            double total = fossil_mockup_cpp_calculate_total_price(&cart);

            THEN("the total price should match the cart's total price") {
                ASSUME_ITS_EQUAL_F64(20.0, total, FOSSIL_TEST_DOUBLE_EPSILON);
            }
        }
    }
}

FOSSIL_TEST(cpp_mocking_test_clear_cart) {
    GIVEN("a shopping cart with items") {
        ShoppingCart cart = {1, "Test Cart", 30.0};

        WHEN("the cart is cleared") {
            fossil_mockup_cpp_clear_cart(&cart);

            THEN("the total price should be reset to 0") {
                ASSUME_ITS_EQUAL_F64(0.0, cart.total_price, FOSSIL_TEST_DOUBLE_EPSILON);
            }
        }
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(cpp_mocking_tests) {
    FOSSIL_TEST_ADD(cpp_mocking_test_suite, cpp_mocking_test_add_item_to_cart);
    FOSSIL_TEST_ADD(cpp_mocking_test_suite, cpp_mocking_test_calculate_total_price);
    FOSSIL_TEST_ADD(cpp_mocking_test_suite, cpp_mocking_test_clear_cart);

    FOSSIL_TEST_REGISTER(cpp_mocking_test_suite);
}
