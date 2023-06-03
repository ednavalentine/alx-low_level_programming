section .data
	hello db "Hello, Holberton", 0
	format db "%s", 0
	newline db "\n", 10

section .text
	extern printf

global main
main:
	sub rsp, 8

	mov rdi, format
	mov rsi, hello
	xor rax, rax
	call printf

	add rsp, 8

	xor eax, eax
	ret
