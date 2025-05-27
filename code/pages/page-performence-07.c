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
FOSSIL_SUITE(c_performence_suite);

// Setup function for the test suite
FOSSIL_SETUP(c_performence_suite) {}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_performence_suite) {}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// Simple test case for 2 + 2
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_performence_test_simple_math) {
    MARK_BENCHMARK("Simple Math Benchmark");

    MARK_START("Simple Math Benchmark");
    int result = 2 + 2;
    MARK_STOP("Simple Math Benchmark");

    ASSUME_ITS_EQUAL_I32(4, result);

    MARK_REPORT("Simple Math Benchmark");
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_performence_tests) {
    FOSSIL_TEST_ADD(c_performence_suite, c_performence_test_simple_math);

    FOSSIL_TEST_REGISTER(c_performence_suite);
}
