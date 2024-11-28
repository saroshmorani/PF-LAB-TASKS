#include <stdio.h>

void display_file_with_line_numbers(const char *fname) {
    FILE*file=fopen(fname, "r");
    if (file==NULL) {
        printf("Error: Could not open file %s\n", fname);
        return;
    }

    char line[1024];
    int linenumber=1;

    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", linenumber, line);
        linenumber++;
    }

    fclose(file);
}

int main() {
    char fname[100];

    printf("Enter the file name: ");
    scanf("%s", fname);

    display_file_with_line_numbers(fname);

    return 0;
}
