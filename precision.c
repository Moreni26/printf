#includ#include "main.h"
#include <ctype.h>

/**
 * get_precision -  function that gets the precision from the format string
 * @format:  the format string parameter
 * @params: the parameters struct
 * @ap: parameter for the argument pointer
 * Return: new pointer
 */

char *get_precision(char *format, params_t *params, va_list ap)
{
    int curr_i = 0; /* Initialize the variable `i`*/
    int precision = -1;

    if (format[curr_i] != '.')
        return (NULL); /* Return NULL instead of precision */

    precision = 0;

    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
        if (isdigit(format[curr_i]))/*Use isdigit from ctype.h*/
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            curr_i++;
            precision = va_arg(ap, int);
            break;
        }
        else
            break;
    }

    /* No need to set `i` as it is not used in this function */

    return (format);
}
