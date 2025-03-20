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