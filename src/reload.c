#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

#include "debug.h"
#include "reload.h"

int reload(char *dll_name, symtab_t *symtab) {
    static void *game_dll = NULL;

    fprintf(stderr, "DLL_NAME: %s\n", dll_name);

    if (game_dll) {
        fprintf(stderr, "CLOSING DLL Handle %p\n", game_dll);
        dlclose(game_dll);
        game_dll = NULL;
    }

    game_dll = dlopen(dll_name, RTLD_LAZY | RTLD_LOCAL);
    if (!game_dll) {
        fprintf(stderr, "ERROR: Could not open shared library %s: %s\n",
                dll_name, dlerror());

        return 1;
    }
    fprintf(stderr, "NEW DLL Handle: %p\n", game_dll);

    while (symtab->symbol) {
        void *sym = dlsym(game_dll, symtab->symbol);
        _DBGP(dbg, sym)
        if (!sym) {
            fprintf(stderr, "ERROR: Caould not open symbol: %s: %s\n",
                    symtab->symbol, dlerror());

            return 2;
        }

        fprintf(stderr, "RELOAD: found symbol %s -> %p\n", symtab->symbol, symtab->ptr);

        *symtab->ptr = sym;
        symtab++;
    }

    return 0;
}
