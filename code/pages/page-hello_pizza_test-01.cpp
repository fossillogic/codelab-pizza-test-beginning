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
FOSSIL_SUITE(cpp_hello_pizza_test_suite);

// Setup function for the test suite
FOSSIL_SETUP(cpp_hello_pizza_test_suite) {}

// Teardown function for the test suite
FOSSIL_TEARDOWN(cpp_hello_pizza_test_suite) {}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// Simple test case for 2 + 2
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(cpp_hello_pizza_test_test_simple_math) {
    int result = 2 + 2;
    ASSUME_ITS_EQUAL_I32(4, result);
}

FOSSIL_TEST(cpp_hello_pizza_test_test_unsigned_math) {
    uint32_t actual = 10;
    uint32_t expected = 5;

    ASSUME_NOT_EQUAL_U32(actual, expected);
    ASSUME_NOT_LESS_THAN_U32(actual, expected);
    ASSUME_NOT_MORE_THAN_U32(expected, actual);
    ASSUME_NOT_LESS_OR_EQUAL_U32(actual, expected);
    ASSUME_NOT_MORE_OR_EQUAL_U32(expected, actual);
}

FOSSIL_TEST(cpp_hello_pizza_test_test_signed_math) {
    int32_t actual = -10;
    int32_t expected = -5;

    ASSUME_NOT_EQUAL_I32(actual, expected);
    ASSUME_NOT_LESS_THAN_I32(expected, actual);
    ASSUME_NOT_MORE_THAN_I32(actual, expected);
    ASSUME_NOT_LESS_OR_EQUAL_I32(expected, actual);
    ASSUME_NOT_MORE_OR_EQUAL_I32(actual, expected);
}

FOSSIL_TEST(cpp_hello_pizza_test_test_soap_rot_brain) {
    const char *text = "This is a clean and clear sentence.";
    ASSUME_NOT_SOAP_ROT_BRAIN(text);

    const char *rot_brain_text = "This sentence contains rizz language.";
    ASSUME_ITS_SOAP_ROT_BRAIN(rot_brain_text);
}

FOSSIL_TEST(cpp_hello_pizza_test_test_soap_tone_detection) {
    const char *formal_text = "Dear Sir or Madam, I hope this message finds you well.";
    ASSUME_ITS_SOAP_TONE_DETECTED(formal_text, "formal");

    const char *casual_text = "Hey, what's up?";
    ASSUME_ITS_SOAP_TONE_DETECTED(casual_text, "casual");

    const char *sarcasticpp_text = "Oh, great, another meeting. Just what I needed.";
    ASSUME_ITS_SOAP_TONE_DETECTED(sarcasticpp_text, "sarcastic");

    const char *incorrect_tone_text = "This is a neutral statement.";
    ASSUME_NOT_SOAP_TONE_DETECTED(incorrect_tone_text, "sarcastic");
}

FOSSIL_TEST(cpp_hello_pizza_test_test_cstr_equality) {
    const char *actual = "hello";
    const char *expected = "hello";
    ASSUME_ITS_EQUAL_CSTR(actual, expected);

    const char *not_expected = "world";
    ASSUME_NOT_EQUAL_CSTR(actual, not_expected);
}

FOSSIL_TEST(cpp_hello_pizza_test_test_cstr_length) {
    const char *text = "hello";
    ASSUME_ITS_LENGTH_EQUAL_CSTR(text, 5);
    ASSUME_NOT_LENGTH_EQUAL_CSTR(text, 10);
}

FOSSIL_TEST(cpp_hello_pizza_test_test_cstr_prefix_suffix) {
    const char *text = "hello world";
    ASSUME_ITS_CSTR_STARTS_WITH(text, "hello");
    ASSUME_NOT_CSTR_STARTS_WITH(text, "world");

    ASSUME_ITS_CSTR_ENDS_WITH(text, "world");
    ASSUME_NOT_CSTR_ENDS_WITH(text, "hello");
}

FOSSIL_TEST(cpp_hello_pizza_test_test_cstr_contains) {
    const char *text = "hello world";
    ASSUME_ITS_CSTR_CONTAINS(text, "world");
    ASSUME_NOT_CSTR_CONTAINS(text, "pizza");
}

FOSSIL_TEST(cpp_hello_pizza_test_test_cstr_count) {
    const char *text = "hello hello world";
    ASSUME_ITS_CSTR_COUNT(text, "hello", 2);
    ASSUME_NOT_CSTR_COUNT(text, "hello", 3);
}

FOSSIL_TEST(cpp_hello_pizza_test_test_pointer_nullability) {
    void *null_ptr = null;
    void *non_null_ptr = (void *)0x1;

    ASSUME_ITS_CNULL(null_ptr);
    ASSUME_NOT_CNULL(non_null_ptr);

    ASSUME_ITS_CNULLABLE(null_ptr);
    ASSUME_NOT_CNULLABLE(non_null_ptr);

    ASSUME_ITS_CNONNULL(non_null_ptr);
    ASSUME_NOT_CNONNULL(null_ptr);
}

FOSSIL_TEST(cpp_hello_pizza_test_test_likely_unlikely_conditions) {
    int likely_condition = 1;
    int unlikely_condition = 0;

    ASSUME_ITS_LIKELY(likely_condition);
    ASSUME_NOT_LIKELY(unlikely_condition);

    ASSUME_ITS_UNLIKELY(likely_condition);
    ASSUME_NOT_UNLIKELY(unlikely_condition);
}

FOSSIL_TEST(cpp_hello_pizza_test_test_pointer_equality) {
    void *ptr1 = (void *)0x1;
    void *ptr2 = (void *)0x1;
    void *ptr3 = (void *)0x2;

    ASSUME_ITS_EQUAL_PTR(ptr1, ptr2);
    ASSUME_NOT_EQUAL_PTR(ptr1, ptr3);
}

FOSSIL_TEST(cpp_hello_pizza_test_test_size_comparisons) {
    size_t size1 = 10;
    size_t size2 = 20;

    ASSUME_ITS_EQUAL_SIZE(size1, 10);
    ASSUME_ITS_LESS_THAN_SIZE(size1, size2);
    ASSUME_ITS_MORE_THAN_SIZE(size2, size1);
    ASSUME_ITS_LESS_OR_EQUAL_SIZE(size1, 10);
    ASSUME_ITS_LESS_OR_EQUAL_SIZE(size1, size2);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(cpp_hello_pizza_test_tests) {
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_simple_math);
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_unsigned_math);
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_signed_math);
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_soap_rot_brain);
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_soap_tone_detection);
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_cstr_equality);
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_cstr_length);
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_cstr_prefix_suffix);
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_cstr_contains);
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_cstr_count);
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_pointer_nullability);
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_likely_unlikely_conditions);
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_pointer_equality);
    FOSSIL_TEST_ADD(cpp_hello_pizza_test_suite, cpp_hello_pizza_test_test_size_comparisons);

    FOSSIL_TEST_REGISTER(cpp_hello_pizza_test_suite);
}
