#ifndef _SHELL_MAIN_H_
#define _SHELL_MAIN_H_


#define BUFFER_SIZE 1024
#define MAX_CMD_COUNT 64

/* Header files */
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>
#include <malloc.h>
#include <stddef.h>
#include <ctype.h>



extern char **environ;



/* Prototypes for custom printing functions */
/** prints.c **/
int _putchar(char c);
void our_printf(char *str);



/* Prototypes for utility functions */
/** _getline.c **/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/** string.c **/
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strchr(const char *s, char c);
char *starts_with(const char *haystack, const char *needle);

/** string1.c **/
char *_strdup(char *str);
char *_strncat(char *dest, char *src, int n);
int _atoi(const char *s);
char *_strtok(char *str, const char *delim);
int _delim(char c, const char *delim);

/** string2.c **/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);
int _strncmp(const char *str1, const char *str2, size_t n);



/* Prototypes for helping functions */
/** handle_path.c **/
void cleanup(char **cmd, int count);
void handle_path(char **cmd, int count);



/* Function prototypes */
/** blinking.c **/
void blinking_prompt(void);

/** built_in.c **/
void exit_shell(const char *status);
void handle_cd(const char *dir);

/** executing_user.c **/
void exec_user_input(char *user_input);

/** reads.c **/
void read_user_input(char *user_input, size_t len);

/** prints_environ.c **/
int _setenv(const char *var_name, const char *value, int overwrite);
void print_env(char **environ);
int _unsetenv(const char *var_name);
char *_getenv(const char *nom); /* Prototypes for utility functions */



#endif