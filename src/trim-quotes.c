#include "trim-quotes.h"

/**
 * @brief Removes surrounding quotes from a given string.
 *
 * This function removes the surrounding quotes from the provided string if they exist.
 * If the string is enclosed within double quotes ("") or single quotes (''),
 * the function modifies the string in-place by removing the first and last characters.
 * The modified string will be properly terminated with a null character ('\0').
 *
 * @param str The string to be processed. It will be modified in-place.
 *
 * @return void
 *
 * @details The function checks if the string has a length of at least 2 and if the first and last characters
 * are either both double quotes (") or both single quotes (''). If the condition is satisfied, the function
 * uses the memmove function to shift the characters in the string one position to the left, effectively
 * removing the first character (quote). Then, it adds a null terminator at the position of the original last
 * character, effectively removing the last character (quote) and ensuring the string is properly terminated.
 *
 * @note This function requires the following include files:
 * @note #include <string.h> // for strlen(), memmove()
 *
 * @author Cloudgen Wong
 * @date 2023-06-10
 */
void trim_quotes(char* str) {
  size_t length = strlen(str);
  if ((length >= 2 && str[0] == '"' && str[length - 1] == '"') || (length >= 2 && str[0] == '\'' && str[length - 1] == '\'')) {
    memmove(str, str + 1, length - 2);
    str[length - 2] = '\0';
  }
}