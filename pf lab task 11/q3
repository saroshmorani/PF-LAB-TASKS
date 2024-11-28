#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *source_file;
    FILE *destination_file;
    char ch;
    source_file = fopen("input.txt", "r");
    
    if (source_file == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }

    destination_file = fopen("uppercase.txt", "w");

    if (destination_file == NULL) {
        printf("Error opening destination file.\n");
        fclose(source_file);
        return 1;
    }

    while ((ch = fgetc(source_file)) != EOF) {
        fputc(toupper(ch), destination_file);
    }

    fclose(source_file);
    fclose(destination_file);

    printf("File copied and converted to uppercase successfully.\n");

    return 0;
}
