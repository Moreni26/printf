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
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
