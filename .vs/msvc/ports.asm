; ports.asm (MASM / x64-compatible)
.code
outw proc port:word, val:word
    mov dx, port
    mov ax, val
    out dx, ax
    ret
outw endp
end
