#include "safety_functions.h"
#include <string.h>
#include <sys/stat.h>


short isInt(const char const *str) {
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        if ((str[i] < '0') && (str[i] > '9')) {
            return 0;
        }
    }

    return 1;
}


short pathExists(const char const *path) {
    struct stat stats;
    stat(path, &stats);

    return S_ISDIR(stats.st_mode);
}
