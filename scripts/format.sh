#!/bin/bash

if [ "$1" == "--check" ]; then
	find . -path ./build -prune -o -type f \( -name '*.c' -o -name '*.h' \) -print0 | xargs -0 clang-format --style=file --dry-run -Werror
elif [ "$1" == "-f" ]; then
	find . -path ./build -prune -o -type f \( -name '*.c' -o -name '*.h' \) -print0 | xargs -0 clang-format --style=file -i
elif [ "$1" == "--tidy" ]; then
	run-clang-tidy -p=build
fi
