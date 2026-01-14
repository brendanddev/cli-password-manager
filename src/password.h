
#ifndef PASSWORD_H
#define PASSWORD_H

#include <stdbool.h>


bool add_password(char *input);
bool view_password(char *type, char *out_password);
bool edit_password(char *new_password, char *type);
bool delete_password(char *type);
char* encode(char *raw);

char* normalize_str(char *str);
void print_str(char *str);

#endif 