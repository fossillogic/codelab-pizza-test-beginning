import os
import argparse

def generate_file(directory, language, subject, number):
    if language not in ['c', 'cpp']:
        print("Error: Language must be 'c' or 'cpp'.")
        return

    if not os.path.exists(directory):
        os.makedirs(directory)

    if not subject:
        print("No subject provided. Using default name 'new'.")
        subject = "new"

    # Use the provided number or find the next available number
    if number is None:
        existing_files = [f for f in os.listdir(directory) if f.startswith(f"page-{subject}-") and f.endswith(f".{language}")]
        numbers = [int(f.split('-')[-1].split('.')[0]) for f in existing_files if f.split('-')[-1].split('.')[0].isdigit()]
        number = max(numbers, default=0) + 1

    # Format the file name
    file_name = f"page-{subject}-{number:02d}.{language}"
    file_path = os.path.join(directory, file_name)

    # Define the content template
    content = f"""/*
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
FOSSIL_SUITE({language}_{subject}_suite);

// Setup function for the test suite
FOSSIL_SETUP({language}_{subject}_suite) {{}}

// Teardown function for the test suite
FOSSIL_TEARDOWN({language}_{subject}_suite) {{}}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// Simple test case for 2 + 2
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST({language}_{subject}_test_simple_math) {{
    int result = 2 + 2;
    ASSUME_ITS_EQUAL_I32(4, result);
}}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Codelab Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP({language}_{subject}_tests) {{
    FOSSIL_TEST_ADD({language}_{subject}_suite, {language}_{subject}_test_simple_math);

    FOSSIL_TEST_REGISTER({language}_{subject}_suite);
}}
"""

    # Create the file
    with open(file_path, 'w') as file:
        file.write(content)

    print(f"File generated: {file_path}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate a test file for the Codelab project.")
    parser.add_argument("directory", help="The directory where the file will be created.")
    parser.add_argument("language", choices=['c', 'cpp'], help="The programming language ('c' or 'cpp').")
    parser.add_argument("subject", help="The subject of the test file.")
    parser.add_argument("--number", type=int, default=None, help="The specific number for the file (optional).")

    args = parser.parse_args()
    generate_file(args.directory, args.language, args.subject, args.number)
