#!/bin/bash

# Commonly used commands with this file:
# bash --version
# cat eg_math.sh
# bash eg_math.sh

x=10
y=5

echo x=$x, y=$y
echo $x+$y=$((x+y))
echo $x-$y=$((x-y))
echo $x*$y=$((x*y))
echo $x/$y=$((x/y))

x=11
echo  # print a empty line
echo 'New value for x'
echo x=$x, y=$y
# Perform division with Bash and bc
echo 'With Bash:' $((x/y))
echo -n 'With bc and scale set to 2: '
echo "scale=2; $x/$y" | bc

echo
echo -n 'Adding x and y with expression (expr): '
expr $x + $y
let "sum = $x + $y"
echo 'x + y =' $sum