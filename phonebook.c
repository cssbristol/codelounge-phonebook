#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Phonebook is a simple phonebook application. Store pairs of names and numbers and then look them up.
 */

struct contact {
    char name[100];
    char number[15];
};

typedef struct contact Contact;

struct phonebook {
    int num_contact;
    Contact contacts[100];
};

typedef struct phonebook Phonebook;

/**
 * Prompt the user for a name and number, then add them to the phonebook.
 */
void add_contact(Phonebook *p) {
    const int max = 100;
    char *name = malloc(20);
    char *number = malloc(20);
    char line[max];
    printf("Name\t Number:\n");
    fgets(line, max, stdin);
    sscanf(line, "%s %s", name, number);
    Contact new_contact;
    strncpy(new_contact.name, name, sizeof(new_contact.name));
    strncpy(new_contact.number, number, sizeof(new_contact.number));
    p->contacts[p->num_contact] = new_contact;
    p->num_contact++;
}

/**
 * Prompt the user for a name, then display any matching records in the phonebook.
 */
void show_contact(Phonebook *p) {
    const int max = 100;
    char *name = malloc(20);
    char line[max];
    printf("Name desired:");
    fgets(line, max, stdin);
    sscanf(line, "%s", name);
    for (int i = 0; i < p->num_contact; i++) {
        if (strcmp(p->contacts[i].name, name) == 0) {
            printf("Name:%s\tNum:%s\n", name, p->contacts[i].number);
            return;
        }
    }
    printf("Contact not found\n");
}

/**
 * Display all records in the phonebook.
 */
void display_phonebook(Phonebook *p) {
    for (int i = 0; i < p->num_contact; i++) {
        Contact contact = p->contacts[i];
        printf("Name: %s  Num: %s\n", contact.name, contact.number);
    }
}

/**
 * Read commands from the user's input and dispatch to the appropriate functions.
 */
int main() {
    Phonebook phonebook;

    printf("Welcome to the phone book. You can add or lookup contacts. (A/L).\n");
    const int max = 10;
    char line[max], command;
    fgets(line, max, stdin);
    while (!feof(stdin)) {
        sscanf(line, "%c", &command);
        if (command == 'A') {
            add_contact(p);
        } else if (command == 'L') {
            show_contact(p);
        } else {
            printf("Non valid input\n");
        }
        printf("Input another command.\n");
        fgets(line, max, stdin);
    }
}
