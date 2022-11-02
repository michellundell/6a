# michellundell/6a C++

## Agenda
1. Status of C version of the Ticket system
2. C++ bare-bone example
3. C++ namespace
4. C++ comments
5. C++ input/output
6. C++ Class example
7. C++ Class Access


## 1. Status of C version of the Ticket system
### What is the status of your ticket software?

1. Have you created a pseudo code of what the software should do?
2. Is it reading the files (flights.csv, booking.csv) provided by the arguments to your program?
3. Is the information about the flights and bookings stored in a data structure?
4. Does the software match each booking with a flight?
5. Does the software allocate seats on the flight?
6. Does the software print a ticket for each booking?

After some C++ introduction, I want to review/help those out with troubles of
the C version of the ticket system.

## 2. C++ bare-bone example

### Minimal C++ program
```
int main(int argc,char **argv)
{ 
	return 0;
}
```
C is a subset of C++, any C program can be compiled with a C++ compiler.

C++ is a superset of C. It requires a C++ compiler.

### Hello in C++
```
#include <iostream>

int main(int argc,char **argv)
{ 
	std::cout << "Hello!" << std::endl;
	return 0;
}
```
1. To use the C++ input/output instead of C stdout and stdin, change the include from 
```
#include <stdio.h>
```
to

```
#include <iostream>
```
Why not using iostream.h?

iostream.h is deprecated and not a standard header. It was used in older programs before C++ was standardized, Functions like cout were defined inside iostream.h. 

After C++ got standardized, all these functions like cout got moved into the std namespace.To adjust to this change, non .h versions of some of these headers were introduced and declared as standard headers. This means that iostream is a standard header whose every function is in the std namespace.

What is std::cout and std::endl mean?

The std::cout means that the character output "cout" is defined in the namespace "std". 
The std::endl means a end of line.

A namespace can define any variables, classes, functions etc. 

## 3. C++ namespace

Different namespaces can define the same variables, classes, functions etc. 

Using the syntax namespacename::name it is possible to specify which one the software uses.

```
#include <iostream>

namespace my_namespace {
    void doit() { std::cout << "my_namespace doit()" << std::endl;
}

namespace other_namespace {
    void doit() { std::cout << "other_namespace doit()" << std::endl;
}

int main(int argc,char **argv)
{ 
	my_namespace::doit();
	other_namespace::doit();
}

```

To not having to type namespace::name all the time, there is a way to tell the compiler which 
namespace that is used in a context.

```
#include <iostream>
using namespace std;

int main(int argc,char **argv)
{ 
    cout << "using standard namespace" << endl;
    return 0
}

```

## 4. C++ comments

In C++ the notation of a single line comment is done by two forward slashes like

```
// This is a single line comment
// This is another single line comment

```

In C++ the notation of a multiple line comment is done like in C 

```
// This is a single line comment
// This is another single line comment
/* 
This is a
multiple line
comment.
*/
/* I can also be used on a single line */

```

## 5. C++ input/output
## 6. C++ Class example
## 7. C++ Class Access
```
```
