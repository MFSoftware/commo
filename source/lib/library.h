#ifndef LIB_LIBRARY_H
#define LIB_LIBRARY_H

void commo_init(void);
int commo_convert_file(char* input, char* output);
char* commo_get_contents(char* filename);
void commo_about(void);
char* commo_convert_line(char* line);
void commo_get_token(void);
int commo_file_exists(char* filename);
int commo_put_contents(char* filename);

#endif