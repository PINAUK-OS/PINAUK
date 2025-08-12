; ports.asm
.code
outw proc port:word, val:word
    mov dx, port
    mov ax, val
    out dx, ax
    ret
outw endp
end
