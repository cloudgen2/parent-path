#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parent-path.h"
#include "trim-quotes.h"

int main(int argc, char* argv[]) {
    // Check if the required arguments are provided
    if (argc < 3) {
        printf("Please provide the filepath and the document root as arguments. Usage:\n   parent-path [FILEPATH] [DOC_ROOT]\n");
        return 1;
    }

    // Get the filepath and document root from command line arguments
    char* filepath = argv[1];
    char* doc_root = argv[2];

    // Trim the double quotation marks from filepath and doc_root
    trim_quotes(filepath);
    trim_quotes(doc_root);

    // Create a buffer to store the result
    char result[100] = "";

    // Call the parent_path function with the filepath, doc_root, and the result buffer
    parent_path(filepath, doc_root, result);

    // Print the result, make sure it's quoted with single quote
    printf("'%s'\n", result);

    return 0;
}
