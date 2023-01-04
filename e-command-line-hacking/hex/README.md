# this hex program
# run this on a linux machine
## too install the hex program 
first compile the program with `make`
```sh
[user@linux][~]$ make
```
output:
```
mkdir -p bin
g++ -c -Wall -std=c++2a src/converter.cpp -o src/converter.o
g++ -c -Wall -std=c++2a src/main.cpp -o src/main.o
g++  -o bin/hex src/converter.o src/main.o 

```
then install the program with `make install`
```sh
[user@linux][~]$ make install
```
output:
```
mkdir -p /opt/hex
cp bin/hex /opt/hex
ln -sf /opt/hex/hex /usr/local/bin/hex

```
## usage example hex
input:
```sh
[user@linux][~]$ hex -h
```
output:
```sh

convert decimal numbers to there hex value
Usage:
  hex [OPTION...]

  -v, --version  print version
  -h, --help     print usage
  -d, --decimal  convert hex numbers to there decimal value
  -f, --file     arg File name as input file (this does not change input file but returns changed file output as echo in terminal)

```