# RISC-V Assembly

* In general, binary operations like addition, AND, XOR, multiplication, and so on, specify 3 operands: 2 source registers with read access, and 1 result register with write access.
* Support of pseudoinstructions to ease the task of writing assembly code.
* Direct translation between assembly language and machine language.

### Elements

- Instructions
- Registers
- Labels
- Directives
- Macros
- Pseudoinstructions

> These elements are combined to create RISC-V assembly programs, which are then assembled into machine code and executed by the processor.

### Example
```asm
  .text2  .text             # Directive: enter text section
  .align 2                  # Directive: align code to 2^2 bytes
  .globl main               # Directive: declare global symbol main

main:                       # label for start of main
  addi sp,sp,-16            # allocate stack frame
  sw ra,12(sp)              # save return address
  lui a0,%hi(string1)       # compute address of
  addi a0,a0,%lo(string1)   # string1
  lui a1,%hi(string2)       # compute address of
  addi a1,a1,%lo(string2)   # string2
  call printf               # call function printf
  lw ra,12(sp)              # restore return address
  addi sp,sp,16             # deallocate stack frame
  li a0,0                   # load return value 0
  ret                       # return

  .section .rodata          # Directive: enter read-only data section
  .balign 4                 # Directive: align data section to 4 bytes

string1:                    # label for first string
  .string "Hello, %s!\n"    # Directive: null-terminated string

string2:                    # label for second string
  .string "world"           # Directive: null-terminated string
```

#### Directives
<details>
<summary>align</summary>
Aligns the location counter to a specified power of 2 boundary.
</details>
<details>
<summary>section</summary>
Specifies the section of the output file where the following data should be placed.
</details>
<details>
<summary>byte</summary>
Defines an array of 8-bit values.
</details>
<details>
<summary>half</summary>
Defines an array of 16-bit values.
</details>
<details>
<summary>word</summary>
Defines an array of 32-bit values.
</details>
<details>
<summary>data</summary>
Specifies the start of the data section where initialized data is stored.
</details>
<details>
<summary>text</summary>
Specifies the start of the code section where instructions are stored.
</details>
<details>
<summary>globl</summary>
Declares a symbol as global and accessible from other files.
</details>
<details>
<summary>equ</summary>
Assigns a value to a symbol, useful for constants.
</details>
<details>
<summary>string</summary>
Defines a string of ASCII characters with a null terminator.
</details>

#### Basic Instructions

| Instruction             | Meaning                                                                                   |
|-------------------------|-----------------------------------------------------------------------------------------  |
| add rd, rs1, rs2        |                                                                                           |
| auipc rd, immediate     | Adds the 20-bit immediate left-shifted by 12 bits to the PC and writes the result to rd   |
| jal rd, offset          | Writes PC+4 to rd and jumps to PC plus the sign-extended offset                           |
| jalr rd, offset(rs1)    | Writes PC+4 to rd and jumps to rs1 plus the sign-extended offset                          |
| lw rd, offset(rs1)      | Loads 4 bytes from address rs1 plus the sign-extended offset, and writes them to rd       |
| lb rd, offset(rs1)      | load byte                                                                                 |
| lui rd, immediate       | load upper immediate (20 bits)                                                            |
| addi rd, rs1, immediate | add immediate (12 bits) to rsq and write result to rd                                     |
| sw rs2, offset(rs1)     | store from rs2 to rs1 plus offset                                                         |
| sb rs2, offset(rs1)     | Stores the least significant byte from rs2 into address rs1 plus the sign-extended offset |

> The manipulation of the CSR registers instructions are part of the Zicsr IS
