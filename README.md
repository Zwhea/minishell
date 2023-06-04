<h1 align="center">
LE PITIT_SHELL
</h1>

<h4 align="center">
Aussi mignon qu’un vrai shell!
</h4>
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-useful-links">Useful Links</a>
</h3>

---

## About
___
This project is focused on creating a minimalistic shell, which is a program that allows users to interact with their operating system by typing commands. By participating in this project, individuals can learn how to create a functional and efficient shell that performs tasks such as running programs, managing input and output, and handling errors.

____
## Index
___
### Project Objectives

The objectives of the project are:
- Create a program that simulates a shell.
- Handle errors and signals.
- Handle environment variables.
- Handle local variables.
- Handle simple redirections (< and >).
- Handle pipes (|).

### Implemented Features

The implemented features in this project are:
- Handling errors and signals.
- Handling environment variables.
- Handling local variables.
- Handling simple redirections (< and >).
- Handling advanced redirections (<< and >>).
- Handling pipes (|).
- Handling the "echo" command.
- Handling the "cd" command.
- Handling the "env" command.
- Handling the "export" command.
- Handling the "unset" command.
- Handling the "exit" command.

Bonus Part :
- Handling logical operators (&& and ||).
- Handling globbing with * in the current repository.

### Non-Implemented Features

The non-implemented features in this project are:
- Handling the semi-colon command separator ;

### Conclusion

The Minishell project at École 42 was an excellent opportunity to put into practice the programming skills acquired throughout the curriculum. Handling errors and signals, environment variables, local variables, redirections, and pipes was a very enriching experience and helped to better understand how a shell works.

___
## Usage
___
### Instructions

**1. Compiling & Executing the program**

To compile and execute the program, run:

```shell
$ make
$ ./minishell
```
**3. Special Compiling Rules**

To compile the program with fsanitize, run:

```shell
$ make debug
$ ./minishell
```
To compile the program with valgrind, run:

```shell
$ make leaks
```
 or:
 ```shell
$ make leak_all
```

## Useful Links
* [42 Docs - minishell](https://harm-smits.github.io/42docs/projects/minishell)
* [Useful notes on Shell & Shell Scripting](https://www.notion.so/Shell-Shell-Scripting-6e0f0290a0304dad93a1d25ba15d92fe)
* [Bash Guide for Beginners](https://tldp.org/LDP/Bash-Beginners-Guide/html/index.html)
* [The Open Group Base Specifications - Shell Command Language](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)
* [Introduction to Systems Programming: a Hands-on Approach - Chapter 5. Writing Your Own Shell ](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)

by [bpoumeau](https://profile.intra.42.fr/users/bpoumeau) & [twang](https://profile.intra.42.fr/users/twang).
