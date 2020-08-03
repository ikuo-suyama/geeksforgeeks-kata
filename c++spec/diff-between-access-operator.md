## For Instance...
ClassName::FieldName : class public static field and methods
ClassInstance.FieldName : accessing a public field (or method) through class reference
ClassPointer->FieldName : accessing a public field (or method) dereferencing a class pointer

### 1.-> for accessing object member variables and methods via pointer to object
```cpp
Foo *foo = new Foo();
foo->member_var = 10;
foo->member_func();
```

### 2.. for accessing object member variables and methods via object instance
```cpp
Foo foo;
foo.member_var = 10;
foo.member_func();
```

### 3.:: for accessing static variables and methods of a class/struct or namespace.
It can also be used to access variables and functions from another scope (actually class, struct, namespace are scopes in that case)

```cpp
int some_val = Foo::static_var;
Foo::static_method();
int max_int = std::numeric_limits<int>::max();
```