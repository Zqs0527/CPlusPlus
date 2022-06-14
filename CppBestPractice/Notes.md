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

Modern C++ has three types of smart pointers
- `std::shared_ptr`
- `std::unique_ptr`: default option
- `std::weak_ptr`

The Rules of Zero, Three, and Five
- Five Class special functions:
    - Copy constructor, copy assignment operator, move operator, move assignment operator and destructor
- Zero
    - Don't create above five special functions. The best practice is to leave them to the compiler

Resource Aquisition Is Initialization (RAII)
- The destructors of stack objects are always called
- Stack objects are trashed in reverse order of their creating
- Any critical resources should be created on the stack
- They should be written to destroy themselves properly
