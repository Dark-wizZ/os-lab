clear
fact(){
s=1
c=1
while [ $c -le $x ]
do
s=`expr $s \* $c`
c=`expr $c \+ 1`
done
}
echo enter the N value
read n
echo enter the R value
read r
x=$n
fact
nf=$s
x=$r
fact
rf=$s
x=`expr $n \- $r`
fact
nrf=$s
res=`expr $rf \* $nrf`
res=`expr $nf \/ $res`
echo result = $res
