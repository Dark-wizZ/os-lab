clear
echo "enter the no of names"
read n
echo "enter the names"
if [ -f 'tempfile' ]
then
	rm 'tempfile'
fi
while [ $n -gt 0 ]
do
	read s
	echo $s | cat >> 'tempfile'
	n=$(($n - 1))
done
echo the sorted names:
sort 'tempfile'
