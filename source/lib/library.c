#include "library.h"

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <io.h>

void commo_init(void) {
    printf("Hello, World!\n");
}

int commo_convert_file(char* input, char* output) {
	if (commo_file_exists(input))
	{
		char* source = commo_get_contents(input);
		return 1;
	}
	else
		return 0;
}

char* commo_convert_line(char* line) {
	return "";
}

void commo_parse_source(char* source) {

}

char* commo_get_contents(char* filename) {
	FILE* file;
	fopen_s(&file, filename, "r");
	char* source = "";
	char* str = "";
	while (fgets(str, 1000, file) != NULL)
        strcat_s(source, strlen(source), str);
	fclose(file);
	return source;
}

int commo_put_contents(char* filename) {
	return 0;
}

void commo_get_token(void) {

}

int commo_file_exists(char* filename) {
	FILE* file;
    if (fopen_s(&file, filename, "r")) {
        fclose(file);
        return 1;
    }
    return 0;
}

void commo_about(void) {
	printf("Commo v1\n");
}