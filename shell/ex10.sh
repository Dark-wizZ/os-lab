clear
echo enter the number
read n
c=1
s=1
while [ $c -le $n ]
do
echo time $c
s=`expr $s \* $c`
c=`expr $c \+ 1`
done
echo the factorial is $s
