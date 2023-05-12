clear
echo Enter the number
read n
a=1
while [ $n -gt 0 ]
do
	a=$(($a * $n))
	n=$(($n-1))
done
echo The factorial value is $a
