# Problem stack0r-64

## My solution

simple buffer overflow of vulnerable gets function to change a boolean to 1

## Prof solution

- use pwntools
- flat({132:0xdeadbeef})
  - at offset 132, put that hex value