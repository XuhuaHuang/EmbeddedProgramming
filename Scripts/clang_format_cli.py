"""
Batch format C/C++ files using clang-format.
"""

import argparse
import subprocess
import pathlib


def is_in_site_packages(path: pathlib.Path) -> bool:
    """
    Check if the given path is in a site-packages directory.

    Args:
        path (pathlib.Path): The path to check for site-packages.

    Returns:
        bool: True if the path is in a site-packages directory, False otherwise.
    """
    # Normalize path parts for cross-platform matching
    lower_parts = [part.lower() for part in path.parts]
    return (
        "site-packages" in lower_parts
        or ("lib" in lower_parts and "python" in "".join(lower_parts))
    )


def is_standalone_source_file(path: pathlib.Path) -> bool:
    """
    Check if the given path is a standalone source file.

    Args:
        path (pathlib.Path): The path to check.

    Returns:
        bool: True if the path is a standalone source file, False otherwise.
    """
    # Heuristics for standalone source file
    if not path.is_file():
        return False
    if path.name.startswith(".") or any(part.startswith(".") for part in path.parts):
        return False  # skip hidden files and folders
    if is_in_site_packages(path):
        return False  # skip virtual environments
    if "build" in path.parts or "out" in path.parts:
        return False  # skip build outputs
    if any(x in path.name.lower() for x in ["build", "lib", "generated", "autogen", "moc_", "ui_"]):
        return False  # skip generated files
    # Assume headers are not standalone sources
    # if path.suffix in [".h", ".hpp"]:
    #     return False
    return True


def find_files(paths: list[pathlib.Path], extensions: set[str]) -> list[pathlib.Path]:
    """
    Find all files in the given paths with the specified extensions.

    Args:
        paths (list[pathlib.Path]): The directories to search for files.
        extensions (set[str]): The file extensions to include in the search.

    Returns:
        list[pathlib.Path]: A list of found files with the specified extensions.
    """
    files: list[pathlib.Path] = []
    for path in paths:
        root = pathlib.Path(path).resolve()
        if not root.exists():
            print(f"⚠️  Warning: Path does not exist: {root}")
            continue
        for f in root.rglob("*"):
            if (
                f.suffix in extensions
                and is_standalone_source_file(f)
            ):
                files.append(f)
    return files


def check_clang_format_config(start_paths: list[str]) -> bool:
    """
    Check if a .clang-format file exists in specified or parent directories.

    Args:
        start_paths (pathlib.Path): The directories to search for .clang-format files.

    Returns:
        bool: True if a .clang-format file is found, False otherwise.
    """
    for path in start_paths:
        dir_path = pathlib.Path(path).resolve()
        for parent in [*dir_path.parents, dir_path]:
            if (parent / ".clang-format").exists():
                return True
    return False


def format_files(files: list[pathlib.Path]) -> None:
    """
    Format the given files using clang-format.
    This function runs clang-format on each file and prints the progress.

    Args:
        files (list[pathlib.Path]): The list of files to format.
    """
    total = len(files)
    for i, file_path in enumerate(files, start=1):
        percent = int((i / total) * 100)
        print(f"[{percent:3}%] Formatting {file_path}")
        try:
            subprocess.run(["clang-format", "-i", str(file_path)], check=True)
        except subprocess.CalledProcessError as e:
            print(f"❌ Failed to format: {file_path}\nError: {e}")


def main():
    """
    Main function to parse command-line arguments and format files.
    """
    parser = argparse.ArgumentParser(
        description="Batch format C/C++ files using clang-format."
    )
    parser.add_argument(
        "paths",
        nargs="*",
        default=["."],
        help="Directories or files to search (default: current directory)",
    )
    parser.add_argument(
        "-e",
        "--extensions",
        nargs="+",
        default=[".cpp", ".cc", ".cxx", ".hpp", ".hh", ".inl", ".h"],
        help="File extensions to include (default: .cpp .cc .cxx .hpp .hh .inl .h)",
    )
    parser.add_argument(
        "--exclude-dirs",
        nargs="+",
        default=[
            ".git", ".svn", ".hg", ".idea", ".vscode",
            ".vs", "__pycache__", "venv", "env",
            "WindowsMLDesktopApp",
            "doctest.hpp",
            "QCustomPlot",
            "build", "out", "x64", "debug", "release",
            "generated", "generated files", "intermediate", "lib", "site-packages"],
        help="List of directory name substrings to exclude (case-insensitive)."
    )

    args = parser.parse_args()

    if not check_clang_format_config(args.paths):
        print("⚠️  Warning: No .clang-format file found in specified or parent directories.\n")

    files = find_files(args.paths, set(args.extensions))

    exclude_dirs = [d.lower() for d in args.exclude_dirs]
    files = [f for f in files if not any(d in f.parts for d in exclude_dirs)]

    if not files:
        print("✅ No files to format.")
        return

    print(f"Found {len(files)} files. Starting clang-format...\n")
    format_files(files)
    print("\n✅ All done.")


if __name__ == "__main__":
    main()
