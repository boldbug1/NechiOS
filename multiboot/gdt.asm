bits 32

global gdt_load

gdt_start:

; null descriptor
dq 0x0

; code segment
code_segment:
dw 0xFFFF
dw 0x0000
db 0x00
db 10011010b    ; present, ring0, code
db 11001111b    ; granularity + 32bit
db 0x00

; data segment
data_segment:
dw 0xFFFF
dw 0x0000
db 0x00
db 10010010b    ; present, ring0, data
db 11001111b
db 0x00

gdt_end:

; gdt pointer (XD;)
gdt_descriptor:
dw gdt_end - gdt_start - 1
dd gdt_start

; 2 part

CODE_SEG equ code_segment - gdt_start
DATA_SEG equ data_segment - gdt_start

; загрузка gdt
gdt_load:
    lgdt [gdt_descriptor]

    ; обновление сегментов
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    jmp CODE_SEG:flush

flush:
    ret