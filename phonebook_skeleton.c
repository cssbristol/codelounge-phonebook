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
};

typedef struct contact Contact;

/**
 * The phonebook, which stores a number of contacts and keeps track of how many contacts it contains.
 */
struct phonebook {

};

typedef struct phonebook Phonebook;

/**
 * Prompt the user for a name and number, then add them to the phonebook.
 */
void add_contact(Phonebook *p) {


}

/**
 * Prompt the user for a name, then display any matching records in the phonebook.
 */
void show_contact(Phonebook *p) {
}

/**
 * Display all records in the phonebook.
 */
void display_phonebook(Phonebook *p) {
}

/**
 * Read commands from the user's input and dispatch to the appropriate functions.
 */
int main() {
    Phonebook p;
    printf("Welcome to the phone book. You can add or lookup contacts. (A/L).\n");
}
