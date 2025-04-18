"""
Locates a Visual Studio style comment block that starts at the beginning of a C++ file
and wrap it around
`// clang format off` and
`// clang format on`
"""

import sys
from pathlib import Path

def wrap_top_box_comment_block(filename: str) -> None:
    """
    Wraps a Visual Studio style comment block around the specified file.

    Args:
        filename (str): File to format.
    """
    path = Path(filename)
    if not path.exists():
        print(f"File '{filename}' does not exist.")
        return

    lines = path.read_text(encoding="utf-8").splitlines()
    output = []

    i = 0
    # Skip any leading blank lines
    while i < len(lines) and lines[i].strip() == "":
        output.append(lines[i])
        i += 1

    # Check if the next line starts with /* to begin a box-style comment
    if i < len(lines) and lines[i].strip().startswith("/*"):
        output.append("// clang-format off")
        while i < len(lines):
            output.append(lines[i])
            if lines[i].strip().endswith("*/"):
                i += 1
                break
            i += 1
        output.append("// clang-format on")

    # Append the rest of the file
    output.extend(lines[i:])

    # Save modified content
    path.write_text("\n".join(output) + "\n", encoding="utf-8")
    print(f"Wrapped top-level box comment in '{filename}'")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python wrap_top_box_comment.py <source_file.cpp>")
    else:
        wrap_top_box_comment_block(sys.argv[1])
