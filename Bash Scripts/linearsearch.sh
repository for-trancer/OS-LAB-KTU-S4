echo "Enter The Size : "
read n
echo "Enter The Data : "

for((i=0;i<n;i++))
do
read arr[i]
done

echo "Enter the Element to Search : "
read x
index=1

for((i=0;i<n;i++))
do
if((arr[i]==x))
then 
echo "Element $x is found at position $index"
exit 0
fi
((index++))
done

echo "$x is not found!"


