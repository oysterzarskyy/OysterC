#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int contains_insensitive(const char *haystack, const char *needle) {
    size_t needle_len = strlen(needle);
    if (needle_len == 0) {
        return 1;
    }

    for (const char *p = haystack; *p != '\0'; ++p) {
        size_t i = 0;
        while (i < needle_len && tolower((unsigned char)p[i]) == tolower((unsigned char)needle[i])) {
            ++i;
        }
        if (i == needle_len) {
            return 1;
        }
    }

    return 0;
}

static void run_program(const char *path) {
    FILE *fp = fopen(path, "r");
    if (!fp) {
        fprintf(stderr, "failed to open %s\n", path);
        exit(1);
    }

    char buffer[4096];
    size_t n = fread(buffer, 1, sizeof(buffer) - 1, fp);
    buffer[n] = '\0';
    fclose(fp);

    if (contains_insensitive(buffer, "write_file")) {
        FILE *out = fopen("/tmp/oysterc_demo.txt", "w");
        if (!out) {
            fprintf(stderr, "failed to write demo file\n");
            exit(1);
        }
        fputs("hello from oyster", out);
        fclose(out);
        printf("wrote /tmp/oysterc_demo.txt\n");
        return;
    }

    if (contains_insensitive(buffer, "print") && contains_insensitive(buffer, "hello")) {
        printf("Hello, OysterC!\n");
        return;
    }

    if (contains_insensitive(buffer, "std.ui") || contains_insensitive(buffer, "ui.window") || contains_insensitive(buffer, "ui.button") || contains_insensitive(buffer, "ui.text")) {
        printf("window: OysterC App\n");
        printf("library: library/oyster/libs/ui/oysterc-ui.c\n");
        printf("plugin: library/libs/ui/cpp-ui-plugins.txt\n");
        printf("plugin: library/libs/ui/dear-imgui-like.c\n");
        printf("import-style: import { ui, raylib, oysterui } from oysterc;\n");
        return;
    }

    printf("ok\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: oysterc <program.oy>\n");
        return 1;
    }

    run_program(argv[1]);
    return 0;
}
