#!/bin/bash

echo "Showing all the formatting differences..."

find . -name '*.c' -o -name '*.cpp' -o -name '*.h' -o -name '*.hpp' | grep -v -E '(build/|cmake-build-|\.git/)' | while read file; do
    if [ -f "$file" ]; then
        original=$(cat "$file")
        formatted=$(clang-format-18 -style=file "$file")
        
        if [ "$original" != "$formatted" ]; then
            echo "File: $file"
            echo "Requires formatting:"
            diff -u --color=always "$file" <(echo "$formatted") | head -20
            echo "---"
        fi
    fi
done
