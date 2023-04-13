clear
echo read the no of employee
read n
c=0
while [ $c -lt $n ]
do
c=`expr $c \+ 1`
echo enter the name
read name
echo enter the idno
read idno
echo the total work time
read wrktime
echo enter the actual time
read actime
echo enter the cost
read cost
overtime=`expr $wrktime \- $actime`
if [ $overtime -ge 0 ]
then
echo the over time is $overtime
extcost=`expr $overtime \* $cost`
echo the extra cost is $extcost
else
echo no overtime
fi
done
