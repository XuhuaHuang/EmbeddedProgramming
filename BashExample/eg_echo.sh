#!/bin/bash

# Commonly used commands with this file:
# bash --version
# cat eg_echo.sh
# bash eg_echo.sh

echo 'Executing file: '$0

echo Hello, world

# To get rid of the automatically inserted \n with -n flag
echo -n 'Hello, world'

# printf in Bash
echo  # add a termination charater to compensate previous -n flag
printf '%s = %d\n' 'Line' $LINES

# - sign forces to allign to the left
printf '%-10.10s = %5.3f\n' 'Const PI' 3.14159265359
# without -sign, alligns to the right
printf '%10.10s = %5.3f\n' 'Const PI' 3.14159265359