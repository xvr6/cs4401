# stack3

`cd /problems/stack3r-64_6_b4102fbcd5bc361d916ae5602ca212ce/`

- finding a different target for manipulation
- there is no vulnerable local variable to corrupt
  - we can corrupt a return address instead
-  

## Stack

```
x is random memory

lower addr                    higher
--------------------------xxxxxxxxxx
                          ^ rsp @ start of main
```

```
ni; adds 8 bytes to memory:

lower addr                    higher
-------------------mmmmmmmxxxxxxxxxx
                  ^ rsp @ main+1
                  b0 48 55 55 55 55
```

```
sub rsp, 0x20; allocating space on stack or local variables

lower addr                    higher
        | 0x20     |
-------------------mmmmmmmxxxxxxxxxx
        ^ rsp @ main+1

```

- x/gx $rsp: `0x5555555548b0`
  - translates from little endian to what is more natural
- x/8bx $rsp: `0xb0 0x48 0x55 0x55 0x55 0x55`
  - order of actually laid out in memory (little endian)

## Canary

- If we overflow through a canary to access other variables, the program can detect if a canary is modified and stop the program
- if we override the canary with teh exact same value the program is expecting, it'll be undetected
- Canarys always contain a null terminator
  - this is so no string funcitonc an overread and display the canary for the above mentioned attack method.

## Course grained ASLR

- moves around variables randomly, but does not change the data within them
- imagine moving books around randomly on a bookshelf - the contents never change but the location does.
  - A way to get around this is just to find out one address in a known variable, and you'd know the rest of the locations in that section
- We need to get an information leak
  - trick the program into giving one know address, you can then know all the rest of the programs information