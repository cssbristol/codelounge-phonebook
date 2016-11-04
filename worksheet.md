## Phonebook

This project is a simple C implementation of a rudimentary phonebook.

This project aims to help you use structs whilst programming and understanding I/O operations in C.

You will be able to add contacts to your phonebook with given numbers and then search for the numbers given the contact name. Lastly you'll be able to export your phonebook to a file.  If you finish all of that and still want to carry on we'll have a few optional extras.

We've given you a skeleton project with very few things filled in apart from some essentials. This project isn't too far beyond the scope of your abilities so it'll be fairly hands off from here on out.

To start I would recommend implementing the `phonebook` and `contact`structs you will be using for the rest of the project.

If you're having trouble implementing the code, grab a friend or a helper and get cracking.

### Extensions
If you've implemented the phonebook no problem why not try to look up some ciphers and write some code to keep your contacts safe.

### Some Useful Functions.

`strncpy(char *destination, const char *source, size_tn num)`

Copies the first num characters of source to destination. If the end of the source C string (which is signaled by a null-character) is found before num characters have been copied, destination is padded with zeros until a total of num characters have been written to it.

`fgets(char *str, int n, FILE *stream)`

reads a line from the file stream and stores it into the string str. It stops when either (n-1) characters are read, the newline character is read, or the end-of-file is reached, whichever comes first.

`sscanf(const char *str, const char *format, ...)`
