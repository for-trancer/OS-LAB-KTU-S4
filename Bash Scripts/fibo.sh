echo "enter the no of terms"

read n

a=0
b=1
c=a+b
n=n-2
echo $a
echo $b
for((i=1;i<=n;i++)
do
echo $c
a=$b
b=$c
c=$a+$b
done

