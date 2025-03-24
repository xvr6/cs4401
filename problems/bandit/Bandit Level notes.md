# Bandit Levels 0-12

0) simply read the readme file
- ZjLjTmM6FvvyRnrb2rfNWOZOTa6ip5If

1) cat file ./-
- 263JGJPfgU6LtdEvgfWU1XP5yac29mFx

2) cat ./spaces\ in\ this\ filename
- MNk8KNH3Usiio41PRUEoDFPqfxLPlSmx

3) cd ./inhere; cat ...Hiding-From-You 
- 2WmrDFRmJIq3IPxneAaMGhap0pFhF3NJ

4) cd ./inhere; file ./* 
- find the only human readable file
- 4oQYVPkxZOOEOO5pTW81FB8j8lxXGUQw

5) Level 5

- cd ./inhere
- file must be:
  - human-readable
    - find . -type f
  - 1033 bytes in size
    - find . -size 1033c
  - not executable
    - find ! -executable -exec file {} +
  - so... `find . -type f -size 1033c ! -executable -exec file {} +`
- cat the only file in output `cat ./maybehere07/.file2`
  - `HWasnPhtq9AVKe0dmk45nxy20cvUa6EG`

6)  
- cd to root
- owned by user bandit7
- owned by group bandit6
- 33 bytes in size
- find . -type f -size 33c -group bandit6 -user bandit7
  - find file that is accessable:
    - `morbNTDkSW6jIlUc0ymOdMaLnOlFVAaj`

7)  

- The password for the next level is stored in the file data.txt next to the word millionth
- grep "millionth" data.txt ( or `grep "millionth" data.txt | awk '{print $2}'` if just pswd should be returned)
  - `dfwvzFQi4mU0wfNbFOe9RoWskMLg7eEc`

8)  

- The password for the next level is stored in the file data.txt and is the only line of text that occurs only once
- `sort data.txt | uniq -u`
  - `4CKMh1JI91bUIZZPXDqGanal4xvAg0JM`

9)  

- The password for the next level is stored in the file data.txt in one of the few human-readable strings, preceded by several ‘=’ characters.
- strings data.txt | grep "===="
  - `FGUW5ilLVJrxX9kMYMmlN4MgbpfMiqey`  
  
10) The password for the next level is stored in the file data.txt, which contains base64 encoded data

- `base64 -d data.txt`
  - `dtR173fZKb0RRsDFSGsg2RWnpNVj3qRr`

11) The password for the next level is stored in the file data.txt, where all lowercase (a-z) and uppercase (A-Z) letters have been rotated by 13 positions

- `cat data.txt | tr 'A-Za-z' 'N-ZA-Mn-za-m'`
  - `7x16WNeHIi5YkIhWsfFIqoognUTyj9Q4`

12)  The password for the next level is stored in the file data.txt, which is a hexdump of a file that has been repeatedly compressed. For this level it may be useful to create a directory under /tmp in which you can work.

- Make tmp
  - mktemp -d
  - cd /tmp/(above line)
- copy file to tmp
  - cp ~/data.txt .
- Connvert tobinary file
  - xxd -r data.txt > compressed_file
- see what file type
  - file compressed_file
- in this case, its a gzip:
  - mv compressed_file cf.gz
  - gunzip cf.gz
- now:
  - file cf
  - in this case, its now a bzip2
  - bzip2 -d cf.bz2 
- now:
  - file cf
  - in this case, gzip
- finally:
  - tar xvf cf
- so on so forth: `FO5dwFsc0cbaIiH0h8J2eUks2vdTDwAn`


13) The password for the next level is stored in /etc/bandit_pass/bandit14 and can only be read by user bandit14. For this level, you don’t get the next password, but you get a private SSH key that can be used to log into the next level. Note: localhost is a hostname that refers to the machine you are working on

-  ssh -i sshkey.private bandit14@localhost -p 2220
-  cat /etc/bandit_pass/bandit14
- `MU4VWeTyJk8ROof1qqmcBPaLh7lDCPvS`

14)  The password for the next level can be retrieved by submitting the password of the current level to port 30000 on localhost.

-  cat /etc/bandit_pass/bandit14 | nc localhost 30000
-  `8xCjnmgoKbGLhHFAZlGE5Tmu4M2tKJQo`
-  

15) The password for the next level can be retrieved by submitting the password of the current level to port 30001 on localhost using SSL/TLS encryption.

- echo 8xCjnmgoKbGLhHFAZlGE5Tmu4M2tKJQo | openssl s_client -connect localhost:30001 -quiet
- `kSkvUpMQ7lBYyCM4GBPvCvT1BfWRy0Dx`

16) The credentials for the next level can be retrieved by submitting the password of the current level to a port on localhost in the range 31000 to 32000. First find out which of these ports have a server listening on them. Then find out which of those speak SSL/TLS and which don’t. There is only 1 server that will give the next credentials, the others will simply send back to you whatever you send to it.

- list of all listening ports
  - nmap -p 31000-32000 localhost
- test for ssl connection
  - openssl s_client -connect localhost:<port>
- echo kSkvUpMQ7lBYyCM4GBPvCvT1BfWRy0Dx | openssl s_client -connect localhost:31790 -quiet
- make local key file with above, then
  -  chmod 600 bandit17.key
- connect to 17 with:
  - ssh -i bandit17.key bandit17@bandit.labs.overthewire.org -p 2220


17) There are 2 files in the homedirectory: passwords.old and passwords.new. The password for the next level is in passwords.new and is the only line that has been changed between passwords.old and passwords.new 

- diff passwords.new passwords.old 
- `x2gLTTjFwMOhQ8oWNbMN362QKxfRqGlO`

18) The password for the next level is stored in a file readme in the homedirectory. Unfortunately, someone has modified .bashrc to log you out when you log in with SSH.

- log in with non interactive shell
  - ssh bandit18@bandit.labs.overthewire.org -p 2220 "cat readme"
  - `cGWpMaKXVwDUNgPAVJbWYuGHVn9zl3j8`

19) To gain access to the next level, you should use the setuid binary in the homedirectory. Execute it without arguments to find out how to use it. The password for this level can be found in the usual place (/etc/bandit_pass), after you have used the setuid binary.

- binary jsut runs as if bandit20
- so: ./bandit20-do cat /etc/bandit_pass/bandit20
  - `0qXahG8ZjOVMN9Ghs7iOWsCfZyXOUbYO`

20) There is a setuid binary in the homedirectory that does the following: it makes a connection to localhost on the port you specify as a commandline argument. It then reads a line of text from the connection and compares it to the password in the previous level (bandit20). If the password is correct, it will transmit the password for the next level (bandit21).

- need to use tmux for nultiolkpe consoles
- in one window:
  - nc -l -p 12345
- in other 
  - ./suconnect 12345
- back in the NC window, type the password from bandit 20 and get pswd for pandit 21
  - `EeoULMCra2q0dSkYj561DX7s1CpBuOBt`

21) A program is running automatically at regular intervals from cron, the time-based job scheduler. Look in /etc/cron.d/ for the configuration and see what command is being executed.
  
- ls -l /etc/cron.d/
- cat /etc/cron.d/cronjob_bandit22
  - mentions a .sh file
- cat /usr/bin/cronjob_bandit22.sh
  - mentions a file in tmp
- cat /tmp/t7O6lds9S0RqQh9aMcz6ShpAoZKF7fgv
  - `tRae0UfB9v0UzbCdn9cY0gQnds9GF58Q`

22) same first 2 steps

- cat /usr/bin/cronjob_bandit23.sh
``` bash
#!/bin/bash

myname=$(whoami)
mytarget=$(echo I am user $myname | md5sum | cut -d ' ' -f 1)

echo "Copying passwordfile /etc/bandit_pass/$myname to /tmp/$mytarget"

cat /etc/bandit_pass/$myname > /tmp/$mytarget
```

- running: `echo I am user bandit23 | md5sum | cut -d ' ' -f 1`
  - 8169b67bd894ddbb4412f91573b38db3
- So: `cat /tmp/8ca319486bfbbc3663ea0fbe81326349`
  - `0Zf11ioIjMVN551jX3CmStKLYqjk54Ga`

23)  
`gb8KRRCsshuZXI0tUuR6ypOFjiZbf3G8`

24)  
``` bash
#!/bin/bash

for i in {0000..9999}
do
        echo gb8KRRCsshuZXI0tUuR6ypOFjiZbf3G8 $i >> possibilities.txt
done

cat possibilities.txt | nc localhost 30002 > result.txt
```

- sort result.txt | grep -v "Wrong!"
  - `iCi86ttT4KSNe1armKiwbQNmB3YJP3q4`

25)  s0773xxkk0MXfdqOfPRVr9L3jJBUOgCZ
26)  upsNCc7vzaRDx6oZC6GiR6ERwe1MowGB
27)  Yz9IpL0sBcCeuG7m9uQFt8ZNpS4HZRcN
28)  4pT1t5DENaYuqnqvadYs1oE4QLCdjmJ7
29)  qp30ex3VLz5MDG1n91YowTv4Q8l7CDZL
30)  fb5S2xb7bRyFmAvQYQGEqsbhVyJqhnDy
31)  3O9RfhqyAlVBEZpVb6LYStshZoqoSx5K
32)  breaking out of shell
    
- `$0`
- whoami
  - bandit33
- cat /etc/bandit\_pass/bandit33
- `tQdtbs5D5i2vJwkO8mEyYEyTL8izoeJ0`
