#! /bin/bash

case "$1" in
    "try")
        cp template/cpp.cpp in-progress/"$2".cpp
        ;;
    "ac")
        echo "// https://open.kattis.com/problems/$2" > Kattis/"$2".cpp
        cat in-progress/"$2".cpp >> Kattis/"$2".cpp
        rm -f in-progress/"$2".cpp
        ;;
    *)
        ;;
esac