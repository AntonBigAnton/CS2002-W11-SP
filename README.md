# CS2002 W11-SP

This is my implementation of the [W011-SP practical for CS2002](https://studres.cs.st-andrews.ac.uk/CS2002/Coursework/W11-SP/W11-SP.pdf).

## Source files

All source files are in the src folder. These are:
- 4 C program files,
- 3 header files,
- A Makefile.
  
My submission also contains a PDF report and this README.md file.

## Compiling

To compile the code, please use the Makefile and run the following commands in the terminal:
```bash
cd src
make clean
make
```

## Testing

To run the unit tests, please first compile (see previous section).
  
To test my Queue implementation, please use the Makefile and run the following command in the terminal:
```bash
./TestQueue
```
  
The output should be:
```bash
Queue Tests complete: 21 / 21 tests successful.
----------------
```
  
To test my BlockingQueue implementation, please use the Makefile and run the following command in the terminal:
```bash
./TestBlockingQueue
```
  
After a brief delay of approximately 2 seconds (this is normal!), the output should be:
```bash
  
BlockingQueue Tests complete: 21 / 21 tests successful.
----------------
```
