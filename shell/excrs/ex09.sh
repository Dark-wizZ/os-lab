clear
echo enter the year
read year
r=`expr $year % 4`
if [ $r -eq 0 ]
then
echo $year is leap year
else
echo $year is not leap year
fi
