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
FOSSIL_SUITE(cpp_domain_driven_development_suite);

FOSSIL_MOCK_STRUCT(Pizza) {
    int id;
    const char *name;
    const char *size;
    double price;
};

Pizza cpp_pizza;

FOSSIL_MOCK_STRUCT(Order) {
    int id;
    Pizza cpp_pizza;
    int quantity;
    const char *customer_name;
    const char *delivery_address;
};

Order cpp_order;

// Setup function for the test suite
FOSSIL_SETUP(cpp_domain_driven_development_suite) {
    // Initialize the Pizza mock structure
    cpp_pizza.id = 1;
    cpp_pizza.name = "Margherita";
    cpp_pizza.size = "Medium";
    cpp_pizza.price = 8.99;

    // Initialize the Order mock structure
    cpp_order.id = 1;
    cpp_order.cpp_pizza = cpp_pizza;
    cpp_order.quantity = 2;
    cpp_order.customer_name = "John Doe";
    cpp_order.delivery_address = "123 Pizza Lane, Pizzatown";
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(cpp_domain_driven_development_suite) {
    // Reset the Pizza mock structure
    cpp_pizza.id = 0;
    cpp_pizza.name = NULL;
    cpp_pizza.size = NULL;
    cpp_pizza.price = 0.0;

    // Reset the Order mock structure
    cpp_order.id = 0;
    cpp_order.cpp_pizza = cpp_pizza;
    cpp_order.quantity = 0;
    cpp_order.customer_name = NULL;
    cpp_order.delivery_address = NULL;
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Cases for Pizza Domain
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(cpp_domain_driven_development_test_cpp_pizza_initialization) {
    // Assert
    ASSUME_ITS_EQUAL_I32(1, cpp_pizza.id);
    ASSUME_ITS_EQUAL_CSTR("Margherita", cpp_pizza.name);
    ASSUME_ITS_EQUAL_CSTR("Medium", cpp_pizza.size);
}

FOSSIL_TEST(cpp_domain_driven_development_test_cpp_order_initialization) {
    // Assert
    ASSUME_ITS_EQUAL_I32(1, cpp_order.id);
    ASSUME_ITS_EQUAL_I32(2, cpp_order.quantity);
    ASSUME_ITS_EQUAL_CSTR("John Doe", cpp_order.customer_name);
    ASSUME_ITS_EQUAL_CSTR("123 Pizza Lane, Pizzatown", cpp_order.delivery_address);

    // Verify nested Pizza structure
    ASSUME_ITS_EQUAL_I32(1, cpp_order.cpp_pizza.id);
    ASSUME_ITS_EQUAL_CSTR("Margherita", cpp_order.cpp_pizza.name);
    ASSUME_ITS_EQUAL_CSTR("Medium", cpp_order.cpp_pizza.size);
    ASSUME_ITS_EQUAL_F64(8.99, cpp_order.cpp_pizza.price, FOSSIL_TEST_DOUBLE_EPSILON);
}

FOSSIL_TEST(cpp_domain_driven_development_test_cpp_pizza_price_update) {
    // Act
    cpp_pizza.price = 10.99;

    // Assert
    ASSUME_ITS_EQUAL_F64(10.99, cpp_pizza.price, FOSSIL_TEST_DOUBLE_EPSILON);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(cpp_domain_driven_development_tests) {
    FOSSIL_TEST_ADD(cpp_domain_driven_development_suite, cpp_domain_driven_development_test_cpp_pizza_initialization);
    FOSSIL_TEST_ADD(cpp_domain_driven_development_suite, cpp_domain_driven_development_test_cpp_order_initialization);
    FOSSIL_TEST_ADD(cpp_domain_driven_development_suite, cpp_domain_driven_development_test_cpp_pizza_price_update);

    FOSSIL_TEST_REGISTER(cpp_domain_driven_development_suite);
}
