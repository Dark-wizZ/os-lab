one="one,two,three,four,five,six,seven,eight,nine"
teen="ten,eleven,twelve,thirteen,fourteen,fifteen,sixteen,seventeen,eighteen,nineteen"
ten=" ,twenty,thirty,forty,fifty,sixty,seventy,eighty,ninety"
echo enter any number between 1-9999
read num

if [ $num -gt 9999 ] || [ $num -lt 1 ]
then
echo the number is out of range
exit
fi

if [ $num -ge 1000 ]
then
	thousands=$(($num / 1000))
	echo $one | cut -d"," -f $thousands | tr -d '\n'
	echo -n ' thousand '
	num=$(($num % 1000))
fi
if [ $num -ge 100 ]
then
	hundreds=$(($num / 100))
	echo $one | cut -d"," -f $hundreds | tr -d '\n'
	echo -n ' hundred '
	num=$(($num % 100))
fi
if [ $num -ge 20 ]
then
	tens=$(($num / 10))
	echo $ten | cut -d"," -f $tens | tr -d '\n'
	num=$(($num % 10))
fi
if [ $num -ge 10 ] && [ $num -lt 20 ]
then
	echo '$teen ' | cut -d"," -f $(($num - 9)) | tr -d '\n'
	num=0
fi
if [ $num -gt 0 ]
then
	echo $one |  cut -d"," -f $num | tr -d '\n'
fi
echo
