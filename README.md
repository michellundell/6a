# michellundell/6a C++

## Agenda
1. Status of C version of the Ticket system
2. C++ bare-bone example
3. C++ namespace
4. C++ comments
5. C++ input/output
6. C++ Class example
7. C++ Class Access
8. C++ files ...
9. C++ Writing a text file
10. C++ Reading a text file


## 1. Status of C version of the Ticket system
### What is the status of your ticket software?

1. Have you created a pseudo code of what the software should do?
2. Does it read the files (flights.csv, booking.csv) provided by the arguments into your program?
3. Is the information about the flights and bookings stored in a data structure?
4. Does the software match each booking with a flight?
5. Does the software allocate seats on the flight?
6. Does the software print a ticket for each booking?

After todays C++ introduction, I want to review/help those out with troubles of
the C version of the ticket system.

Lets start with some light C++ stuff!

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

In C++ it is common practice to use the operators >> and << for input and output.

These operators can be overloaded for objects which leaves the output and input from and to streams up to the 
implementation of the class object itself.

### Output

Use the << operator for output like this:

```
#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	cout << "My text is printed to standard output now!" << endl;
        return 0;
}
```

### Input
```
#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
        cout << "Give a number!" << endl;
        int x = 0;
        cin >> x;
        cout << "Thank you, your number is " << x << endl;
        return 0;
}
```

## 6. C++ Class example
```
#include <iostream>
using namespace std;

class myClass {
        public:
            char name[25];
            int age;

            void showInfo()
            {
                cout << "Hi my name is " << this->name << " and Im " << this->age << " old." << endl;
            }

};

int main(int argc,char **argv)
{
        myClass me;

        cout << "What is my name?" << endl;
        cin >> me.name;
        cout << "What is my age?" << endl;
        cin >> me.age;

        me.showInfo();

        return 0;
}
```
**Note** The class myClass is almost like a struct, except it has a keyword **public** and defines a function **showInfo()**inside it.

**Note** The class myClass does not need to be named by a **typedef**, this is automatically.


## 7. C++ Class Access

As you may have noted, the variables in the class was accessible outside the class, just like a struct.

It is common practice to "hide" the variables in a class from access outside the class. This is done by
declaring them as **private**.

Variables not declared in the **public** section of a class is by default **private**.

So declaring variables like this
```
class myClass {
            char name[25];
            int age;
        public:
            void showInfo() { cout << "Name:" << this->name << "," << this->age << " years" << endl;
            }
};
```
and in this way ...
```
class myClass {
	private:
            char name[25];
            int age;
        public:
            void showInfo() { cout << "Name:" << this->name << "," << this->age << " years" << endl; }
};
```
would be the same.

Below is an example of code that does not work ...
```
#include <iostream>
using namespace std;

class myClass {
            char name[25];
            int age;
        public:

            void showInfo()
            {
                cout << "Hi my name is " << this->name << " and Im " << this->age << " old." << endl;
            }

};

int main(int argc,char **argv)
{
        myClass me;

        cout << "What is my name?" << endl;
        cin >> me.name;
        cout << "What is my age?" << endl;
        cin >> me.age;

        me.showInfo();

        return 0;
}
```

Compiling this will generate the following errors (on my platform macOS)

```
c++     example.cpp   -o example
example.cpp:21:19: error: 'name' is a private member of 'myClass'
        cin >> me.name; 
                  ^
example.cpp:5:11: note: implicitly declared private here
            char name[25];
                 ^
example.cpp:23:19: error: 'age' is a private member of 'myClass'
        cin >> me.age; 
                  ^
example.cpp:6:10: note: implicitly declared private here
            int age;
                ^
2 errors generated.
make: *** [example] Error 1
```

## 8. C++ files ...

In order to open a file with a stream object we use its member function open:

**open (filename, mode);**

Where filename is a string representing the name of the file to be opened, and mode is an optional parameter with a combination of the following flags:
```
ios::in	        Open for input operations.
ios::out	Open for output operations.
ios::binary	Open in binary mode.
ios::ate	Set the initial position at the end of the file.
                If this flag is not set, the initial position is the beginning of the file.
ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.
ios::trunc	If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
```

All these flags can be combined using the bitwise operator OR (|). For example, if we want to open the file example.bin in binary mode to add data we could do it by the following call to member function open:

```
ofstream myfile;
myfile.open ("example.bin", ios::out | ios::app | ios::binary);
```

Each of the open member functions of classes ofstream, ifstream and fstream has a default mode that is used if the file is opened without a second argument:

```
class	        default mode parameter
-----           ......................
ofstream	ios::out
ifstream	ios::in
fstream	        ios::in | ios::out
```


## 9. C++ Writing a text file
```
#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char **argv) 
{
  ofstream myfile("example.txt");
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  } else cerr << "Unable to open file" << endl;
  return 0;
}
```

## 10. C++ Reading a text file
```
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char **argv) 
{
  string line;
  ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  } else cerr << "Unable to open file" << endl; 

  return 0;
}
```



## Todays assignment

1. If the variables in the myClass is not public, how can they be set if they are only accessible from the class itself?
   Find the solution, correct it and make a pull-request so I can run my program!

   The file is called myClass.cpp and is found in the michellundell/6a repo.

2. If you are finished with the ticket program in C, start making a C++ version of it! (you could start by copying ticket.c to ticket.cpp).

Think about how the data and functions could be grouped together, maybe as a class?

I myself would probably think like this:

hmm I need something that holds the information about the flights ... maybe a class called FlightManager?

Which methods should the FlightManager have ... hmm 
```
class FlightManager {
	public:
	    bool initFromFile(const char *filename)
	    Flight *getFirst();
	    Flight *getNext();
	    bool hasMore(); // bool is a type that can be true or false
}
```

### Hints
- I see I need something that holds the information about one flight ... perhaps a class called Flight?
- Maybe I need something that holds the information about all the bookings and each booking?
- Maybe I need some reports?

and so on ....


