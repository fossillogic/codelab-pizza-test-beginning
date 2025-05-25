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

// Define the test suite and add test cases
FOSSIL_SUITE(c_domain_driven_development_suite);

FOSSIL_MOCK_STRUCT(Pizza) {
    int id;
    const char *name;
    const char *size;
    double price;
} Pizza;

Pizza c_pizza;

FOSSIL_MOCK_STRUCT(Order) {
    int id;
    Pizza c_pizza;
    int quantity;
    const char *customer_name;
    const char *delivery_address;
} Order;

Order c_order;

// Setup function for the test suite
FOSSIL_SETUP(c_domain_driven_development_suite) {
    // Initialize the Pizza mock structure
    c_pizza.id = 1;
    c_pizza.name = "Margherita";
    c_pizza.size = "Medium";
    c_pizza.price = 8.99;

    // Initialize the Order mock structure
    c_order.id = 1;
    c_order.c_pizza = c_pizza;
    c_order.quantity = 2;
    c_order.customer_name = "John Doe";
    c_order.delivery_address = "123 Pizza Lane, Pizzatown";
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_domain_driven_development_suite) {
    // Reset the Pizza mock structure
    c_pizza.id = 0;
    c_pizza.name = NULL;
    c_pizza.size = NULL;
    c_pizza.price = 0.0;

    // Reset the Order mock structure
    c_order.id = 0;
    c_order.c_pizza = c_pizza;
    c_order.quantity = 0;
    c_order.customer_name = NULL;
    c_order.delivery_address = NULL;
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Cases for Pizza Domain
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_domain_driven_development_test_c_pizza_initialization) {
    // Assert
    ASSUME_ITS_EQUAL_I32(1, c_pizza.id);
    ASSUME_ITS_EQUAL_CSTR("Margherita", c_pizza.name);
    ASSUME_ITS_EQUAL_CSTR("Medium", c_pizza.size);
}

FOSSIL_TEST(c_domain_driven_development_test_c_order_initialization) {
    // Assert
    ASSUME_ITS_EQUAL_I32(1, c_order.id);
    ASSUME_ITS_EQUAL_I32(2, c_order.quantity);
    ASSUME_ITS_EQUAL_CSTR("John Doe", c_order.customer_name);
    ASSUME_ITS_EQUAL_CSTR("123 Pizza Lane, Pizzatown", c_order.delivery_address);

    // Verify nested Pizza structure
    ASSUME_ITS_EQUAL_I32(1, c_order.c_pizza.id);
    ASSUME_ITS_EQUAL_CSTR("Margherita", c_order.c_pizza.name);
    ASSUME_ITS_EQUAL_CSTR("Medium", c_order.c_pizza.size);
    ASSUME_ITS_EQUAL_F64(8.99, c_order.c_pizza.price, FOSSIL_TEST_DOUBLE_EPSILON);
}

FOSSIL_TEST(c_domain_driven_development_test_c_pizza_price_update) {
    // Act
    c_pizza.price = 10.99;

    // Assert
    ASSUME_ITS_EQUAL_F64(10.99, c_pizza.price, FOSSIL_TEST_DOUBLE_EPSILON);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_domain_driven_development_tests) {
    FOSSIL_TEST_ADD(c_domain_driven_development_suite, c_domain_driven_development_test_c_pizza_initialization);
    FOSSIL_TEST_ADD(c_domain_driven_development_suite, c_domain_driven_development_test_c_order_initialization);
    FOSSIL_TEST_ADD(c_domain_driven_development_suite, c_domain_driven_development_test_c_pizza_price_update);

    FOSSIL_TEST_REGISTER(c_domain_driven_development_suite);
}
