C++11 added lambdas, auto type deduction, list initialization, smart pointers and move semantics

C++14 gave return type deduction, binary literals and generic lambda expressions

C++17 structured binding, nested namespace, inline variables and constexpr lambda

- Static Analyzers
    - Tool that automatically examines C++ code for issues
    - It is much slower than compilation
    - Dozens of static analyzers, open source and commercial
    - Occasionally false positive
    - Usually added to a program's build chain

Cppcheck -> even checks for use of STL

Coverity -> a static analysis tool for C/C++ (commercial)

Auto type deduction
- `auto` tells the compiler to deduce the type of a variable

Strongly typed enums
- Must use scope resolution operator
- Enums no longer exported to surrounding scope
- Redefinition of types ia no longer an issue
- Implicit conversion is no longer allowed


Lambda functions
- Unnamed function object
- Use a lambda to write a local function of limited use
- Use a lambda for complex initialization
- Always prefer lambda function to `std::bind`