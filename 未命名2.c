#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void countChars(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("文件无法打开\n");
        return;
    }
  
    int charCount = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        charCount++;
    }
  
    fclose(file);
    printf("字符数：%d\n", charCount);
}

void countWords(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("文件无法打开\n");
        return;
    }
  
    int wordCount = 0;
    char ch;
    int inWord = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch) || ch == ',' || ch == EOF) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            wordCount++;
        }
    }
  
    fclose(file);
    printf("单词数：%d\n", wordCount);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("参数错误。\n使用方法: %s -c|-w 文件名\n", argv[0]);
        return 1;
    }
  
    if (strcmp(argv[1], "-c") == 0) {
        countChars(argv[2]);
    } else if (strcmp(argv[1], "-w") == 0) {
        countWords(argv[2]);
    } else {
        printf("无效参数：%s\n使用-c统计字符，使用-w统计单词。\n", argv[1]);
        return 1;
    }
  
    return 0;
}
