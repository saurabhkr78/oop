/*
Definition
An inline function is a function where the compiler tries to copy the function's code directly where it is called, instead of jumping to a separate function call.

Purpose
It is used to make programs faster, especially for small functions that are called many times. It avoids the extra work of calling a function (like saving memory and passing arguments).

Syntax
To make a function inline, just add the inline keyword before the function:

cpp
Copy
inline int add(int a, int b) {
    return a + b;
}
Performance
Inline functions can make your program run faster because they avoid the overhead of function calls. However, they can also make your program larger because the function code is copied everywhere it is used.

Compiler Discretion
The inline keyword is a suggestion to the compiler. The compiler can ignore it if the function is too big or complex.

Use Cases
Best for small, simple functions that are called often, like getters and setters in classes.

Trade-offs
Pros: Faster execution for small functions.

Cons: Can increase the size of your program if the function is used many times.

Header Files
Inline functions are often written in header files because the compiler needs to see the full function definition to copy it.

Limitations
Not good for large functions, recursive functions, or functions with loops, as they can make the program too big.

Debugging
Harder to debug because the function code is copied into multiple places, making it harder to track.

Linkage
Inline functions are not shared across different files by default. They are only visible in the file where they are defined.

Macros vs. Inline Functions
Inline functions are better than macros because they are safer and easier to debug. Macros are just text replacements and can cause errors.

C++ Member Functions
In C++, if you define a function inside a class, it is automatically treated as inline.

Best Practices
Use inline functions only for small, simple functions that need to be fast. Avoid using them for large or complex functions.




---we we try to execute a fxn1 and inside the fxn1 we call another fxn2. as we know each function have thier own stack frame and when we call a function, the control goes to the called function and the stack frame of the called function is created.
-- the memory is allocated for the fxn1 and inside the d\fxn1 we have another fxn2. so, we craete  stack frame for fxn2 aswell.and memory is allocqated for fxn2.here we can see to much overhead. to avoid overhead from the function call, we use inline function.



*/

#include<bits/stdc++.h>
using namespace std;
class Test{
    public:
    void display();
    inline void show();

};
int main(){
    Test t;
    t.display();
    t.show();
    return 0;
}
