## Template
```
template <typename T> T maxof(T &a, T &b){
    return a > b ? a : b;
}
```
When `maxof()` is called, there will be a specialization created by compiler, if the input type is `int`, the specilization is 
```
int maxof(int &a, int &b){
    return a > b ? a : b;
}
```
if `a` and `b` are `string` type, the comparison is based on the alphabet.

if if `a` and `b` are `pointer` type, the comparison is based on the pointer, e.g. `const char *`