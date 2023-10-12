#ifndef PARENT_PATH_H
#define PARENT_PATH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim_quotes(char* str);
void parent_path(char *filepath, const char *doc_root, char *result);

#endif /* PARENT_PATH_H */