#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/**
 * struct variables - variables
 * @av: command line arguments
 * @buffer: buffer of command
 * @env: environment variables
 * @count: count of commands entered
 * @argv: arguments at opening of shell
 * @status: exit status
 * @commands: commands to execute
 */
typedef struct variables
{
	char **av;
	char *buffer;
	char **env;
	size_t count;
	char **argv;
	int status;
	char **commands;
} vars_t;

/**
 * struct builtins - struct for the builtin functions
 * @name: name of builtin command
 * @f: function for corresponding builtin
 */
typedef struct builtins
{
	char *name;
	void (*f)(vars_t *);
} builtins;

void free_env(char **env);
char **make_env(char **env);

ssize_t _puts(char *str);
char *_strcat(char *strc1, char *strc2);
char *_strdup(char *strtodup);
int _strcmpr(char *strcmp1, char *strcmp2);
unsigned int _strlen(char *str);

void (*checkbuild(vars_t *vars))(vars_t *vars);
void new_exit(vars_t *vars);
void _env(vars_t *vars);
void new_setenv(vars_t *vars);
void new_unsetenv(vars_t *vars);

char **tokenize(char *buffer, char *delimiter);
char **_realloc(char **ptr, size_t *size);
char *new_strtok(char *str, const char *delim);

void add_key(vars_t *vars);
char **find_key(char **env, char *key);
char *add_value(char *key, char *value);
int _atoi(char *str);

void check_for_path(vars_t *vars);
int execute_cwd(vars_t *vars);
int check_for_dir(char *str);
int path_execute(char *command, vars_t *vars);
char *find_path(char **env);

char *_uitoa(unsigned int count);
void print_error(vars_t *vars, char *msg);
void _puts2(char *str);

#endif /* _SHELL_H_ */
