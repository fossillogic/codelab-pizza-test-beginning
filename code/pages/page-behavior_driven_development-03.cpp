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
FOSSIL_SUITE(cpp_behavior_driven_development_suite);

// Setup function for the test suite
FOSSIL_SETUP(cpp_behavior_driven_development_suite) {}

// Teardown function for the test suite
FOSSIL_TEARDOWN(cpp_behavior_driven_development_suite) {}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// Simple test case for 2 + 2
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(cpp_behavior_driven_development_test_simple_math) {
    GIVEN("two integers 2 and 2") {
        int a = 2;
        int b = 2;

        WHEN("they are added together") {
            int result = a + b;

            THEN("the result should be 4") {
                ASSUME_ITS_EQUAL_I32(4, result);
            }
        }
    }
}

FOSSIL_TEST(cpp_behavior_driven_development_test_unsigned_math) {
    GIVEN("two unsigned integers 10 and 5") {
        uint32_t actual = 10;
        uint32_t expected = 5;

        WHEN("comparing their values") {
            THEN("they should not be equal") {
                ASSUME_NOT_EQUAL_U32(actual, expected);
            }
            THEN("the first should not be less than the second") {
                ASSUME_NOT_LESS_THAN_U32(actual, expected);
            }
            THEN("the second should not be more than the first") {
                ASSUME_NOT_MORE_THAN_U32(expected, actual);
            }
            THEN("the first should not be less or equal to the second") {
                ASSUME_NOT_LESS_OR_EQUAL_U32(actual, expected);
            }
            THEN("the second should not be more or equal to the first") {
                ASSUME_NOT_MORE_OR_EQUAL_U32(expected, actual);
            }
        }
    }
}

FOSSIL_TEST(cpp_behavior_driven_development_test_signed_math) {
    GIVEN("two signed integers -10 and -5") {
        int32_t actual = -10;
        int32_t expected = -5;

        WHEN("comparing their values") {
            THEN("they should not be equal") {
                ASSUME_NOT_EQUAL_I32(actual, expected);
            }
            THEN("the second should not be less than the first") {
                ASSUME_NOT_LESS_THAN_I32(expected, actual);
            }
            THEN("the first should not be more than the second") {
                ASSUME_NOT_MORE_THAN_I32(actual, expected);
            }
            THEN("the second should not be less or equal to the first") {
                ASSUME_NOT_LESS_OR_EQUAL_I32(expected, actual);
            }
            THEN("the first should not be more or equal to the second") {
                ASSUME_NOT_MORE_OR_EQUAL_I32(actual, expected);
            }
        }
    }
}

FOSSIL_TEST(cpp_behavior_driven_development_test_soap_rot_brain) {
    GIVEN("a clean and clear sentence") {
        const char *text = "This is a clean and clear sentence.";

        WHEN("checking for soap rot brain") {
            THEN("it should not be detected") {
                ASSUME_NOT_SOAP_ROT_BRAIN(text);
            }
        }
    }

    GIVEN("a sentence with rizz language") {
        const char *rot_brain_text = "This sentence contains rizz language.";

        WHEN("checking for soap rot brain") {
            THEN("it should be detected") {
                ASSUME_ITS_SOAP_ROT_BRAIN(rot_brain_text);
            }
        }
    }
}

FOSSIL_TEST(cpp_behavior_driven_development_test_soap_tone_detection) {
    GIVEN("a formal text") {
        const char *formal_text = "Dear Sir or Madam, I hope this message finds you well.";

        WHEN("detecting its tone") {
            THEN("it should be formal") {
                ASSUME_ITS_SOAP_TONE_DETECTED(formal_text, "formal");
            }
        }
    }

    GIVEN("a casual text") {
        const char *casual_text = "Hey, what's up?";

        WHEN("detecting its tone") {
            THEN("it should be casual") {
                ASSUME_ITS_SOAP_TONE_DETECTED(casual_text, "casual");
            }
        }
    }

    GIVEN("a sarcastic text") {
        const char *sarcasticpp_text = "Oh, great, another meeting. Just what I needed.";

        WHEN("detecting its tone") {
            THEN("it should be sarcastic") {
                ASSUME_ITS_SOAP_TONE_DETECTED(sarcasticpp_text, "sarcastic");
            }
        }
    }

    GIVEN("a neutral text") {
        const char *incorrect_tone_text = "This is a neutral statement.";

        WHEN("detecting its tone") {
            THEN("it should not be sarcastic") {
                ASSUME_NOT_SOAP_TONE_DETECTED(incorrect_tone_text, "sarcastic");
            }
        }
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(cpp_behavior_driven_development_tests) {
    FOSSIL_TEST_ADD(cpp_behavior_driven_development_suite, cpp_behavior_driven_development_test_simple_math);
    FOSSIL_TEST_ADD(cpp_behavior_driven_development_suite, cpp_behavior_driven_development_test_unsigned_math);
    FOSSIL_TEST_ADD(cpp_behavior_driven_development_suite, cpp_behavior_driven_development_test_signed_math);
    FOSSIL_TEST_ADD(cpp_behavior_driven_development_suite, cpp_behavior_driven_development_test_soap_rot_brain);
    FOSSIL_TEST_ADD(cpp_behavior_driven_development_suite, cpp_behavior_driven_development_test_soap_tone_detection);

    FOSSIL_TEST_REGISTER(cpp_behavior_driven_development_suite);
}
