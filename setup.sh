#! /bin/bash

PROGRESS_DIR="in-progress"

if [ "$2" != "" ]; then
    # If a second parameter is provided, set the variable to that
    problem="$2".cpp
else
    problem=$(ls ./in-progress | head -n 1)
fi

name="${problem%.*}"
# echo "$name"

# echo "Problem is $problem"

case "$1" in
    "try" | "--try" | "-t")
        echo "Try $problem"
        mkdir -p "$PROGRESS_DIR"
        echo "// https://open.kattis.com/problems/$2" > "$PROGRESS_DIR"/"$2".cpp
        cat template/cpp.cpp >> "$PROGRESS_DIR"/"$2".cpp
        ;;
    "ac" | "--ac" | "-a")
        echo "AC $problem"
        cp "$PROGRESS_DIR"/"$problem" Kattis/"$problem"
        rm -f "$PROGRESS_DIR"/"$problem"
        ;;
    "compile" | "--compile" | "-c")
        echo "Compile $problem"
        g++ "$PROGRESS_DIR"/"$problem" -Wall -o ./a.out
        ;;
    "giveup" | "--giveup" | "-g")
        echo "Give up $problem"
        rm -f "$PROGRESS_DIR"/"$problem"
        ;;
    "find" | "--find" | "-f")
        ls --color=always -la ./Kattis | grep "$name"
        ;;
    *)
        echo "Unknown command"
        ;;
esac