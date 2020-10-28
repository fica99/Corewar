# Libftprintf

My implementation of some of the Standard C Library functions including some additional ones.

## What is **libft**?

**Libft** is an individual project at school 42 that requires us to re-create some standard C library functions including some additional ones that can be used later to build a library of useful functions for the rest of the program.

Disclaimer: Reinventing the wheel is bad, 42 makes us do this just so we can have a deeper understanding of data structures and basic algorithms. At 42 we're not allowed to use some standard libraries on our projects, so we have to keep growing this library with our own functions as we go farther in the program.

Notes: Most of the the files and function names are namespaced with an ft in front. It stands for Fourty Two

## What is **ft_printf**?
The **ft_printf** tis my own implementation of a well-known function **printf**.
The **printf** function is a standard output function. Using this function, you can display a character string, number, variable value ...

## How does it work?

The goal is to create a library called libftprintf.a from the source files so I can later use that library from other projects at 42.

To create that library, after downloading/cloning this project, cd into the project and call `make`:

```
git clone https://github.com/fica99/libftprintf
cd libftprintf
make
```

You should see a *libftprintf.a* file and some object files (.o) in *obj* folder.

Now to clean up (removing the .o files (*obj* folder)), call `make clean`

## How do I use the library?

The library includes **ft_printf** and **libft**.
You have to tell the file where your library resides and which library it is using:
```
gcc example.c -I libftprintf/includes -L . -lftprintf
```
`-L` takes the path to your library. `.` in this case

`-l` takes the name of your library. This is the set of characters that come after *lib* in your library name.
