## Template
```
template <typename T> T maxof(const T &a,const T &b){
    return a > b ? a : b;
}
```
When `maxof()` is called, there will be a specialization created by compiler, if the input type is `int`, the specilization is 
```
int maxof(cosnt int &a,const int &b){
    return a > b ? a : b;
}
```
if `a` and `b` are `string` type, the comparison is based on the alphabets order

if if `a` and `b` are `pointer` type, the comparison is based on the pointer, e.g. `const char *`

There is also argument deduction. When the template function is called, there is no need to specify the type. The compiler can determine the type.
```
 maxof<int>(a, b); <-> maxof(a, b)
```

### Template variable
`constexpr`: It is available at compile time. It is a strongly typed constant

`auto` is type inference

`decltype()` is a keyword to declare a type

### Containers
Containers are the heart of the STL

- Vector
- List

The list is a sequence container like a vector, but it is optimized for rapid insert and delete operations. It doesn't support random access

    - list\<int\> l1 = {1, 2, 3};