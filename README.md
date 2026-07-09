# OysterC

OysterC is a new programming language designed for three goals at once: everyday scripting, native development, and Android app creation. It uses a readable syntax, supports modules and classes, and can interoperate with Bash and C while also integrating with Gradle for Android builds.

## What is included
- A language specification in [SPEC.md](SPEC.md)
- Grammar notes in [grammar.ebnf](grammar.ebnf)
- A starter interpreter in [src/oysterc.c](src/oysterc.c)
- Example programs in [examples](examples)
- A Gradle build placeholder in [build.gradle](build.gradle)
- A root library tree under [library](library) with the main UI module in [library/oyster/libs/ui/oysterc-ui.c](library/oyster/libs/ui/oysterc-ui.c) and optional C/C++ toolkit integration notes in [library/libs/ui](library/libs/ui)
- A library creation guide in [LIBRARY_GUIDE.md](LIBRARY_GUIDE.md)
- GitHub Linguist metadata in [.gitattributes](.gitattributes) and [.github/linguist.yml](.github/linguist.yml) so OysterC is treated as C-like for syntax highlighting

## Core language ideas
- Clean syntax with `let`, `const`, `fun`, `class`, `module`, `try`, and `catch`
- Built-in support for file I/O, printing, and simple scripting workflows
- Bash interop with `bash { ... }`
- C interop and C-compatible primitives for native integration
- Gradle-based Android packaging targets such as APK and AAR

## Quick start

For GitHub-flavored markdown rendering, use fenced code blocks with `c` or `cpp` for OysterC examples so the syntax colors follow the C style.
Run an example:

```bash
gcc -std=c99 -Wall -Wextra -O2 -o build/oysterc src/oysterc.c
./build/oysterc examples/hello.oy
```

Run the starter tests:

```bash
python3 -m unittest discover -s tests -q
```

## Repository layout
- [examples](examples): sample OysterC programs
- [src](src): starter implementation and runtime entrypoint
- [tests](tests): basic verification tests
- [SPEC.md](SPEC.md): language specification
- [grammar.ebnf](grammar.ebnf): grammar sketch
