echo "Enter The Size : "
read n
echo "Enter the Elements : "

for((i=0;i<n;i++))
do
read arr[i]
done

echo "Enter the Element to Search : "
read x

low=0
high=n-1

while((low<high))
do
((mid=(low+high)/2))

if((arr[mid]==x))
then 
echo "$x is found!"
exit 0
fi

if((x<arr[mid]))
then
((high=mid-1))
else
((low=mid+1))
fi

done

echo "$x is not found!"




