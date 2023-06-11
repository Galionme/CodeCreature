#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHAR_AMOUNT 2

typedef struct {
  char name;
  char *keys[4];
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
  ptr[0].keys[3] = "double";
  ptr[0].reward = 0.01;
  ptr[0].inflation = 0.1;
  ptr[1].name = 'B';
  ptr[1].keys[0] = "strlen";
  ptr[1].keys[1] = "strcmp";
  ptr[1].keys[2] = "strcat";
  ptr[1].keys[3] = "strstr";
  ptr[1].reward = 0.1;
  ptr[1].inflation = 0.5;
}

void fileReader(DNA_CHAR *ptr) {
  FILE *fp;
  char *str = NULL;
  char *word = NULL;
  char fileName[255];
  float *score_arr = calloc(100, sizeof(float));
  float *score_start = score_arr;
  float *score_end = score_arr + 100;
  *score_arr = 1;
  for (; score_arr < score_end; score_arr++) {
    *score_arr = 1;
  }

  for (; score_start < score_end; score_start++) {
    printf("%f ", *score_start);
  }
  size_t getline_point = 0, read;
  float score = 0;
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
      for (int i = 0; i < strlen(word) + 1; i++) {
        if (word[i] == '\n') {
          word[i] = '\0';
        }
      }
      if (word[0] != '\0') {
        for (int i = 0; i < 4; i++) {
          if (strstr(word, ptr[1].keys[i]) != NULL) {
            printf("%s - %s\n", word, ptr[1].keys[i]);
          }
        }
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 4; j++) {
            if (strcmp(word, ptr[i].keys[j]) == 0) {
              printf("%s\n", word);
            }
          }
        }
      }
      word = strtok(NULL, " ");
    }
  }
  printf("your score\n");
  // for (int i = 0; i < 100; i++) {
  //   printf("%.2f ", score_arr[i]);
  // }
  free(str);
  free(score_arr);
  fclose(fp);
}
