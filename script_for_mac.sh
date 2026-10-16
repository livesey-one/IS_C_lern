#!/bin/bash

TARGET_DIR="$HOME/Library/Caches"
OUTPUT_FILE="$HOME/Desktop/Caches_Size_Report.txt"
echo " $TARGET_DIR"
du -sh "$TARGET_DIR"/* 2>/dev/null | sort -hr > "$OUTPUT_FILE"
echo "раб стол: $OUTPUT_FILE"
