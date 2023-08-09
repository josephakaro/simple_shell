# SIMPLE SHELL GROUP PROJECT
> [!WARNING]
> **NEVER** copy any code, never look at solution (and never give any solution to your friends, you are not helping them by doing so)
> **ALWAYS** write code alone from scratch after you get help to check that you have actually understood. If you can not do it, you have not understood enough, and need to study more. Do not rewrite code from memory, but from understanding.

## CONTEXT ON THE PROJECT


### How does shell work?
A shell is a crucial tool for efficiently navigating the command line of an operating system. It provides users with an intuitive interface, allowing them to effortlessly run programs, manage files, and maintain full control over various aspects of the operating system.

Shells are a vital component of operating systems. They **read**, **interpret**, and **execute** user commands efficiently. Additionally, shells facilitate seamless interaction between users and the operating system by handling **error messages** and **input prompts**.

Here are the steps involved in how a shell works:
```txt
1. The shell reads a command from the user.

2. The shell interprets the command. This involves breaking the command down into its individual components, such as the command name, arguments, and options.

3. The shell executes the command. This may involve:
   - Forking a child process and executing the command in the child process.
   - Executing a built-in command.
   - Searching for the command in the PATH environment variable and executing it.

4. The shell waits for the child process to finish.

5. If the command fails, the shell prints an error message.

6. The shell repeats steps 1-5 until the user quits the shell.
```

Here is a diagram of how a shell works:
```txt
  User
      |
      |----> Shell
      |
      |----> Operating System
```

The shell is a user-friendly interface where users can enter commands to interact with the operating system. It interprets and executes these commands, retrieving the results from the operating system and displaying them back to the user. This streamlined process makes it easy for users to navigate and control their systems efficiently.

Shells play a crucial role in every operating system. They empower users to efficiently interact with the system and accomplish various tasks with ease.
