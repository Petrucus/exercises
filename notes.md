
# Pointers to void

A pointer of type void * represents the address of an object, but not its type.

For example, a memory allocation function void *malloc( size_t size ); returns a pointer to void which can be casted to any data type.

example:

`int *ptr = (int*)malloc(n * sizeof(int));`

Why we use the (int*) casting in this context:
malloc returns a void*: The malloc function in C returns a pointer of type void*. 
This is a generic pointer that can point to any data type.
In C, we typically want to work with pointers of specific types.
In this case, we're allocating memory for an array of integers, so we want an int* pointer.
Explicit conversion: The cast (int*) explicitly converts the void* returned by malloc to an int*.
This tells the compiler that we intend to use this memory to store integers.

Avoiding warnings: In older versions of C (before C99), this cast was necessary to avoid compiler warnings about assigning a void* to an int*.

In modern C, the cast is not strictly necessary, as the conversion from void* to any other pointer type is implicit.

Even in modern C where the cast isn't required, some programmers prefer to include it for clarity, making the intended use of the allocated memory explicit in the code.

It's worth noting that in C++, the cast is mandatory because C++ has stricter type-checking rules than C.


# Lvalue Expressions in C

#### Lvalue Expressions in C
Expressions that refer to a memory location are called "lvalue" expressions.

An "lvalue" may appear as either the left-hand or right-hand side of an assignment.
Variables in C are lvalues and so they may appear on the left-hand side of an assignment.

#### Rvalue Expressions in C

The term "rvalue" refers to a data value that is stored at some address in memory.

An "rvalue" is an expression that cannot have a value assigned to it which means an rvalue may appear on the right-hand side but not on the left-hand side of an assignment.

Numeric literals are rvalues and so they may not be assigned and cannot appear on the left-hand side.


# Integer promotion rules

```
char a = 'z';
int b = (a % 10) - 32;
printf("%d", b); // prints -46 !
```

But ...
```
 int largeNumber = 300;
 char charValue;
 charValue = largeNumber;

printf("\nOriginal large int value: %d\n", largeNumber); // 300
printf("Value after conversion to char: %d\n", charValue); // 44
// is also compiler warning (or error see -Werror !)
```
- Byte and short values − They are promoted to int.
- If one operand is a long − The entire expression is promoted to long.
- If one operand is a float − The entire expression is promoted to float.
- If any of the operands is double − The result is promoted to double.
`In C, the result of an operation is always in the data type with larger byte length`[^1]

# Change the Value of a Constant

The following code demonstrates how to change the value of a constant with the pointer mechanism
```
#include <stdio.h>
int main(){
   const int x = 10;
   printf("Initial Value of Constant: %d\n", x);

   // y is a pointer to constant x
   int* y = &x;
   
   // assign new value
   *y = 100;
   printf("Value of Constant after change: %d", x);
   return 0;
}
```
#### Output

On executing this code, you will get the following output −
```
Initial Value of Constant: 10
Value of Constant after change: 100
```
Note that this technique is effective only for those  **constants**  which are defined using the  **const**  qualifier.

If you have defined your constant using the  **#define**  directive, then you cannot apply this process. This is because the pointer has a data type, and it must be of the same type whose address is to be stored. On the other hand, the constant defined using the  **#define**  directive doesn't really have a data type. It is in fact a macro whose value is substituted during the runtime.



[^1]:In C, the result type of an operation depends on a set of complex rules involving the types of the operands, their integer rank, and whether they are signed or unsigned. While operations often result in a type that can represent a larger range of values, this is not always the case, and the specific rules should be consulted for each situation to understand the exact behavior.