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
FOSSIL_SUITE(c_integration_suite);

FOSSIL_MOCK_STRUCT(PizzaToppings) {
    const char *name;
    int quantity;
} PizzaToppings;

FOSSIL_MOCK_STRUCT(Dough) {
    const char *type;
    double thickness;
} Dough;

FOSSIL_MOCK_STRUCT(Pizza) {
    const char *name;
    PizzaToppings *toppings;
    int topping_count;
    double price;
    Dough dough;
} Pizza;

FOSSIL_MOCK_STRUCT(Customer) {
    const char *name;
    const char *address;
    const char *phone_number;
} Customer;

FOSSIL_MOCK_STRUCT(Order) {
    int order_id;
    Customer customer;
    Pizza *pizzas;
    int pizza_count;
    double total_price;
} Order;

FOSSIL_MOCK_STRUCT(DeliveryDriver) {
    const char *name;
    const char *vehicle;
    int deliveries_completed;
} DeliveryDriver;

// Setup function for the test suite
FOSSIL_SETUP(c_integration_suite) {}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_integration_suite) {}

// Mock function to simulate pizza order processing
FOSSIL_MOCK_FUNC(int, c_process_order, Order *order) {
    if (order == null || order->pizza_count <= 0) {
        return -1; // Invalid order
    }
    
    double total = 0.0;
    for (int i = 0; i < order->pizza_count; i++) {
        total += order->pizzas[i].price;
    }
    
    order->total_price = total;
    return 0; // Success
}

// Mock function to simulate pizza delivery
FOSSIL_MOCK_FUNC(int, c_deliver_pizza, DeliveryDriver *driver, Order *order) {
    if (driver == null || order == null || order->pizza_count <= 0) {
        return -1; // Invalid delivery
    }
    
    driver->deliveries_completed++;
    return 0; // Success
}

// Mock function to simulate customer feedback
FOSSIL_MOCK_FUNC(int, c_submit_feedback, Customer *customer, const char *feedback) {
    if (customer == null || feedback == null || feedback[0] == '\0') {
        return -1; // Invalid feedback
    }
    
    // Simulate storing feedback
    printf("Feedback from %s: %s\n", customer->name, feedback);
    return 0; // Success
}

// Mock function to simulate pizza preparation
FOSSIL_MOCK_FUNC(int, c_prepare_pizza, Pizza *pizza) {
    if (pizza == null || pizza->topping_count <= 0) {
        return -1; // Invalid pizza
    }
    
    // Simulate pizza preparation
    printf("Preparing pizza: %s with %d toppings\n", pizza->name, pizza->topping_count);
    return 0; // Success
}

// Mock function to simulate customer order
FOSSIL_MOCK_FUNC(int, c_place_order, Customer *customer, Order *order) {
    if (customer == null || order == null || order->pizza_count <= 0) {
        return -1; // Invalid order
    }
    
    // Simulate placing an order
    printf("Order placed by %s for %d pizzas\n", customer->name, order->pizza_count);
    return fossil_mockup_c_process_order(order); // Process the order
}

// Mock function to simulate customer registration
FOSSIL_MOCK_FUNC(int, c_register_customer, Customer *customer) {
    if (customer == null || customer->name == null || customer->address == null) {
        return -1; // Invalid customer
    }
    
    // Simulate customer registration
    printf("Customer registered: %s\n", customer->name);
    return 0; // Success
}

