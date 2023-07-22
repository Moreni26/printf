#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define OUTPUT_BUFF_SIZE 1024
#define BUFF_FLUSH -1

#define UNUSED(x) (void)(x)
#define FEILD_BUFF_SIZE 50
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define NULL_STRING "(null)"

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#define PARAMS_INT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define S_LONG 2
#define S_SHORT 1

/**
 * struct parameters - parameters struct
 * @unsign: flag if unsigned value
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 * @width: field width specified
 * @precision: field precision specified
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 */

typedef struct parameters {
    unsigned int unsign         : 1;
    unsigned int plus_flag      : 1;
    unsigned int space_flag     : 1;
    unsigned int hashtag_flag   : 1;
    unsigned int zero_flag      : 1;
    unsigned int minus_flag     : 1;
    unsigned int width;
    unsigned int precision;
    unsigned int h_modifier     : 1;
    unsigned int l_modifier     : 1;
} params_t;

/* Function prototypes for printf implementation */
int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int print_hex(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_hexadecimal(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int print_address(va_list ap, params_t *params);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);
void init_params(params_t *params, va_list ap);
int print_reverse(va_list types, char buffer[],int flags, int width int precision, int size);
int handle_write_char(char c, char buffer[],int flags, int width, int precision, int size);
nt write_number(int is_positive, int ind, char buffer[],int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,int width, int flags, char padd, char extra_c, int padd_start);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
void init_params(params_t *params, va_list ap);
char *get_precision(char *p, params_t *params, va_list ap);
#endif /* MAIN_H */
