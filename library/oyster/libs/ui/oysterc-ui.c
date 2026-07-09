#include <stdio.h>

void oyster_ui_render(const char *title) {
    printf("oysterc-ui:%s\n", title);
}

void oyster_ui_alert(const char *message) {
    printf("alert:%s\n", message);
}
