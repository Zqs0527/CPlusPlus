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

- Pair and tuple

    - `pair` is in the `#include <utility>` header
    - Comparison operators work for the `pair`. The first value of the pair has the priority to be compared. `pair<int, string>`
    - `pair<int, string> &p` the values of p can be accessed by using `p.first` and `p.second`
    - `tuple` type is in the `#include <tuple>` header
    ```
    template<typename T> void print3tuple(T t){
        auto tsz = tuple_size<decltype>::value;
        if(tsz != 3) return;
        cout << get<0>(t) << ":" << get<1>(t) << ":" << get<2>(t) << endl;
    }
    ```

- Array

    - It is a fixed size sequence container
    ```
    template<typename T, size_t N> void printa(array<T, N> &a){
        for (T &i : a) cout << i << " ";
        cout << endl;
    }
    ```
- Deque
    - It is in the `#include <deque>` header
    - Double ended queue, hence the name D-E queue
    - It is opeimized to push and pop from its ends

- Queue
    - A queue is a container adaptor, which is like a wrapper that uses an underlying container to hold its contents
    - The queue implements a first in and first out queue, pushed back from the container and popped from the front
    ```
    list<int> l1 = {1,2,3,4,5};
    queue<int, list<int>> q1(l1);
    ```

- Stack
    - Stack is a container adaptor, which is like a wrapper that uses an underlying container to hold its contents
    - The stack implements last in first out stack, where the elements pushed and popped from the top of the stack which is the back of the container

- Set
    - It is a container holds a sorted elements. It holds only unique elements. `multiset<string>` provides the duplication of the elements
    - `#include <unordered_set>` will not sort the set and it will make it faster to access by providing the hash keys

- Map
    - key value pairs, `{"a", "b"}`


### Iterators

It works a lot like a pointer. It can be incremented and de-referenced
- double colon operator `::` is the scope resolution operator. `iterator` class is defined in the scope of container
```
vector<int> vi1 = {1,2,3,4};
vector<int>::iterator it1;
vector<int>::iterator ibegin = vi1.begin();
vector<int>::iterator iend = vi1.end();

for (it1 = ibegin; it1 < iend; it1++){
    cout << *it1 << " ";
}
cout << endl;
```
- Accessing iterators
- Input iterators
- Output iterators
- Forward iterators
- Bidirectional iterators
- Random access iterators

`container.end()` is pointing to the location passed the last element of the container.
```
vector<int> v1 = {1,2,3,4}
x = v1.end() - 3
```
The value of x is 2


### Transformations
It is in the header of `algorithm`
- Lambda transformation
```
auto x = [accum] (int d) mutable -> int {return accum += d;};
```
`accum` is to capture something. `(int d)` is the parameter. `-> int` the return value type is `int`. 