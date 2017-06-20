# Big Integer Library

Big Integer library written in C++ to perform basic arithmetic operations

### Prerequisites

* g++ version 4.8.4 or higher
* Boost version 1.63.0 or higher
* python 2.7.6 or higher

### Installing

First compile the project in your local system by:

```
make clean
make
```
For testing if it works, see Running tests below

## Running Tests

For automated tests, run:

``` 
python tester.py
```
It generates random numbers and tests if the basic operations are performed correctly

For manual tests, run:

``` 
./test -a #For addition
./test -s #For subtraction
./test -m #For multiplication
./test -d #For division
./test -e #For exponentiation
```

## Deployment

For using the Intal library:

* Copy libintal.a file to the location of your source file.
* Include Intal.h to your source file.
* To compile your program (say main.cpp):
 
```
g++ -static main.cpp -L. -lintal -o main
```

## Built With

* [C++](http://www.cplusplus.com/) - The main backend used
* [Boost](http://www.boost.org/) - For faster multiplication
* [Python](https://docs.python.org/2/) - Used for testing

## Authors

* **Ganesh K.** - [DarkFate13](https://github.com/DarkFate13)

## Acknowledgments

This is developed as an assignment for Design and Analysis of Algorithms Course
