# Bases
- base 10
    Digits 0-9 and combine numbers but combining digits together.
- hexadecimal
    [0123456789abcdef]
- binary
    0,1: combine them to get different values
      0 0 0 0 0 0 0 0
      2^7 2^6 2^5-2^0

# x86 arch
- CPU
    ALU - logic and arithmetic
    Control Unit - decode instructions and direct operations to other units
    Clock - cycles between 0 and 1 ( Time between these is one clock cycle) at the tick we execute an instruction 
    Registers - fastest memory to access. part of the CPU
- Memory
- IO Devices

- Control BUS
    help sychronizes all the devices attached to the BUS
- Address BUS
    helps hold the address of instruction. help to show where things will be moved
- Data BUS
    handles transfer of data between CPU, Memory, IO devices etc

# Instructions:
- fetch
- decode
- if operands are involved, fetch them from Memory
- exevute the instruction and update the status flag
- store the result if required

# Modes
- Protected Mode - the native processor state
- Real address mode - early intel programming environment with the ability to switch modes

# Registers
- 32 bit size registers
example : eax, ebx, ecx, edx
high 16 bits: ax, bx, cx, dx
8bit high: ah, bh, ch, dh
8bit low: al, bl, cl, dl

- eax used by multiplication and division
- ebx GP
- ecx used as loop counter
- edx GP
- esi High speed memory transfer
- edi High speed memory transfer
- ebp Base pointer (used to reference function parameters and local stack variables)
- esp Stack pointer
- eip instruction pointer

- EFLAGS: 
    - CF carry
    - OF overflow
    - SF sign
    - ZF zero
    - AC auxiliary
    - PF parity
