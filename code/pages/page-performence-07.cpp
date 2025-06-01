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
FOSSIL_SUITE(cpp_performence_suite);

// Setup function for the test suite
FOSSIL_SETUP(cpp_performence_suite) {}

// Teardown function for the test suite
FOSSIL_TEARDOWN(cpp_performence_suite) {}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// Simple test case for 2 + 2
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(cpp_performence_test_simple_math) {
    // Ensure proper macro or function definitions for benchmarking
    MARK_BENCHMARK(simple_math_benchmark);

    MARK_START(simple_math_benchmark);
    int result = 2 + 2;
    MARK_STOP(simple_math_benchmark);

    ASSUME_ITS_EQUAL_I32(4, result);

    MARK_REPORT(simple_math_benchmark);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(cpp_performence_tests) {
    FOSSIL_TEST_ADD(cpp_performence_suite, cpp_performence_test_simple_math);

    FOSSIL_TEST_REGISTER(cpp_performence_suite);
}
