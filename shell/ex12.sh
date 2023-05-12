clear
echo enter the no of employee
read n
while [ $n -gt 0 ]
do
	echo enter the name
	read name
	echo enter idno
	read id
	echo enter the total workk time
	read twt
	echo enter the actual work time
	read awt
	echo enter cost per hour
	read cost
	if [ $twt -gt $awt ]
	then
		extratime=$(($twt-$awt))
		extracost=$(($extratime*$cost))
		echo the overtime is $extratime
		echo the extracost is $extracost
	else
		echo no overtime
	fi
	n=$(($n-1))
done

