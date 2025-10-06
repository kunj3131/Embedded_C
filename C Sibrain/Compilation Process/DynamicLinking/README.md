## C Compilation Process

# Preprocessing
gcc -E -P hello.c -o hello.i

# Compilation
gcc -S hello.i -o hello.s

# Assembling
gcc -c hello.s -o hello.o

#Linking
gcc hello.o -o hello

# Execution 
./hello
