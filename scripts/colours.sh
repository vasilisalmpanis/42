#!/bin/bash

NONE='\033[0m'

for STYLE in "38;5"; do
    for COLOR in {0..255}; do
        TAG="\033[${STYLE};${COLOR}m"
        STR="${STYLE};${COLOR}"
        echo "${TAG}${STR}${NONE}  "
    done
    echo
done

