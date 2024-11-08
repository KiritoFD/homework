#include <stdio.h>
#include <stdlib.h>

const int FILE_NAME_MAX_LEN = 128;
const int STRING_MAX_LEN = 512;
const int MAX_LINE_LEN = 1024;

// Given the name of a text file and a target string, 
// searches for all occurrences of the target string
// in the file.
//
// For each match, it prints the line number and the
// entire line containing the target string.
int main() {
  char file_name[FILE_NAME_MAX_LEN];
  char target_str[STRING_MAX_LEN];
  printf("Enter the file name:");
  gets(file_name);
  printf("Enter the target string:");
  gets(target_str);

  FILE* file_ptr;
  // Open the first file in reading mode
  file_ptr = fopen(file_name, "r");
  if (file_ptr == NULL) {
    printf("file %s can't be opened.\n", file_name);
    return EXIT_FAILURE;
  }

  // Read the file line by line.
  char line[MAX_LINE_LEN];
  int line_num = 0;
  while (fgets(line, MAX_LINE_LEN, file_ptr)) {
    if(strstr(line, target_str)!=NULL) {
      printf("Line %d: %s", line_num, line);
    }
    line_num++;
  }

  fclose(file_ptr);
  return 0;
}
