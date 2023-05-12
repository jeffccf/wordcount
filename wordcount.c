// Copyright 2023 Jeff Chu

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE *fin;
    int totalline = 0;
    int lines, words, chars;
    int filescount = 0;
    char ch;
    if (argc<=1) {
        fprintf(stderr, "There should be at least one input file.\n");
        exit(1);
    }
    int checkflag = 0;
    char flag;
    for (int i=1; i<argc; i++) {
        if (strlen(argv[i])==2 && argv[i][0]=='-') {
            if (argv[i][1]=='c' || argv[i][1]=='l' ||argv[i][1]=='w') {
                flag=argv[i][1];
                checkflag++;
                break;
            }
        }
    }
    for (int i=1; i<argc; i++) {
        if (strlen(argv[i])==2 && argv[i][0]=='-' && checkflag == 1) {
            if (argv[i][1]=='c' || argv[i][1]=='l' || argv[i][1]=='w') {
                continue;
            }
        }
        if ((fin = fopen(argv[i], "r"))==NULL) {
            fprintf(stderr, "%s will not open. Skipping.\n", argv[i]);
            continue;
        }
        if (ferror(fin)) {
            fprintf(stderr, "fopen failed\n");
            fclose(fin);
            continue;
        }
        filescount++;
        lines = 0;
        words = 0;
        chars = 0;
        char last=' ';
        while ((ch=fgetc(fin)) != EOF) {
            if (ch=='\n') {
                lines++;
                } else if (ch!=' ' && (last==' ' || last=='\n')) {
                    words++;
                }
            last = ch;
            chars += 1;
        }
            totalline += lines;
            if (checkflag == 0) {
                printf(" %d  %d %d %s\n", lines, words, chars, argv[i]);
            } else if (flag=='c') {
                printf("%d\n", chars);
            } else if (flag=='l') {
                printf("%d\n", lines);
            } else if (flag=='w') {
                printf("%d\n", words);
            }
            fclose(fin);
    }
        if (filescount==0) {
            fprintf(stderr, "Usage: ./wordcount requires an input file\n");
            if (checkflag!=0)
                return EXIT_FAILURE;
        } else if (filescount>=2) {
            if (checkflag == 0) {
                printf("Total Lines = %d\n", totalline);
            }
        }
        return EXIT_SUCCESS;
}
