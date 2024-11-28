#include <stdio.h>

int main() {
    // Variable declaration
    int a = 10, b = 20;
    int result;
    int bitwiseResult;

    // Arithmetic Operators
    printf("Arithmetic Operators:\n");
    printf("a + b = %d\n", a + b); // Addition
    printf("a - b = %d\n", a - b); // Subtraction
    printf("a * b = %d\n", a * b); // Multiplication
    printf("b / a = %d\n", b / a); // Division
    printf("b %% a = %d\n", b % a); // Modulus

    // Relational Operators
    printf("\nRelational Operators:\n");
    printf("a == b: %d\n", a == b); // Equal to
    printf("a != b: %d\n", a != b); // Not equal to
    printf("a > b: %d\n", a > b);   // Greater than
    printf("a < b: %d\n", a < b);   // Less than
    printf("a >= b: %d\n", a >= b); // Greater than or equal to
    printf("a <= b: %d\n", a <= b); // Less than or equal to

    // Logical Operators
    printf("\nLogical Operators:\n");
    printf("(a < b) && (a > 0): %d\n", (a < b) && (a > 0)); // Logical AND
    printf("(a < b) || (a < 0): %d\n", (a < b) || (a < 0)); // Logical OR
    printf("!(a < b): %d\n", !(a < b)); // Logical NOT

    // Bitwise Operators
    printf("\nBitwise Operators:\n");
    bitwiseResult = a & b; // Bitwise AND
    printf("a & b = %d\n", bitwiseResult);
    bitwiseResult = a | b; // Bitwise OR
    printf("a | b = %d\n", bitwiseResult);
    bitwiseResult = a ^ b; // Bitwise XOR
    printf("a ^ b = %d\n", bitwiseResult);
    bitwiseResult = ~a;    // Bitwise NOT
    printf("~a = %d\n", bitwiseResult);
    bitwiseResult = a << 1; // Left shift
    printf("a << 1 = %d\n", bitwiseResult);
    bitwiseResult = a >> 1; // Right shift
    printf("a >> 1 = %d\n", bitwiseResult);

    // Assignment Operators
    printf("\nAssignment Operators:\n");
    result = a; // Simple assignment
    printf("result = a: %d\n", result);
    result += b; // Add and assign
    printf("result += b: %d\n", result);
    result -= a; // Subtract and assign
    printf("result -= a: %d\n", result);
    result *= 2; // Multiply and assign
    printf("result *= 2: %d\n", result);
    result /= 2; // Divide and assign
    printf("result /= 2: %d\n", result);
    result %= 3; // Modulus and assign
    printf("result %%= 3: %d\n", result);

    // Conditional Operator
    printf("\nConditional Operator:\n");
    int max = (a > b) ? a : b; // Ternary operator
    printf("Max of a and b is: %d\n", max);

    return 0;
}
