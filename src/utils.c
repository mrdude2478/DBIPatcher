// Portable mkpath: recursively create directories like `mkdir -p`
#ifdef _WIN32
#include <direct.h>   // _mkdir
#include <io.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#endif

#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>

// Portable mkpath: recursively create directories like `mkdir -p`
// If given a file path, it only creates the parent directory.
int mkpath(int mode, const char *fmt, ...) {
    char fullpath[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(fullpath, sizeof(fullpath), fmt, args);
    va_end(args);

    // --- Work on a copy ---
    char path[1024];
    strncpy(path, fullpath, sizeof(path));
    path[sizeof(path) - 1] = '\0';

    // Strip filename part if there's an extension or final separator
    char *last_sep = strrchr(path, '/');
#ifdef _WIN32
    char *last_sep2 = strrchr(path, '\\');
    if (!last_sep || (last_sep2 && last_sep2 > last_sep)) {
        last_sep = last_sep2;
    }
#endif
    if (last_sep) {
        // If the path doesn't end with a slash, assume it's a file
        if (*(last_sep + 1) != '\0') {
            *last_sep = '\0'; // keep only parent dir
        }
    }

    // If no directory part → nothing to do
    if (strlen(path) == 0) {
        return 0;
    }

    // Walk through and create directories
    char *p = path;
    for (; *p; p++) {
        if (*p == '/' || *p == '\\') {
            char sep = *p;
            *p = '\0';

            if (strlen(path) > 0) {
#ifdef _WIN32
                if (_mkdir(path) != 0 && errno != EEXIST) return -1;
#else
                if (mkdir(path, mode) != 0 && errno != EEXIST) return -1;
#endif
            }

            *p = sep;
        }
    }

    // Final directory
#ifdef _WIN32
    if (_mkdir(path) != 0 && errno != EEXIST) return -1;
#else
    if (mkdir(path, mode) != 0 && errno != EEXIST) return -1;
#endif

    return 0;
}


int mkpath_for_file(int mode, const char *filepath) {
    char buf[1024];
    strncpy(buf, filepath, sizeof(buf));
    buf[sizeof(buf) - 1] = '\0';

    char *last_sep = strrchr(buf, '/');
#ifdef _WIN32
    char *last_sep2 = strrchr(buf, '\\');
    if (!last_sep || (last_sep2 && last_sep2 > last_sep)) {
        last_sep = last_sep2;
    }
#endif
    if (last_sep) {
        *last_sep = '\0'; // cut at last slash → parent dir only
        return mkpath(mode, "%s", buf);
    }

    // No directory part → nothing to do
    return 0;
}