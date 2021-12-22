#include "tools_common.h"

size_t str_len(char *str)
{
	size_t len;

	len = 0;
	while (*str++)
		++len;
	return (len);
}

char *str_dup(char *str)
{
	char *dup;
	char *tmp;
	char *src;

	dup = malloc(str_len(str) + 1);
	tmp = dup;
	src = (char *)str;
	if (tmp)
	{
		while((*tmp++ = *src++))
			;
	}
	return (void *)(dup);
}

char *str_len_until(char *src, char until)
{
	while(*src)
	{
		if (*src == until)
			break;
		++src;
	}
	if (*src)
		++src;
	return src;
}

char *sub_string(char *begin, char until, char **out)
{
	int		length;
	char	*pin;
	char	*tmp;

	pin = str_len_until(begin, until);
	length = pin - begin;
	*out = 0;
	if (1 < length)
	{
		*out = malloc(length + 1);
		tmp = *out;
		if (tmp)
		{
			while (*begin && *begin != until)
				*tmp++ = *begin++;
			*tmp = 0;
		}
	}
	return begin;
}

size_t str_cmp(char *src, char *cmp)
{
	size_t 	difference;

	difference = 0;
	while (*cmp && *src == *cmp)
	{
		++src;
		++cmp;
	}
	if (*cmp)
		difference = src - cmp;
	return difference;
}
