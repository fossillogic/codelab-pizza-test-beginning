# Codelab by Fossil Logic

Welcome to the Codelab project template by Fossil Logic! This template is designed to help you kickstart your journey in creating classic executable projects. Whether you're sharing applications via GitHub or exploring sample implementations, this template provides all the necessary setup, compilation, installation, and execution instructions to get you started quickly.

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
    git clone https://github.com/fossillogic/codelab-base.git
    cd codelab-base
    ```

2. **Configure the Build**:
    ```bash
    meson setup builddir
    ```

3. **Compile the Project**:
    ```bash
    meson compile -C builddir
    ```

5. **Run the Project**:
    ```bash
    ./<executable-name>
    ```

## Contributing

We welcome contributions! Feel free to open pull requests or create issues on the [GitHub repository](https://github.com/fossillogic/codelab-base).

## Feedback and Support

Have questions, feedback, or encountered an issue? Please open an issue on the [GitHub repository](https://github.com/fossillogic/codelab-base).

## License

This project is licensed under the **Mozilla Public License**. See the `LICENSE` file for more details.