#!/bin/bash

# Commonly used commands with this file:
# bash --version
# cat eg_ifelse.sh
# bash eg_ifelse.sh

age=0  # initialize a variable age to 0
# Provide instruction and ask for user input
echo -n 'Pleaes enter your age: '
read age
# alternative: read -p "Please enter your age: " age
# Ouput to terminal
printf 'You claimed to be %d years old.\n' $age

# Determine the range of age
if [ ${age} -lt 18 ]; then
    echo 'You are under 18 years old.'
elif [ ${age} -eq 20 ]; then
    echo 'You may get popcorn because you are 20.'
else
    echo 'You may proceed.'
    exit 1
fi

echo 'This line may not be executed.'

# -gt (greater than) >
# -ge (greater or equal to) >=
# lt (less than) <
# -le (less than or equal to) <=
# -eq (equal to) ` = ` eg. if [ "$password" = "admin"]; then ...
# -nq (not equal to) !=