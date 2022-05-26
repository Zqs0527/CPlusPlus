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

### Template variable
`constexpr`: It is available at compile time. It is a strongly typed constant

`auto` is type inference

`decltype()` is a keyword to declare a type