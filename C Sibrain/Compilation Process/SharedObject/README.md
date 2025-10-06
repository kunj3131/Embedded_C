## Dynamic Linking with Shared Object File

# Preprocessing
cc -E -P hello.c -o hello.i

# Compiling
cc -S hello.i -o hello.s

# Linking
cc -c -fPIC hello.s -o hello.o

# Shared Object 
cc -shared -o hello.so hello.o

# Executing 
cc main.c ./hello.so -o hello
