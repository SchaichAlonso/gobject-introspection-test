#include <stdlib.h>

#include <girepository.h>

int main (int argsc, char **argsv)
{
    const char *namespace = "Gtk";
    const char *version = "4.0";
    if (argsc == 3) {
        namespace = argsv[1];
        version = argsv[2];
    }
    
    GError *error = NULL;
    GIRepository *repository = g_irepository_get_default ();
    
    g_print("irepository search paths:\n");
    for (GSList *path=g_irepository_get_search_path(); path!=NULL; path=path->next) {
        g_print("  %s\n", (const char *)path->data);
    }
    
    g_irepository_require (repository, namespace, version, 0, &error);
    if (error) {
        g_error ("ERROR: %s\n", error->message);
        return EXIT_FAILURE;
    }
    g_print("Found %s Version=%s in %s\n",
            namespace,
            g_irepository_get_version(repository, namespace),
            g_irepository_get_shared_library(repository, namespace)
    );
    
    return EXIT_SUCCESS;
}
