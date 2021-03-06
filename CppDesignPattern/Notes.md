- Some challenges in the software development

    - Flexible code
    - Extensible code
    - Maintainable code

A **design pattern** is a common repeatable solution for creating software programs

Add new features; Update features; Replace features; Apply program in different situations

Around 23 design patterns: Creational; Structural; Behaviorial

## Creational Design Pattern
It is to efficiently create objects to increase flexibility
- Factory method

### Inheritence vs. composition
- Sometimes inheritence may cause class explosion
- If a parent class is too general, some properties might not be used by some inherited classes

Use inheritence together with composition. Then there is no extra shared code by all classes 

- Compositon: Properties referenced by another class. One class is using or consisting of another
- Inheritence: Class extends another class

![](images/Screenshot%202022-05-19%20234240.png)

### Concrete vs. abstract
`Virtual` keyword is used to indicate a method must be overriden
```
class BaseClass{
    public:
    virtual void methodA(){

    }
    virtual void methodB()=0
};
```

### Factory method design pattern
- One of the most used design patterns
- Encapsulates the creation of the related objects
- Create objects based on runtime parameters

![](images/Screenshot%202022-05-25%20214447.png)

A general usage of factory method is to give results based on the different options given by users

### Abstract factory design pattern
Aims to create a family/suite of classes or products

- Provides an interface for creating families of related objects without specifying their concrete classes

![](images/Screenshot%202022-05-21%20222711.png)

### Builder design pattern
- Separates construction of complex objects
- Builds a complex object one step at a time
- Same construction process for different representations

![](images/Screenshot%202022-05-23%20220117.png)

Builders share the same steps to build an object. The objects might have a common interface. 
![](images/Screenshot%202022-05-23%20234155.png)


### Prototype design pattern
Creates new objects by cloning an existing one
The difference between a copy constructor and prototype design pattern
![](images/Screenshot%202022-05-24%20215325.png)

Shallow copy: only the memeber is copied
Deep copy: makes copies of reference objects

### Singleton
 - Must be **global** accessible
 - Must only be **one instance** of a class
 ![](images/Screenshot%202022-05-25%20211342.png)
 The constructor is private. The class can not be instantiated in `main()`, which is outside of the class
 ```
 class Leader{
 private:
    Leader *_instance
    Leader()=0;
 public:
    Leader * getInstance(){
        if (_instance == NULL){
            _instance = new Leader();
        }
        return _instance;
    }
    void giveSpeech(){

    }
 }

 int main(){
     Leader::getInstance() -> giveSpeech();
 }
 ```
 - Lazy initialization
 - Critical section
    
    ```
    EnterCriticalSection(&critical);
    ...
    ...
    LeaveCriticalSection(&critical);
    ```
    Only one thread can excute the whole block. It is a costly operation


### Summary
![](images/Screenshot%202022-05-25%20213711.png)