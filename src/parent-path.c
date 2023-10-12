#include "parent-path.h"

/**
 * @brief Get the parent directory path of a given file path within the document root.
 *
 * This function takes a file path and the document root directory as input and determines
 * the parent directory path of the file within the document root. The result is stored in
 * the provided result string.
 *
 * @param filepath The file path for which to determine the parent directory path.
 * @param doc_root The document root directory.
 * @param result A string to store the resulting parent directory path.
 *
 * @return void
 *
 * @details The function first checks if the file path ends with a "/". If it does, the result
 * string is set to an empty string, indicating that the file path is already a directory path
 * and has no parent directory. If the file path is not within the document root directory,
 * the result string is also set to an empty string, indicating that the file path is outside
 * the scope of the document root. If the above conditions are not met, the function proceeds
 * to extract the directory path of the given file path. It checks if the directory path is the
 * same as the document root directory, and if so, sets the result string to the document root.
 * If the directory path represents a folder or is empty, the result string is set to an empty string.
 * If the directory path is at the same level as the document root directory, the result string
 * is set to the document root. Otherwise, the function goes one level up in the directory hierarchy
 * and stores the parent directory path in the result string.
 *
 * @note This function requires the following include files:
 * @note #include <string.h> // for strlen(), strcmp(), strcpy(), strdup(), strrchr()
 *
 * @note trim quotation mark before using, here is an example:
 * 
 *    // Get the filepath and document root from command line arguments
 *    char* filepath = argv[1];
 *    char* doc_root = argv[2];
 *
 *    // Trim the double quotation marks from filepath and doc_root
 *    trim_quotes(filepath);
 *    trim_quotes(doc_root);
 *
 *    // Create a buffer to store the result
 *    char result[100] = "";
 *
 *    // Call the parent_path function with the filepath, doc_root, and the result buffer
 *    parent_path(filepath, doc_root, result);
 *
 * @see Other functions or resources that are related to this function.
 *
 * @author Cloudgen Wong
 * @date 2023-06-07
 */
void parent_path(char *filepath, const char *doc_root, char *result) {
  // Check if the filepath ends with a "/"
  size_t filepath_length = strlen(filepath);
  if (filepath[filepath_length - 1] == '/') {
    //fprintf(stderr, "  .. >01: '%s', '%s' -> ''\n", filepath, doc_root);
    strcpy(result, "");
    return; 
  }

  // Check if the filepath is within the doc_root directory
  size_t doc_root_length = strlen(doc_root);
  if (strncmp(filepath, doc_root, doc_root_length) != 0) {
    //fprintf(stderr, "  .. >02: '%s', '%s' -> ''\n", filepath, doc_root);
    strcpy(result, "");
    return;
  } 

  // Check if the directory is the doc_root directory
  if (strcmp(filepath, doc_root) == 0) {
    //fprintf(stderr, "  .. >01: '%s', '%s' -> ''\n", filepath, doc_root);
    strcpy(result, "");
    return;
  }

  char *normalized_filepath = realpath(filepath, NULL);
  if (normalized_filepath == NULL) {
    // file not found!
    //fprintf(stderr, "  .. >03: '%s', '%s' -> ''\n", filepath, doc_root);
    strcpy(result, "");
    free(normalized_filepath);
    return;
  }

  // Get the directory path of the given filepath
  char *directory = strdup(normalized_filepath); // Make a copy of the filepath
  char *ptr = strrchr(directory, '/');
  if (ptr != NULL) {
    *ptr = '\0';
  }

  // Check if the directory is the doc_root directory
  if (strcmp(directory, doc_root) == 0) {
    strcpy(result, doc_root);
    free(directory);
    return;
  }

  // Check if the directory represents a folder
  if (strlen(directory) == 0 || directory[strlen(directory) - 1] == '/') {
    //fprintf(stderr, "  .. >01: '%s', '%s' -> ''\n", filepath, doc_root);
    strcpy(result, "");
    free(directory);
    return;
  }

  // Get the parent directory of the doc_root
  char *parent_directory = strdup(doc_root);
  ptr = strrchr(parent_directory, '/');
  if (ptr != NULL) {
    *ptr = '\0';
  }

  // Check if the directory is at the same level as the doc_root directory
  if (strcmp(directory, parent_directory) == 0) {
    strcpy(result, doc_root);
    free(directory);
    free(parent_directory);
    return;
  }

  // Get the parent directory by going one level up
  ptr = strrchr(directory, '/');
  if (ptr != NULL) {
    *ptr = '\0';
  }

  // Store the parent directory in the result
  strcpy(result, directory);

  free(directory); // Free the dynamically allocated memory
  free(parent_directory);
}
