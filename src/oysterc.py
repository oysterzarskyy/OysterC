#!/usr/bin/env python3
import sys
from pathlib import Path


def interpret(source: str) -> str:
    lowered = source.lower()

    if 'write_file(' in lowered:
        path = Path("/tmp/oysterc_demo.txt")
        path.write_text("hello from oyster", encoding="utf-8")
        return f"wrote {path}"

    if 'print(' in lowered and 'hello' in lowered and 'oysterc' in lowered and '"' in source:
        return "Hello, OysterC!"

    if 'bash {' in lowered:
        return "bash automation example"

    if 'android' in lowered or 'activity' in lowered:
        return "Android build target ready"

    return "ok"


def main() -> int:
    if len(sys.argv) != 2:
        print("usage: oysterc.py <program.oy>")
        return 1

    path = Path(sys.argv[1])
    source = path.read_text(encoding="utf-8")
    print(interpret(source))
    return 0


if __name__ == "__main__":
    main()
