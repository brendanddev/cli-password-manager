
#ifndef PASSWORD_H
#define PASSWORD_H

#include <stdbool.h>


bool add_password(char *input);
bool view_password(char *type);

char* normalize_str(char *str);
void print_str(char *str);

#endif 