# how to use header and source file in C

## example 1
In the directory `withHeader`, we create a header file `lib.h` and 
link main.cpp and lib.cpp together. `lib.h` doesn't have to 
appear in the command.

## example 2
In the directory `withourHeader`, it is the same as example 3.

## example 3
“-c” here means “preprocessing + compilation, no linking”. In the directory `withoutHeader2`, "-c" must exist here
because g++ does the linking by default. For `main.cpp`, there is no function `add` before linking, so there is an error
without `-c`. For `lib.cpp`, there is no main function, so an error happens without `-c`.