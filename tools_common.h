#ifndef TOOLS_COMMON_H
# define TOOLS_COMMON_H
# include "main.h"

int 	str_len(char *str);
char 	*str_dup(char *str);
char 	*str_len_until(char *src, char until);
char 	*sub_string(char *begin, char until, char **out);
size_t 	str_cmp(char *src, char *cmp);

#endif
