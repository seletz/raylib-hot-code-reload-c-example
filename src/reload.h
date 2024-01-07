#ifndef RELOAD_H_
#define RELOAD_H_

typedef struct {
  char *symbol;  // name of the symbol
  void **ptr;    // address to be updated
} symtab_t;

/**
 * Load given dll and rebind symbols found in supplied
 * symbol table.
 */
int reload(char *path, symtab_t *symtab);

#endif // RELOAD_H_
