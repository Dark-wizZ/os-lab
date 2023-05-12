clear
fact(){
	f=1
	while [ $x -gt 0 ]
	do
		f=$(($f*$x))
		x=$(($x-1))
	done
}
echo enter n value
read n
echo enter r value
read r
x=$n
fact
nf=$f
x=$r
fact
rf=$f
nr=$(($n-$r))
x=$nr
fact
nrf=$f
res=$(($rf*$nrf))
res=$(($nf/$res))
echo the combo is $res
