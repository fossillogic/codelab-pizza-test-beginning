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

// TODO: Note to myself, support built-in prameters in the next release.

// Define the test suite and add test cases
FOSSIL_SUITE(c_params_suite);

// Setup function for the test suite
FOSSIL_SETUP(c_params_suite) {}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_params_suite) {}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_params_test_simple_math) {
    int a = 2;
    int b = 2;
    int result = a + b;
    ASSUME_ITS_EQUAL_I32(4, result);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_params_tests) {
    FOSSIL_TEST_ADD(c_params_suite, c_params_test_simple_math);

    FOSSIL_TEST_REGISTER(c_params_suite);
}
