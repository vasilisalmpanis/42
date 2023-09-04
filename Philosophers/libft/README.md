# Minishell

Minishell is a powerful and elegant shell created as a collaborative effort by our team, [@mamesser](https://github.com/memaar92) and [@me](https://github.com/vasilisalmpanis),
combining our skills to craft a feature-rich command-line interface. In this school project, we've taken on the challenge of developing a fully functional shell from scratch, 
incorporating various system calls and features to create a versatile and efficient tool.
This readme serves as a guide to understand what our Minishell can do and the valuable takeaways from our teamwork.

![Minishell](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExN2p1bDU3aGQxMG0ydDNhZTZpNjcxanhrZDI2ZTd5NmsyY3ZqMnhzMyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/kUQ4qEo3EQjEOkWxxa/giphy.gif)

## Installation

Follow these steps to set up and run Minishell on your system:

1. **Clone the Repository**: Start by cloning this repository to your local machine using the following command:

    ```sh
    git clone https://github.com/yourname/minishell.git
    ```

2. **Navigate to the Directory**: Move into the cloned repository's directory:

    ```sh
    cd minishell
    ```

3. **Compile the Code**: Ensure you have `make` and `gcc` installed on your system. If not, you can install them using the package manager for your operating system. Once you have them, run the following command to compile Minishell:

    ```sh
    make
    ```

4. **Launch the Executable**: After successful compilation, you can launch Minishell by running:

    ```sh
    ./minishell
    ```

## Features

Our Minishell boasts a range of features that make it a reliable and user-friendly shell:

- **Interactive Prompt**: Minishell provides a user-friendly prompt that welcomes input from the user.

- **Command History**: The shell incorporates a history feature, allowing users to easily navigate and reuse previous commands.

- **Executable Search**: Minishell can locate and execute the appropriate executable based on the PATH variable or provided relative/absolute paths.

- **Signal Handling**: We've meticulously designed our signal handling, ensuring that only one global variable is used to indicate received signals. This maintains the integrity of our main data structures.

- **Quoting**: Minishell handles single quotes ('), preventing the interpretation of metacharacters within the quoted sequence. Double quotes (") are also managed, except for the dollar sign ($).

- **Redirections**: The shell supports various redirections:
    - `<` redirects input.
    - `>` redirects output.
    - `<<` reads input until a specified delimiter, without updating history.
    - `>>` redirects output in append mode.

- **Pipes**: Our shell implements pipes (`|`), facilitating the seamless flow of output from one command to the input of the next.

- **Environment Variables**: Minishell handles environment variables ($ followed by characters), expanding them to their corresponding values.

- **Exit Status**: We've incorporated the ability to use `$?` to expand to the exit status of the most recently executed foreground pipeline.

- **Ctrl-C, Ctrl-D, Ctrl-\ Handling**: The shell behaves like bash with respect to these keyboard shortcuts:
    - Ctrl-C: Displays a new prompt on a new line.
    - Ctrl-D: Exits the shell.
    - Ctrl-\: No action taken.

- **Built-in Commands**: Minishell supports the following built-in commands:
    - `echo` with the `-n` option
    - `cd` with relative or absolute paths
    - `pwd` with no options
    - `export` with no options
    - `unset` with no options
    - `env` with no options or arguments
    - `exit` with no options

## Collaboration and Takeaways

Collaborating on Minishell has been an enriching experience for our team. By working together, we've not only honed our programming skills but also gained insights into various aspects of software development:

- **Teamwork**: Developing a complex project like Minishell required seamless collaboration, effective communication, and code integration. Our team successfully navigated these challenges, reinforcing the importance of teamwork in software development.

- **System Calls and Functions**: The project exposed us to a wide range of system calls and functions. We delved into concepts like signal handling, process management, file manipulation, memory allocation, and more, enhancing our understanding of low-level programming.

- **Problem Solving**: Overcoming challenges in implementing various features sharpened our problem-solving skills. From handling quotes to managing redirections, we devised creative solutions that combined theoretical knowledge with practical application.

- **Code Structure and Design**: Crafting a well-organized and modular codebase was crucial for Minishell's maintainability and readability. We learned to design code with clarity and reusability in mind.

- **Debugging and Testing**: Minishell's development phase exposed us to the intricacies of debugging and testing. We became adept at identifying and rectifying issues, ensuring that our shell functions smoothly.

- **Documentation**: The creation of this readme itself is a testament to the significance of documentation. We learned to articulate complex concepts clearly, making our work accessible to others.

---

*Minishell - As beautiful as a shell*
