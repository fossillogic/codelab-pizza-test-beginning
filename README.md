# Codelab: Pizza Test Humble Beginnings
Welcome to the Humble Beginnings series, where we explore the power and flexibility of **Pizza Test**, a comprehensive and easy-to-use testing framework for C and C++. This series highlights the core capabilities of Pizza Test, guiding you through essential test styles and use cases. From writing your very first unit test to mastering advanced concepts, these codelabs will help you unlock the full potential of this library. Whether you're a beginner or an experienced developer, Pizza Test provides the tools you need to create reliable, maintainable, and expressive tests that seamlessly integrate into your development workflow.

| Page No. | Page Title                  | Description                                          |
| -------- | --------------------------- | ---------------------------------------------------- |
| 1        | Hello Pizza!                | Introduction and writing your first simple unit test |
| 2        | Test-Driven Development     | Writing tests first and driving development          |
| 3        | Behavior Driven Development | Writing expressive BDD-style tests                   |
| 4        | Domain Driven Design        | Testing with domain concepts and fixtures            |
| 5        | Beyond Basics               | Using assertions and assumptions for validation      |
| 6        | Mocking and Stubbing        | Simulating dependencies for isolated testing         |
| 7        | Parameterized Tests         | Writing tests that run with multiple input sets      |
| 8        | Performance Testing         | Measuring and validating performance characteristics |
| 9        | Regression Testing          | Ensuring changes don't break existing functionality  |
| 10       | Integration Testing         | Testing interactions between multiple components     |

For viewing samples, be sure to look in the `code/pages` directory.

## Prerequisites

Before you begin, ensure you have the following installed:

- **Meson Build System**: This project uses Meson for building. Visit the [official Meson website](https://mesonbuild.com/) for installation instructions.

## Setting Up Meson Build

1. **Install Meson**:  
    Follow the installation guide on the [Meson website](https://mesonbuild.com/Getting-meson.html) for your operating system.

## Setting Up, Compiling, Installing, and Running the Project

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/fossillogic/codelab-pizza-test-beginning.git
    cd codelab-pizza-test-beginning
    ```

2. **Configure the Build**:
    ```bash
    meson setup builddir
    ```

3. **Compile the Project**:
    ```bash
    meson compile -C builddir
    ```

4. **Run the Project**:
    ```bash
    ./<executable-name>
    ```

## Contributing

We welcome contributions! Feel free to open pull requests or create issues on the [GitHub repository](https://github.com/fossillogic/codelab-pizza-test-beginning).

## Feedback and Support

Have questions, feedback, or encountered an issue? Please open an issue on the [GitHub repository](https://github.com/fossillogic/codelab-pizza-test-beginning/issues).

## License

This project is licensed under the **Mozilla Public License**. See the `LICENSE` file for more details.