#include "main.h"
/**
 * get_precision -  function that gets the precision from the format string
 * @s:  the format string parameter
 * @params: the parameters struct
 * @ap: paramater for the argument pointer
 * Return: new pointer
*/
char *get_precision(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s != '.')
		return (s);

	s++; /* Move past the period '.' */

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++; /* Move past the asterisk '*' */
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}

	params->precision = d;
	return (s);
}
