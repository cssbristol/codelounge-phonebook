#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Phonebook is a simple phonebook application. Store pairs of names and numbers and then look them up.
 */

#define NAME_LENGTH 20
#define NUMBER_LENGTH 20
#define PHONEBOOK_LENGTH 100
#define COMMAND_LENGTH 5

/**
 * A single contact, which has a name and phone number.
 */
struct contact {
    char name[NAME_LENGTH];
    char number[NUMBER_LENGTH];
};

typedef struct contact Contact;

/**
 * The phonebook, which stores a number of contacts and keeps track of how many contacts it contains.
 */
struct phonebook {
    int num_contacts;
    Contact contacts[PHONEBOOK_LENGTH];
};

typedef struct phonebook Phonebook;

/**
 * Prompt the user for a name and number, then add them to the phonebook.
 */
void add_contact(Phonebook *p) {
    const int max = NAME_LENGTH + NUMBER_LENGTH + 2;
    char *name = malloc((NAME_LENGTH + 1) * sizeof(char));
    char *number = malloc((NUMBER_LENGTH + 1) * sizeof(char));
    char line[max];
    printf("Enter new contact details:\n");
    printf("Name\tNumber\n");
    fgets(line, max, stdin);
    sscanf(line, "%s %s", name, number);
    Contact new_contact;
    strncpy(new_contact.name, name, sizeof(new_contact.name));
    strncpy(new_contact.number, number, sizeof(new_contact.number));
    p->contacts[p->num_contacts] = new_contact;
    p->num_contacts++;
}

/**
 * Prompt the user for a name, then display any matching records in the phonebook.
 */
void show_contact(Phonebook *p) {
    char *name = malloc(20);
    char line[PHONEBOOK_LENGTH];
    printf("Search for name: ");
    fgets(line, NAME_LENGTH, stdin);
    sscanf(line, "%s", name);
    for (int i = 0; i < p->num_contacts; i++) {
        if (strncmp(p->contacts[i].name, name, NAME_LENGTH) == 0) {
            printf("Name: %s\tNum: %s\n", name, p->contacts[i].number);
            return;
        }
    }
    printf("Contact not found\n");
}

/**
 * Display all records in the phonebook.
 */
void display_phonebook(Phonebook *p) {
    for (int i = 0; i < p->num_contacts; i++) {
        Contact contact = p->contacts[i];
        printf("Name: %s  Num: %s\n", contact.name, contact.number);
    }
}

/**
 * Read commands from the user's input and dispatch to the appropriate functions.
 */
int main() {
    Phonebook p;
    p.num_contacts = 0;

    printf("Welcome to the phone book. You can add or lookup contacts. (A/L).\n");
    char line[COMMAND_LENGTH], command;
    printf("> ");
    fgets(line, COMMAND_LENGTH, stdin);
    while (!feof(stdin)) {
        sscanf(line, "%c", &command);
        if (command == 'A') {
            add_contact(&p);
        } else if (command == 'L') {
            show_contact(&p);
        } else if (command == 'Q') {
            break;
        } else {
            printf("Invalid command. Try A or L.\n");
        }
        printf("> ");
        fgets(line, COMMAND_LENGTH, stdin);
    }
}
