clear
echo enter the source file name
read source
echo enter the destination file name
read dest
cp $source $dest
echo $source copied to $dest
echo $dest:
cat $dest
