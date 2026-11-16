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

#define MAX_RECORDS 1000
#define INPUT_SIZE 128

typedef struct record record;
struct record {
    char id[10]; 
    int score;
};

int scoreSorter(const void *a, const void *b);
int idSorter(const void *a, const void *b);

/* Task 1: Validate a Student ID */
int isValidID(const char *id)
{
    if (id[0] == 'a' &&  strlen(id) == 9) {
        return 1;
    }
    return 0;
}

/* Task 2: Read One Student Record */
int readStudent(record *student)
{
    char line[INPUT_SIZE];
    char word[INPUT_SIZE];
    record temp;

    // Prompt for ID until EOF, valid, or -1
    while (1) {
        printf("Enter student id: ");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            return 0; // EOF
        }
        if (sscanf(line, "%127s", word) != 1) {
            continue; // Blank
        }
        if (strcmp(word, "-1") == 0) {
            return 0; // Cancel prompt
        }
        if (isValidID(word)) {
            strcpy(temp.id, word);
            break; // Valid
        }
    }

    // Prompt for score until EOF, 0-100, or -1
    while (1) {
        printf("Enter student score: ");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            return 0;
        }
        if (sscanf(line, "%127s", word) != 1) {
            continue;
        }
        if (strcmp(word, "-1") == 0) {
            return 0;
        }
        char *end;
        long value = strtol(word, &end, 10);
        if (*end != '\0' && value >= 0 && value <= 100) {
            temp.score = (int)value;
            break;
        }
    }

    *student = temp;
    return 1;
}

/* Task 3: Display All Student Records */
void displayRecords(const record records[], size_t count)
{
    for (size_t i = 0; i < count; i++) {
        fprintf(stderr, "%zu %s %d\n", i + 1, records[i].id, records[i].score);
    }
}

/* Task 4: Sort Records by Score */
void sortByScore(record records[], size_t count)
{
    qsort(records, count, sizeof(record), scoreSorter);
}

int scoreSorter(const void *a, const void *b) {
    record *p = (record *)a;
    record *q = (record *)b;

    return (p->score > q-> score) - (p->score < q-> score);
}

/* Task 5: Sort Records by Student Number */
void sortByStudentNumber(record records[], size_t count)
{
    qsort(records, count, sizeof(record), idSorter);
}

int idSorter(const void *a, const void *b) {
    record *p = (record *)a;
    record *q = (record *)b;

    return strcmp(p->id, q->id);
}

/* Task 6: Append a Student Record */
void appendRecord(record records[], size_t *count, size_t capacity)
{
    if (*count >= capacity) {
        return;
    }
    record temp;
    if (readStudent(&temp) == 1) { // struct assignment copies id and score
        records[*count] = temp;
        (*count)++;
    }
}

/* Task 7: Modify an Existing Record */
void modifyRecord(record records[], size_t count, size_t recordNumber)
{
   if (recordNumber < 1 || recordNumber > count) {
       return; // Out of range
   }
    size_t index = recordNumber - 1;

    fprintf(stderr, "%zu %s %d\n", recordNumber, records[index].id, records[index].score);

    record temp;
    if (readStudent(&temp) == 1) {
        records[index] = temp;
    }
}

int main(void)
{
    record records[MAX_RECORDS];
    size_t count = 0;
    char input[INPUT_SIZE];

    while (1) {
        fprintf(stdout, "Enter command: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;  /* EOF exits the program. */
        }

        int command = atoi(&input[0]);

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
