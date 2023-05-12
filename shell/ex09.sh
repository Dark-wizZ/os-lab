clear
echo Enter the year
read y
x=$(($y%4))
if [ $x -eq 0 ]
then
	echo $y is a leap year
else
	echo $y is not a leap year
fi
