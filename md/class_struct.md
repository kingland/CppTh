# Class vs Struct

In C++, struct and class are both used to define user-defined types, but they differ primarily in their default member access specifiers and default inheritance visibility.

## Key Differences

**Default Member Access:**

* struct: Members (data and functions) declared within a struct are public by default. This means they are accessible from outside the struct without explicitly specifying public:.
* class: Members declared within a class are private by default. This means they are not directly accessible from outside the class unless explicitly specified as public: or protected:.

**Default Inheritance Visibility:**

* struct: When a struct inherits from another class or struct, the inheritance is public by default.
* class: When a class inherits from another class or struct, the inheritance is private by default.


## Similarities and Capabilities
Despite these default differences, struct and class are functionally very similar in C++. Both can:

* Have member variables (data) and member functions (methods).
* Have constructors and destructors.
* Support inheritance (public, protected, and private).
* Support polymorphism through virtual functions.
* Implement access specifiers (public, private, protected) explicitly to override the defaults.

## When to Use Which
While technically interchangeable with explicit access specifiers, a common convention guides their usage:

**struct:**
Typically used for Plain Old Data (POD) structures or simple data aggregates where the primary purpose is to group related data, and direct access to members is generally intended. Think of them as lightweight containers for data.

**class:**
Generally preferred for defining objects with encapsulated behavior, where data is often hidden (private) and accessed through public member functions (methods), promoting information hiding and object-oriented principles.

In essence, the choice between struct and class often comes down to semantic intent and readability, with struct signaling a data-centric type and class indicating a more feature-rich, behavior-oriented object.