#!/bin/bash

# Commonly used commands with this file:
# bash --version
# cat eg_case.sh
# bash eg_case.sh

select=10  # change this variable to different value

case $select in
1)
    printf 'The value for select is %d' $select
    ;;
2)
    printf 'The value for select is %d' $select
    ;;
*)
    printf 'Value is neither 1 nor 2: %d' $select
    exit 1
esac