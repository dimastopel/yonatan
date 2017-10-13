Compile:
nasm -f elf64 syscall.asm
ld -o syscall syscall.o
strip -s syscall



# Show headers
readelf -h tiny

# Show sections
readelf -S tiny

# Show hex of the whole file
xxd tiny

# Disassemble
objdump -M intel -d tiny
