## Chapter 2
### Basic Syntax
- A statement is a unit of code terminated by a semi-colon
    - call functions
    - declare uninitialized variables
    - operate on expressions
- A function is a larger unit of code
    - many statements

```
int main (int argc, char *argv[])
{
    puts("Hello world!");
    return 0;
}
```
Above code, `argc` is the number of arguments. `argv` is the an array of character array. It also be denoted as `char **argv`

An expression is anything that returns a value

Identifiers: Latin alphabet; numerics; underscore

Qualifiers (modifiers), they change the behavior of the varibles in various ways:

- **const**: can't change after defined
- double ampersand(&&)

### Pointers
```
int x;
x = 1;
int y = x;

int * ip; // this is an integer pointer to an integer value
ip = &x; // ampersand operator here is called refrence operator. The address of operator
y = *ip; // this statements copies the value pointed to by ip into y. this asterisk is called pointer dereference operator
```

### References
- No need to use dereference (* asterisk). The value of a reference is always the referred value
- There is no syntax for changing the reference. Once it is defined, it can't be changed
- Recommend that reference has const as a modifier

### Primitive array

```
int ia[5]; <-> int * ip = ia; // initialize an integer array, the pointer is pointing to the first element of the array
*ip = 2;
ia[0] = 1; <-> *ia = 1;

++ip; // move the pointer to the address of the next element. pointer knows the size of the element, this increment will be sure to point to the next element
*ip = 3; // this will assign the value to the second element

*(++ip) = 4; // assign the value to the third element
```

### Primitives string
```
char s[] = "string"; <-> char s[] = {'s','t','r','i','n','g',0};
```

### Range for loop
```
for (int x: arrayInput){
    printf("%d\n", x);
}
```

### cout
- cout is an STL class. STL is the standard template library. Introduce STL, which requires CPU and space. And it might introduce more errors
- One advantage is that cout doesn't care about the data type

## Chapter 3
### Data types

### Characters and strings
```
char cstring[] = "String"; // it copies literal string to the array
const char * cstring = "String"; // makes the pointer to point to the type of the pointer. This is not a constant pointer. It is not copying the the literal string to an array
```

### Character escape
- backslash `\`

### Qualifier
`const static int- i = 42; // const and static are qualifiers`

- Constant and Volatile qualifiers (CV Qualifiers)
    - `const`
    - `mutable`
    - `voltile`; is deprecated
- Storage Duration
    - `static`: if a variable is declared as static, there is a static memory to for that variable
    - `register`
    - `extern`

### References
Common usage
```
int & f(int & i){
    return ++i;
}

int main(){
    int i = 5;
    printf("f(i) is %d\n", f(i));
}
```
Best practice is to return a `const` reference
```
const int & f(const int & i){
    return i;
}
```

### Structure
```
struct Employee = {
    int id;
    const char * name;
    const char * role;
}

int main(){
    Employee employee = {2, "Datre", "Engineer"};
    Employee * j = &employee;
    j->name;
    j->role;
    j->id;
}
```

### Union
It is a data structure that allows you to use the same memory space for different types

### Defining types with typedef
```
typedef unsigned char points_t; // _t is tradtional for the type def types
typedef unsigned char rank_t;

struct score {
    points_t p;
    rank_t r;
};

int main(){
    score s = {5,1};
    return 0;
}
```
### Compound operator
The variable on the left hand side will be evaluated once. More efficient

### Pointer increment
```
void printp(int *p){
    printf("pointer is %p, value is %d\n", p, *p);
}

int main(){
    uint8_t *arr = {4,3,2,1};
    uint8_t *p = arr;
    printp(p++);
}
```
pre-increment is slightly more efficient than the post-increment, because post-increment has to copy the value firstly

### Dynamic memory operators
```
#include <new>

delete
```

### Using sizeof
- `size_t` is the return type of the `sizeof`
- `%zd` is used for `size_t` type
- `sizeof` always returns byte
- Find the space for a type

### Using typeid
```
#include <typeinfo>
typeid(a1)
```