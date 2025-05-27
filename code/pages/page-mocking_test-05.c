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
FOSSIL_SUITE(c_mocking_test_suite);

FOSSIL_MOCK_STRUCT(ShoppingCart) {
    int id;
    const char *name;
    double total_price;
} ShoppingCart;

ShoppingCart c_cart;

FOSSIL_MOCK_STRUCT(Item) {
    int id;
    const char *name;
    double price;
} Item;

Item c_item;

// Mock function to add an item to the shopping cart
FOSSIL_MOCK_FUNC(void, c_add_item_to_cart, ShoppingCart *cart, Item *item) {
    cart->total_price += item->price;
}

// Mock function to calculate the total price of the shopping cart
FOSSIL_MOCK_FUNC(double, c_calculate_total_price, ShoppingCart *cart) {
    return cart->total_price;
}

// Mock function to clear the shopping cart
FOSSIL_MOCK_FUNC(void, c_clear_cart, ShoppingCart *cart) {
    cart->total_price = 0.0;
}


// Setup function for the test suite
FOSSIL_SETUP(c_mocking_test_suite) {
    // Initialize the ShoppingCart mock structure
    c_cart.id = 1;
    c_cart.name = "Test Cart";
    c_cart.total_price = 0.0;

    // Initialize the Item mock structure
    c_item.id = 1;
    c_item.name = "Test Item";
    c_item.price = 10.0;

    // Add the item to the cart
    fossil_mockup_c_add_item_to_cart(&c_cart, &c_item);
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_mocking_test_suite) {
    // Reset the ShoppingCart mock structure
    c_cart.id = 0;
    c_cart.name = NULL;
    c_cart.total_price = 0.0;

    // Reset the Item mock structure
    c_item.id = 0;
    c_item.name = NULL;
    c_item.price = 0.0;

    // Clear the cart
    fossil_mockup_c_clear_cart(&c_cart);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_mocking_test_add_item_to_cart) {
    GIVEN("an empty shopping cart and an item") {
        ShoppingCart cart = {1, "Test Cart", 0.0};
        Item item = {1, "Test Item", 10.0};

        WHEN("the item is added to the cart") {
            fossil_mockup_c_add_item_to_cart(&cart, &item);

            THEN("the total price of the cart should be updated") {
                ASSUME_ITS_EQUAL_F64(10.0, cart.total_price, FOSSIL_TEST_DOUBLE_EPSILON);
            }
        }
    }
}

FOSSIL_TEST(c_mocking_test_calculate_total_price) {
    GIVEN("a shopping cart with items") {
        ShoppingCart cart = {1, "Test Cart", 20.0};

        WHEN("calculating the total price") {
            double total = fossil_mockup_c_calculate_total_price(&cart);

            THEN("the total price should match the cart's total price") {
                ASSUME_ITS_EQUAL_F64(20.0, total, FOSSIL_TEST_DOUBLE_EPSILON);
            }
        }
    }
}

FOSSIL_TEST(c_mocking_test_clear_cart) {
    GIVEN("a shopping cart with items") {
        ShoppingCart cart = {1, "Test Cart", 30.0};

        WHEN("the cart is cleared") {
            fossil_mockup_c_clear_cart(&cart);

            THEN("the total price should be reset to 0") {
                ASSUME_ITS_EQUAL_F64(0.0, cart.total_price, FOSSIL_TEST_DOUBLE_EPSILON);
            }
        }
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_mocking_tests) {
    FOSSIL_TEST_ADD(c_mocking_test_suite, c_mocking_test_add_item_to_cart);
    FOSSIL_TEST_ADD(c_mocking_test_suite, c_mocking_test_calculate_total_price);
    FOSSIL_TEST_ADD(c_mocking_test_suite, c_mocking_test_clear_cart);

    FOSSIL_TEST_REGISTER(c_mocking_test_suite);
}
