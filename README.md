# wordcount

In Linux CLI, wc command could count the words in a file.

This program could do the same thing

# Implementation
To implement the program in a Linux environment, use the command gcc -Wall -std=c11 -o wordcount wordcount.c to compile.
To run the program, use the command ./wordcount -"flag" "file1" "file2"...

# Outputs
If no flags entered, the program should output argc+1 lines, for the first argc lines, the output should be

"#lines" "#words" "#chars" nth file,

for example: 80 253 1570 testfile.txt.

If there are more than one input files, the last line should output the total lines of the files

# Flags
There are three options in the program, -l -w -c.

-l option would only output the number of lines

-w option would only output the number of words

-c option would only output the number of characters
