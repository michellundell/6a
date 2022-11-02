# michellundell/6a C++

## Agenda
1. Status of C version of the Ticket system
2. C++ bare-bone example
3. C++ namespace
4. C++ input/output
5. C++ Class example
6. C++ Class Access



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

iostream.h is deprecated and not a standard header. It was used in older programs before C++ was standardized, Functions like cout were defined inside iostream.h. 

After C++ got standardized, all these functions like cout got moved into the std namespace.To adjust to this change, non .h versions of some of these headers were introduced and declared as standard headers. This means that iostream is a standard header whose every function is in the std namespace.



## 3. C++ namespace
## 4. C++ input/output
## 5. C++ Class example
## 6. C++ Class Access
```
```
