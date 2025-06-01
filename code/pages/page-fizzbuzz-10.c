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
FOSSIL_SUITE(c_fizzbuzz_suite);

// Setup function for the test suite
FOSSIL_SETUP(c_fizzbuzz_suite) {}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_fizzbuzz_suite) {}

char *c_fizzbuzz(int number) {
    if (number % 3 == 0 && number % 5 == 0) {
        return "FizzBuzz";
    } else if (number % 3 == 0) {
        return "Fizz";
    } else if (number % 5 == 0) {
        return "Buzz";
    } else {
        static char buffer[12];
        snprintf(buffer, sizeof(buffer), "%d", number);
        return buffer;
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// solve the test cases for FizzBuzz, be sure to
// remove unused operator when solving these
// test cases.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_fizzbuzz_test_fizz) {
    char *result = c_fizzbuzz(3);
    unused(result); // Suppress unused variable warning
    
    // solve this test case
}

FOSSIL_TEST(c_fizzbuzz_test_buzz) {
    char *result = c_fizzbuzz(5);
    unused(result); // Suppress unused variable warning
    
    // solve this test case
}

FOSSIL_TEST(c_fizzbuzz_test_fizzbuzz) {
    char *result = c_fizzbuzz(15);
    unused(result); // Suppress unused variable warning
    
    // solve this test case
}

FOSSIL_TEST(c_fizzbuzz_test_number) {
    char *result = c_fizzbuzz(7);
    unused(result); // Suppress unused variable warning
    
    // solve this test case
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_fizzbuzz_tests) {
    FOSSIL_TEST_ADD(c_fizzbuzz_suite, c_fizzbuzz_test_fizz);
    FOSSIL_TEST_ADD(c_fizzbuzz_suite, c_fizzbuzz_test_buzz);
    FOSSIL_TEST_ADD(c_fizzbuzz_suite, c_fizzbuzz_test_fizzbuzz);
    FOSSIL_TEST_ADD(c_fizzbuzz_suite, c_fizzbuzz_test_number);

    FOSSIL_TEST_REGISTER(c_fizzbuzz_suite);
}
