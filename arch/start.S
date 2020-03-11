
.section .text
nop

.global _start
_start:
    stmfd sp!, {lr}

    bl main

    ldmfd sp!, {pc}
