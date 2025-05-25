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
FOSSIL_SUITE(c_test_driven_development_suite);

// Setup function for the test suite
FOSSIL_SETUP(c_test_driven_development_suite) {}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_test_driven_development_suite) {}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// Simple test case for 2 + 2
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_driven_development_test_simple_math) {
    // Arrange
    int a = 2, b = 2;

    // Act
    int result = a + b;

    // Assert
    ASSUME_ITS_EQUAL_I32(4, result);
}

FOSSIL_TEST(c_test_driven_development_test_unsigned_math) {
    // Arrange
    uint32_t actual = 10;
    uint32_t expected = 5;

    // Act & Assert
    ASSUME_NOT_EQUAL_U32(actual, expected);
    ASSUME_NOT_LESS_THAN_U32(actual, expected);
    ASSUME_NOT_MORE_THAN_U32(expected, actual);
    ASSUME_NOT_LESS_OR_EQUAL_U32(actual, expected);
    ASSUME_NOT_MORE_OR_EQUAL_U32(expected, actual);
}

FOSSIL_TEST(c_test_driven_development_test_signed_math) {
    // Arrange
    int32_t actual = -10;
    int32_t expected = -5;

    // Act & Assert
    ASSUME_NOT_EQUAL_I32(actual, expected);
    ASSUME_NOT_LESS_THAN_I32(expected, actual);
    ASSUME_NOT_MORE_THAN_I32(actual, expected);
    ASSUME_NOT_LESS_OR_EQUAL_I32(expected, actual);
    ASSUME_NOT_MORE_OR_EQUAL_I32(actual, expected);
}

FOSSIL_TEST(c_test_driven_development_test_soap_rot_brain) {
    // Arrange
    const char *text = "This is a clean and clear sentence.";
    const char *rot_brain_text = "This sentence contains rizz language.";

    // Act & Assert
    ASSUME_NOT_SOAP_ROT_BRAIN(text);
    ASSUME_ITS_SOAP_ROT_BRAIN(rot_brain_text);
}

FOSSIL_TEST(c_test_driven_development_test_soap_tone_detection) {
    // Arrange
    const char *formal_text = "Dear Sir or Madam, I hope this message finds you well.";
    const char *casual_text = "Hey, what's up?";
    const char *sarcastic_text = "Oh, great, another meeting. Just what I needed.";
    const char *incorrect_tone_text = "This is a neutral statement.";

    // Act & Assert
    ASSUME_ITS_SOAP_TONE_DETECTED(formal_text, "formal");
    ASSUME_ITS_SOAP_TONE_DETECTED(casual_text, "casual");
    ASSUME_ITS_SOAP_TONE_DETECTED(sarcastic_text, "sarcastic");
    ASSUME_NOT_SOAP_TONE_DETECTED(incorrect_tone_text, "sarcastic");
}

FOSSIL_TEST(c_test_driven_development_test_cstr_equality) {
    // Arrange
    const char *actual = "hello";
    const char *expected = "hello";
    const char *not_expected = "world";

    // Act & Assert
    ASSUME_ITS_EQUAL_CSTR(actual, expected);
    ASSUME_NOT_EQUAL_CSTR(actual, not_expected);
}

FOSSIL_TEST(c_test_driven_development_test_cstr_length) {
    // Arrange
    const char *text = "hello";

    // Act & Assert
    ASSUME_ITS_LENGTH_EQUAL_CSTR(text, 5);
    ASSUME_NOT_LENGTH_EQUAL_CSTR(text, 10);
}

FOSSIL_TEST(c_test_driven_development_test_cstr_prefix_suffix) {
    // Arrange
    const char *text = "hello world";

    // Act & Assert
    ASSUME_ITS_CSTR_STARTS_WITH(text, "hello");
    ASSUME_NOT_CSTR_STARTS_WITH(text, "world");
    ASSUME_ITS_CSTR_ENDS_WITH(text, "world");
    ASSUME_NOT_CSTR_ENDS_WITH(text, "hello");
}

FOSSIL_TEST(c_test_driven_development_test_cstr_contains) {
    // Arrange
    const char *text = "hello world";

    // Act & Assert
    ASSUME_ITS_CSTR_CONTAINS(text, "world");
    ASSUME_NOT_CSTR_CONTAINS(text, "pizza");
}

FOSSIL_TEST(c_test_driven_development_test_cstr_count) {
    // Arrange
    const char *text = "hello hello world";

    // Act & Assert
    ASSUME_ITS_CSTR_COUNT(text, "hello", 2);
    ASSUME_NOT_CSTR_COUNT(text, "hello", 3);
}

FOSSIL_TEST(c_test_driven_development_test_pointer_nullability) {
    // Arrange
    void *null_ptr = null;
    void *non_null_ptr = (void *)0x1;

    // Act & Assert
    ASSUME_ITS_CNULL(null_ptr);
    ASSUME_NOT_CNULL(non_null_ptr);
    ASSUME_ITS_CNULLABLE(null_ptr);
    ASSUME_NOT_CNULLABLE(non_null_ptr);
    ASSUME_ITS_CNONNULL(non_null_ptr);
    ASSUME_NOT_CNONNULL(null_ptr);
}

FOSSIL_TEST(c_test_driven_development_test_likely_unlikely_conditions) {
    // Arrange
    int likely_condition = 1;
    int unlikely_condition = 0;

    // Act & Assert
    ASSUME_ITS_LIKELY(likely_condition);
    ASSUME_NOT_LIKELY(unlikely_condition);
    ASSUME_ITS_UNLIKELY(likely_condition);
    ASSUME_NOT_UNLIKELY(unlikely_condition);
}

FOSSIL_TEST(c_test_driven_development_test_pointer_equality) {
    // Arrange
    void *ptr1 = (void *)0x1;
    void *ptr2 = (void *)0x1;
    void *ptr3 = (void *)0x2;

    // Act & Assert
    ASSUME_ITS_EQUAL_PTR(ptr1, ptr2);
    ASSUME_NOT_EQUAL_PTR(ptr1, ptr3);
}

FOSSIL_TEST(c_test_driven_development_test_size_comparisons) {
    // Arrange
    size_t size1 = 10;
    size_t size2 = 20;

    // Act & Assert
    ASSUME_ITS_EQUAL_SIZE(size1, 10);
    ASSUME_ITS_LESS_THAN_SIZE(size1, size2);
    ASSUME_ITS_MORE_THAN_SIZE(size2, size1);
    ASSUME_ITS_LESS_OR_EQUAL_SIZE(size1, 10);
    ASSUME_ITS_LESS_OR_EQUAL_SIZE(size1, size2);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_test_driven_development_tests) {
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_simple_math);
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_unsigned_math);
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_signed_math);
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_soap_rot_brain);
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_soap_tone_detection);
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_cstr_equality);
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_cstr_length);
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_cstr_prefix_suffix);
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_cstr_contains);
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_cstr_count);
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_pointer_nullability);
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_likely_unlikely_conditions);
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_pointer_equality);
    FOSSIL_TEST_ADD(c_test_driven_development_suite, c_test_driven_development_test_size_comparisons);

    FOSSIL_TEST_REGISTER(c_test_driven_development_suite);
}