// Mock function to simulate customer login
FOSSIL_MOCK_FUNC(int, c_login_customer, Customer *customer, const char *password) {
    if (customer == null || password == null || password[0] == '\0') {
        return -1; // Invalid login
    }
    
    // Simulate customer login
    printf("Customer %s logged in successfully\n", customer->name);
    return 0; // Success
}
// Mock function to simulate customer logout
FOSSIL_MOCK_FUNC(int, c_logout_customer, Customer *customer) {
    if (customer == null) {
        return -1; // Invalid logout
    }
    
    // Simulate customer logout
    printf("Customer %s logged out successfully\n", customer->name);
    return 0; // Success
}
// Mock function to simulate customer account deletion
FOSSIL_MOCK_FUNC(int, c_delete_account, Customer *customer) {
    if (customer == null) {
        return -1; // Invalid account deletion
    }
    
    // Simulate account deletion
    printf("Customer account %s deleted successfully\n", customer->name);
    return 0; // Success
}
// Mock function to simulate customer account update
FOSSIL_MOCK_FUNC(int, c_update_account, Customer *customer, const char *new_address, const char *new_phone_number) {
    if (customer == null || new_address == null || new_phone_number == null) {
        return -1; // Invalid account update
    }
    
    // Simulate account update
    customer->address = new_address;
    customer->phone_number = new_phone_number;
    printf("Customer account %s updated successfully\n", customer->name);
    return 0; // Success
}
// Mock function to simulate customer order history retrieval
FOSSIL_MOCK_FUNC(int, c_get_order_history, Customer *customer, Order **orders, int *order_count) {
    if (customer == null || orders == null || order_count == null) {
        return -1; // Invalid order history retrieval
    }
    
    // Simulate retrieving order history
    *order_count = 0; // No orders for simplicity
    printf("Order history retrieved for customer %s\n", customer->name);
    return 0; // Success
}
// Mock function to simulate customer password reset
FOSSIL_MOCK_FUNC(int, c_reset_password, Customer *customer, const char *new_password) {
    if (customer == null || new_password == null || new_password[0] == '\0') {
        return -1; // Invalid password reset
    }
    
    // Simulate password reset
    printf("Password for customer %s reset successfully\n", customer->name);
    return 0; // Success
}
// Mock function to simulate customer account verification
FOSSIL_MOCK_FUNC(int, c_verify_account, Customer *customer, const char *verification_code) {
    if (customer == null || verification_code == null || verification_code[0] == '\0') {
        return -1; // Invalid account verification
    }
    
    // Simulate account verification
    printf("Account for customer %s verified successfully\n", customer->name);
    return 0; // Success
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// Simple test case for 2 + 2
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_integration_test_pizza_order_processing) {
    PizzaToppings toppings[] = {{"Cheese", 2}, {"Pepperoni", 3}};
    Dough dough = {"Thin Crust", 0.5};
    Pizza pizza = {"Pepperoni Pizza", toppings, 2, 12.99, dough};
    Customer customer = {"John Doe", "123 Pizza St", "555-1234"};
    Order order = {1, customer, &pizza, 1, 0.0};

    int result = fossil_mockup_c_process_order(&order);
    ASSUME_ITS_EQUAL_I32(0, result);
    ASSUME_ITS_EQUAL_F64(12.99, order.total_price, 0.01);
}

FOSSIL_TEST(c_integration_test_pizza_delivery) {
    DeliveryDriver driver = {"Jane Smith", "Car", 0};
    PizzaToppings toppings[] = {{"Cheese", 2}, {"Pepperoni", 3}};
    Dough dough = {"Thin Crust", 0.5};
    Pizza pizza = {"Pepperoni Pizza", toppings, 2, 12.99, dough};
    Customer customer = {"John Doe", "123 Pizza St", "555-1234"};
    Order order = {1, customer, &pizza, 1, 12.99};

    int result = fossil_mockup_c_deliver_pizza(&driver, &order);
    ASSUME_ITS_EQUAL_I32(0, result);
    ASSUME_ITS_EQUAL_I32(1, driver.deliveries_completed);
}

FOSSIL_TEST(c_integration_test_pizza_preparation) {
    PizzaToppings toppings[] = {{"Cheese", 2}, {"Pepperoni", 3}};
    Dough dough = {"Thin Crust", 0.5};
    Pizza pizza = {"Pepperoni Pizza", toppings, 2, 12.99, dough};

    int result = fossil_mockup_c_prepare_pizza(&pizza);
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST(c_integration_test_customer_feedback) {
    Customer customer = {"John Doe", "123 Pizza St", "555-1234"};
    const char *feedback = "Great pizza!";

    int result = fossil_mockup_c_submit_feedback(&customer, feedback);
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST(c_integration_test_customer_registration) {
    Customer customer = {"John Doe", "123 Pizza St", "555-1234"};
    int result = fossil_mockup_c_register_customer(&customer);
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST(c_integration_test_customer_login) {
    Customer customer = {"John Doe", "123 Pizza St", "555-1234"};
    const char *password = "password123";
    int result = fossil_mockup_c_login_customer(&customer, password);
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST(c_integration_test_customer_logout) {
    Customer customer = {"John Doe", "123 Pizza St", "555-1234"};
    int result = fossil_mockup_c_logout_customer(&customer);
    ASSUME_ITS_EQUAL_I32(0, result);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_integration_tests) {
    FOSSIL_TEST_ADD(c_integration_suite, c_integration_test_pizza_order_processing);
    FOSSIL_TEST_ADD(c_integration_suite, c_integration_test_pizza_delivery);
    FOSSIL_TEST_ADD(c_integration_suite, c_integration_test_pizza_preparation);
    FOSSIL_TEST_ADD(c_integration_suite, c_integration_test_customer_feedback);
    FOSSIL_TEST_ADD(c_integration_suite, c_integration_test_customer_registration);
    FOSSIL_TEST_ADD(c_integration_suite, c_integration_test_customer_login);
    FOSSIL_TEST_ADD(c_integration_suite, c_integration_test_customer_logout);

    FOSSIL_TEST_REGISTER(c_integration_suite);
}
