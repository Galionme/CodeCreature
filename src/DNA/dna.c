#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHAR_AMOUNT 2

typedef struct {
  char name;
  char *keys[3];
  double reward;
  double inflation;
} DNA_CHAR;

void fillStruct(DNA_CHAR *ptr);
void fileReader(DNA_CHAR *ptr);

int main(void) {
  DNA_CHAR dnaChars[CHAR_AMOUNT];
  DNA_CHAR *ptr = dnaChars;
  fillStruct(ptr);
  fileReader(ptr);
  return 0;
}

void fillStruct(DNA_CHAR *ptr) {
  ptr[0].name = 'A';
  ptr[0].keys[0] = "int";
  ptr[0].keys[1] = "char";
  ptr[0].keys[2] = "float";
  ptr[0].reward = 0.01;
  ptr[0].inflation = 0.1;
  ptr[1].name = 'B';
  ptr[1].keys[0] = "strlen";
  ptr[1].keys[1] = "strcmp";
  ptr[1].keys[2] = "strcat";
  ptr[1].reward = 0.1;
  ptr[1].inflation = 0.5;
}

void fileReader(DNA_CHAR *ptr) {
  FILE *fp;
  char *str = NULL;
  char *word = NULL;
  char fileName[255];
  size_t getline_point = 0, read;
  printf("Enter file name: ");
  scanf("%s", fileName);
  if (strlen(fileName) > 255) {
    puts("too long filename"); // создать папку лок для тектстовых выводов
    exit(EXIT_FAILURE);
  }
  fflush(stdin);
  fp = fopen(fileName, "r");
  if (fp == NULL) {
    puts("Error opening file");
    exit(EXIT_FAILURE);
  }
  while ((read = getline(&str, &getline_point, fp)) != (unsigned long int)EOF) {
    word = strtok(str, " ");
    while (word != NULL) {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
          if (strcmp(word, ptr[i].keys[j]) == 0) {
            printf("%s\n", ptr[i].keys[j]);
          }
        }
      }
      word = strtok(NULL, " ");
    }
  }
  free(str);
  fclose(fp);
}
