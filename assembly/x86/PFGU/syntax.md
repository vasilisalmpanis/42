![peng](./peng.png)
# GNU assembly syntax 
immediate addressing mode
```text
movl $1, %eax
```

* indexed addressing mode

* indirect addressing mode
```
(%ecx), %eax
```

* base pointer addresing mode

```text
movl    -8(%ebp, %edx, 4), %eax  # Full example: load *(ebp + (edx * 4) - 8) into eax
movl    -4(%ebp), %eax           # Typical example: load a stack variable into eax
movl    (%ecx), %edx             # No index: copy the target of a pointer into a register
leal    8(,%eax,4), %eax         # Arithmetic: multiply eax by 4 and add 8
leal    (%edx,%eax,2), %eax      # Arithmetic: multiply eax by 2 and add edx
```


* mov{b,w,l,q}
* cmp{b,w,l,q}
* inc{b,w,l,q}
* dec{b,w,l,q}
* call
* jmp
* sub{b,w,l,q}, reg `create space, normally using the stack have local variables`
* push{b,w,l,q}
* pop{b,w,l,q}

* .lcomm -> *local common area*
* .comm -> *common area*
* .equ *NAME*, value
