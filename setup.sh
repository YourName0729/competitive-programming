#! /bin/bash

PROGRESS_DIR="in-progress"

case "$1" in
    "try" | "--try" | "-t")
        mkdir -p "$PROGRESS_DIR"
        echo "// https://open.kattis.com/problems/$2" > "$PROGRESS_DIR"/"$2".cpp
        cat template/cpp.cpp >> "$PROGRESS_DIR"/"$2".cpp
        ;;
    "ac" | "--ac" | "-a")
        cp "$PROGRESS_DIR"/"$2".cpp Kattis/"$2".cpp
        rm -f "$PROGRESS_DIR"/"$2".cpp
        ;;
    "compile" | "--compile" | "-c")
        echo "Compile"
        g++ "$PROGRESS_DIR"/"$2".cpp -Wall
        ;;
    *)
        echo "Unknown command"
        ;;
esac