clear
echo enter the number
read a
x=$(($a%2))
if [ $x -eq 0 ]
then
	echo $a is even
else
	echo $a is odd
fi
