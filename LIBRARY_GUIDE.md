# OysterC Library Creation Guide

## Goals
Create reusable OysterC libraries that are easy to discover, document, and integrate with the C-based runtime.

## Library Layout
Place libraries under the root library tree:
- library/oyster/libs/...
- library/libs/...

## Recommended Structure
Each library should include:
1. A source file such as `oysterc-ui.c`
2. A small README or notes file
3. A simple example program
4. A short API description

## Naming
- Use lowercase names
- Prefer `oysterc-` prefixes for OysterC-native modules
- Keep C-style function names such as `oyster_ui_render`

## Integration
Libraries should expose simple C-compatible entry points so the OysterC runtime can call them directly.

## Example
```c
#include <stdio.h>

void oyster_ui_render(const char *title) {
    printf("render:%s\n", title);
}
```
