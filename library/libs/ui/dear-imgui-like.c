#include <stdio.h>
#include <string.h>

void oyster_imgui_begin(const char *title) {
    printf("imgui::begin[%s]\n", title);
}

void oyster_imgui_text(const char *text) {
    printf("imgui::text[%s]\n", text);
}

int oyster_imgui_button(const char *label) {
    printf("imgui::button[%s]\n", label);
    return 1;
}

void oyster_imgui_end(void) {
    printf("imgui::end\n");
}
