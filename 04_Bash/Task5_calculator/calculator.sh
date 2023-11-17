#!/bin/bash

while true; do
    read -p "Enter expression (e.g., '3 + 2'): " expression

    # Use 'set' command to split the input into variables
    set -- $expression

    num1=$1
    operator=$2
    num2=$3

    result=$(echo "$num1 $operator $num2" | bc)

    echo "Result: $result"
done
