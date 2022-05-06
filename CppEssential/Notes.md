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
