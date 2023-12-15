#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define _GNU_SOURCE
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
void print_character(stack_t **stack, unsigned int line_n);
void print_string(stack_t **stack, unsigned int line_n);
void rotl(stack_t **stack, unsigned int line_n);
void rotr(stack_t **stack, unsigned int ln);
void node_add(stack_t **new_node, unsigned int line_n);
void print(stack_t **stack, unsigned int line_n);
void pop(stack_t **stack, unsigned int line_n);
void print_top(stack_t **stack, unsigned int line_n);
void nop(stack_t **stack, unsigned int line_n);
void swap(stack_t **stack, unsigned int line_n);
void add_nodes(stack_t **stack, unsigned int line_n);
void sub_nodes(stack_t **stack, unsigned int line_n);
void div_nod(stack_t **stack, unsigned int line_n);
void mul_nod(stack_t **stack, unsigned int line_n);
void mod_nod(stack_t **stack, unsigned int line_number);
stack_t *New_node(int n);
void free_allocated_nodes(void);
void queue_add(stack_t **new_node, __attribute__((unused))unsigned int line_n);
void access_file(char *file_name);
void scan_file(FILE *file_content);
void match_operation(char *opcode, char *arguments, int line_n, int mode);
int parse(char *BUFFER, int line_n, int mode);
void call_operation(op_func function, char *op, char *arguments, int line_n, int mode);
void error_message_v1(int error_flag, ...);
void error_message_v2(int error_code, ...);
void error_message_v3(int error_flag, ...);

#endif
