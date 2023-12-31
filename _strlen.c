#include <stddef.h>
#include "main.h"

/**
 * _strlen - calculates the length of a string,
 * @string: String whose length to be calculated,
 * Return: length of string.
 */

size_t _strlen(const char *string)
{
    size_t len = 0;

   /* Check for NULL pointer */
    if (string == NULL)
    {
        return (0);
    }

    /* Increment len while the current character is not '\0' */
    while (*string != '\0')
    {
        len++;
        string++;
    }

    return (len);
}
