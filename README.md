# Simple Shell

A shell is a user interface for access to an unix based operative system. This is a simple version of bash written in C Language requested by Holberton School. This project contains several features and prototype functions made by us.

## List of system calls and functions used
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* strtok (man 3 strtok)
* wait (man 2 wait

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. 

### Prerequisites

A Unix-like operating system or by default a virtual machine. You should have git installed.
[picture unix-like]

### Installing

- If you don't have a Unix-like operative system you can use a virtual machine that you find is this link: https://www.virtualbox.org/
- Clone this repo to your local machine using in your terminal`git clone https://github.com/SebastianCalle/simple_shell.git`
- The shell will be compiled this way: ```gcc -Wall -Werror -Wextra -pedantic *.c -o hsh```

### Usage

- You can run the shell in two ways:

mode interactive
```shell
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
mode non-interactive
```shell
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
- You can use basic command lines: 

```shell
$ ls
$ rm
$ cp
$ rm
And more...
```

- These are the commands and functions developed by us

* strtok
* getline 
* env
* setenv
* unsetenv
* rm

## Authors

* **Hugo Vargas** - *Initial work* - [Github](https://github.com/vargas88hugo)
* **Juan Sebastian Montealegre** - *Initial work* - [Github](https://github.com/SebastianCalle)

## License

This project is licensed under Educational Community License v2.0 - see the [LICENSE](https://opensource.org/licenses/ECL-2.0) file for details
