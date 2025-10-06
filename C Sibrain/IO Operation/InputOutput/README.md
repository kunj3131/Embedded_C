# Input Output

## putchar and getchar
Read write single character but require to write before scanf other wise it return error due to input buffer

## printf and scanf
allowing you to display different data types (like integers, floats, and strings) using format specifiers (e.g., %d for integers, %f for floats, %s for strings).
 By default, scanf skips over whitespace characters like spaces, tabs, and newlines when it's looking for input to match a format specifier. 
The real issue arises when scanf doesn't consume the newline character left in the input buffer after a user presses Enter. For example, consider this code

## pgets and fgets
It reads an entire line of input until a newline character is encountered, but it doesn't know the size of the buffer it's writing to.  This can lead to a program crashing or being exploited.
On the other hand, fgets is the safe alternative. It takes three arguments: the buffer to store the string, the maximum number of characters to read (which prevents buffer overflow), and the input stream from which to read. Always use fgets for reading strings.

