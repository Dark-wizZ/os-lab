clear
ones="one,two,three,four,five,six,seven,eight,nine"
tens=" ,twenty,thirty,fourty,fifty,sixty,seventy,eighty,ninenty"
teens="ten,eleven,twelve,thirteen,fourteen,fifteen,sixteen,seventeen,eighteen,nineteen"

echo enter any number between 1-9999
read num
if [ $num -lt 1 ] || [ $num -gt 9999 ]
then
	break
fi
if [ $num -ge 1000 ]
then
	mult=$(($num/1000))
	echo $ones | cut -d',' -f$mult | tr -d '\n'
	echo -n thousand
	num=$(($num%1000))
fi
if [ $num -ge 100 ]
then
	mult=$(($num/100))
	echo $ones | cut -d',' -f$mult | tr -d '\n'
	echo -n  hundred
	num=$(($num%100))
fi
if [ $num -ge 20 ]
then
	mult=$(($num/10))
	echo $tens | cut -d',' -f$mult | tr -d '\n'
	num=$(($num%20))
fi
if [ $num -ge 10 ]
then
	echo $teens | cut -d',' -f$(($mult-9)) | tr -d '\n'
	num=$(($num%10))
fi
if [ $num -gt 0 ]
then
	echo $ones | cut -d',' -f$num | tr -d '\n'
fi
echo
