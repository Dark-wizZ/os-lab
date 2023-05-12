clear
echo Enter the string
read s
len=`echo $s | wc -m`
while [ $len -gt 0 ]
do
	echo -n `echo $s | cut -c $len`
	len=$(($len - 1))
done
echo
