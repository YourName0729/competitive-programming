#! /bin/bash

case "$1" in
    "try")
        echo "// https://open.kattis.com/problems/$2" > in-progress/"$2".cpp
        cat template/cpp.cpp >> in-progress/"$2".cpp
        ;;
    "ac")
        cp in-progress/"$2".cpp Kattis/"$2".cpp
        rm -f in-progress/"$2".cpp
        ;;
    *)
        ;;
esac