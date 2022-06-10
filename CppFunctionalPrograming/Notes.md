## Functional programing style
- Imumutable variables
- Recursion over loops
- Functions are pure and simple
- Expressions preferred over statements
- Currying manages how arguments are passed to functions
![](images/Screenshot2022-06-08223546.png)

`std::tansform` replaces `map`

`std::copy_if` replaces `filter`

`std::accumulate` replaces `reduce`

`std::bind`

- Manipulate a function and its parameters
- Reorder the function's arguments
- Bind values to arguments
```
 bind(&greaterThan, placeholders::_1, 21));
```
The first argument is the function address. 

`std::function`
- It is a wrapper for invokable objects
- Invokable objects include functions, functors and lambdas
- Can store functions in a vector

`Lambda`
- Unnamed function object
- Create closure over calling scope
- Use the keyword mutable to make changes to the closure

