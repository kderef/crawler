#include <errno.h>
#include <stdbool.h>
#include <string.h>

// -- util
#define streq(A, B) (strcmp((A), (B)) == 0)

#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "nob.h"

// --- deps
#define PATH_RAYLIB "deps/raylib/"
#define URL_RAYLIB "https://github.com/raysan5/raylib"

/// clone into ./deps/
bool git_clone(const char* url, const char* tag, const char* dest) {
    Cmd cmd = {0};

    cmd_append(&cmd, "git", "clone", url, dest, "--depth=1");

    if (tag) {
        cmd_append(&cmd, "--branch", tag);
    }

    if (!nob_cmd_run_sync(cmd)) {
        nob_log(ERROR, "failed to run git clone.");
        return false;
    }
    
    return true;
}

bool dir_exists(const char* dir) {
    DIR *dp = opendir(dir);

    if (dp) {
        // dir exists
        closedir(dp);
        return true;
    }
    else {
        // NULL
        if (errno != ENOENT) {
            nob_log(ERROR, "Unknown error: %s", strerror(errno));
        }
    }
    return false;
}

int main(int argc, char** argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);

    const char* arg = (argc > 1)? argv[1] : "";

    Cmd cmd = {0};

    // 1 --- building raylib
    if (!dir_exists(PATH_RAYLIB)) {
        nob_log(INFO, "Raylib does not exist, cloning...");

        if (!git_clone(URL_RAYLIB, "5.5", PATH_RAYLIB)) {
            nob_log(ERROR, "failed to clone " URL_RAYLIB);
            return 1;
        }
    }

    // build?
    const char* libraylib = PATH_RAYLIB "src/libraylib.a";
    if (!nob_file_exists(libraylib)) {
        nob_log(INFO, "building raylib...");
        
        nob_cmd_append(&cmd, "make", "-C", PATH_RAYLIB "src/");

        if (!nob_cmd_run_sync_and_reset(&cmd)) {
            nob_log(ERROR, "failed building raylib");
            return 1;
        }
    }

    // build main program
    typedef const char* cfg;

    cfg cc = "gcc";

    cfg main = "src/main.c";
    cfg bin = "bin/crawler";
    
    nob_cmd_append(&cmd, cc, main, "-o", bin);

    // flags
    nob_cmd_append(&cmd,
        "-O3",
        "-Wall",
        "-I" PATH_RAYLIB "src",
        "-L" PATH_RAYLIB "src",
        "-lraylib",
    );

    #if defined(__APPLE__)
        nob_cmd_append(&cmd,
            "-framework", "CoreVideo",
            "-framework", "IOKit",
            "-framework", "Cocoa",
            "-framework", "GLUT",
            "-framework", "OpenGL",
        );
    #endif

    #if defined(_WIN32)
        nob_cmd_append(&cmd,
             "-lopengl32",
             "-lgdi32",
             "-lwinmm",
        );
    #endif


    if (!nob_cmd_run_sync_and_reset(&cmd)) {
        nob_log(ERROR, "failed to build");

        return 1;
    }

    // -- check arg
    if (*arg) {
        if (streq(arg, "run")) {
            nob_cmd_append(&cmd, bin);
            if (!nob_cmd_run_sync_and_reset(&cmd)) {
                nob_log(ERROR, "failed to run %s", bin);
                return 1;
            }
        }

        else {
            nob_log(WARNING, "unknown arg '%s'", arg);
        }
    }


    return 0;
}

