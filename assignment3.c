/*
 * COMP 2510 - Fall 2026
 * Assignment 3
 *
 * Complete the functions below to build a student-record program.
 * Do not change the provided function names or parameter lists.
 * You may add helper functions if needed.
 *
 * Student Name: Fawaz Shariff
 * Student Number: A01443086
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECORDS 1000
#define INPUT_SIZE 128

typedef struct record record;
struct record {
    char id[10]; 
    int score;
};

/* Task 1: Validate a Student ID */
int isValidID(const char *id)
{
    if (id[0] == 'a' &&  strlen(id) == 8) {
        return 1;
    }
    return 0;
}

/* Task 2: Read One Student Record */
int readStudent(record *student)
{
    /* TODO:
       - Prompt for an ID until it is valid, EOF, or -1.
       - Prompt for a score until it is an integer from 0 to 100,
         EOF, or -1.
       - Only update *student after BOTH fields are valid.
       - Return 1 on success and 0 if the operation is cancelled.
       - Use only the first word of each input line.
       - Print prompts to stdout. */
    return 0;
}

/* Task 3: Display All Student Records */
void displayRecords(const record records[], size_t count)
{
    /* TODO: Print records to stderr, one per line, in the format:
       <record number> <ID> <score>
       Record numbering starts at 1. Print nothing if count is 0. */
}

/* Task 4: Sort Records by Score */
void sortByScore(record records[], size_t count)
{
    /* TODO: Sort the existing records by score in ascending order. */
}

/* Task 5: Sort Records by Student Number */
void sortByStudentNumber(record records[], size_t count)
{
    /* TODO: Sort the existing records by student ID in ascending order. */
}

/* Task 6: Append a Student Record */
void appendRecord(record records[], size_t *count, size_t capacity)
{
    /* TODO: Read a new student and append only if input succeeds.
       Do not write past capacity. */
}

/* Task 7: Modify an Existing Record */
void modifyRecord(record records[], size_t count, size_t recordNumber)
{
    /* TODO:
       - Ignore an out-of-range record number.
       - Display the current record number, ID, and score to stderr.
       - Read replacement data and overwrite ONLY if input succeeds.
       Record numbers start at 1, array indices at 0. */
}

int main(void)
{
    record records[MAX_RECORDS];
    size_t count = 0;
    char input[INPUT_SIZE];
    int command;

    while (1) {
        /* TODO: Print a command prompt to stdout. */

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;  /* EOF exits the program. */
        }

        /* TODO: Read ONLY the first word and convert it to an integer.
           Ignore invalid commands without printing an error. */
        command = 0;  /* Replace with parsed command. */

        if (command == -4) {
            break;
        } else if (command == -3) {
            sortByScore(records, count);
        } else if (command == -2) {
            sortByStudentNumber(records, count);
        } else if (command == -1) {
            appendRecord(records, &count, MAX_RECORDS);
        } else if (command == 0) {
            displayRecords(records, count);
        } else if (command > 0) {
            modifyRecord(records, count, (size_t)command);
        }
        /* Other commands are ignored. */
    }

    return 0;
}
