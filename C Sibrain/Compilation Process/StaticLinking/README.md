## Linking 

# Preprocessing
gcc -E -P hello.c -o hello.i

# Compilation
gcc -s hello.i -o hello.s

# Assembling
gcc -c hello.s -o hello.o

# Static Linking
gcc -static hello.o -o hello

--> Static Linking Increase Size of File
