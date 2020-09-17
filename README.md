# 0x19. C - Stacks, Queues - LIFO, FIFO

## Resources:books:
Read or watch:
* [Google](https://intranet.hbtn.io/rltoken/56-bDz7IrFgcH02EkGkB3w)
* [How do I use extern to share variables between source files in C?](https://intranet.hbtn.io/rltoken/9neX6gaN6DoA-ow1INgZqw)

---
## Usage
####Monty interpreter
The Monty language is a very simple programming language. Monty relies on a unique stack of integers and performs some operations.  
Usage is : `./monty FILE.m` where `FILE` contains lines of commands.  
Lines are of the type `opcode [argument]`.  
Current opcodes are: 
Number | Opcode | Description
---|---|---|
1 | **Push** | push onto stack. This opcode is the only one requiring an argument. This argument must be an integer. |
2 | **Pall** | print all stack.|
3 | **Swap** | swap the top 2 elements of the stack.|
4 | **Add** | pop the 2 elements at the top, push the result of the addition on the stack.|
4 | **Nop** | does not do anything|
---

### [0. push, pall](./1000-holberton.bf)
* Implement the push and pall opcodes.


### [1. pint](./1001-add.bf)
* Implement the pint opcode.


### [2. pop](./1002-mul.bf)
* Implement the pop opcode.


### [3. swap](./1003-mul.bf)
* Implement the swap opcode.

















---

## Author
* **Julian Camilo Torres** - [Camilo6](https://github.com/Camilo6)
* **Camilo Andrés Barreiro** - [Cbarreiro96](https://github.com/CBarreiro96)