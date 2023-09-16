#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <elf.h>

void elf_check(unsigned char *e_indent);
void data_print(unsigned char *e_indent);
void magic_print(unsigned char *e_indent);
void print_class(unsigned char *e_indent);
void version_print(unsigned char *e_indent);
void elf_close(int elf);
void aBI_print(unsigned char *e_indent);
void os_abi_print(unsigned char *e_indent);
void type_print(unsigned int type_elf, unsigned char *e_indent);
void entry_print(unsigned long int e, unsigned char *e_indent);



void get_magic(Elf64_Ehdr *ehdr, char *fname, int fd);
void get_type(Elf64_Ehdr *ehdr);
void get_entry(Elf64_Ehdr *ehdr);
void get_class(Elf64_Ehdr *ehdr);
void get_magic(Elf64_Ehdr *ehdr, char *fname, int fd);

#endif
