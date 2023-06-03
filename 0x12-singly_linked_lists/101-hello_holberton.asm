section .data
	message db 'Hello, Holberton', 0

section .text
	extern printf

global main
main:
	; Prepare arguments for printf function call
	mov rdi, message
	xor rax, rax  ; Clear rax register to indicate no floating-point arguments
	call printf

	; Exit the program
	mov eax, 60  ; System call number for exit
	xor edi, edi ; Exit status code (0)
	syscall
