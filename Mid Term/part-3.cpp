#include <iostream>
#include <string>

template <typename T>
T within(T& A, T& B, T& C, T& D )
{
    int noOfELemets=0;
    for (int i = 0; i < C; i++)
    {
        if (i == C)
        {
            noOfELemets++;
            break;
        }
        noOfELemets++;
    }

    return noOfELemets;
}

template <>  
 int within<int>(const char* a, const char* b, const char* c, const char* d)
{
    if (a == b)
    {
        return sizeof(array) / sizeof(a[])
    }

}


int main()
{
    std::string str[]{ "yes", "no", "who", "when", "why" };
    int a[]{ 1, 2, 3, 4, 5 };
    double b[]{ 1.1, 2.2, 3.3, 4.4, 2.2 };

    auto i = within(str, std::string("who"), std::string("why"), 5);
    std::cout << i << std::endl;

    i = within(a, 3, 5, sizeof a / sizeof(int));
    std::cout << i << std::endl;

    i = within(b, 2.2, 3.3, sizeof b / sizeof(double));
    std::cout << i << std::endl;
}

Define a family of functions(a templated function) named within that return the number of elements of an array of any type and specified length that have values between specified lower and uppper bounds inclusive of the same type.

Specialize the function for the type std::string.In this specialization, a string lies between the specified bounds if the first character of the string lies between the first character of the bounds(according to their ASCII codes).The other characters need not be the same.

The client code listed below uses your template to produce the output shown.

A type that uses this template must include in its definition certain functionsand /or operators.Identify each function and /or operator that your template assumes is defined.You may do so in the form of an exact prototype or an English descriptive phrase.

Write your solution in the textbox below.