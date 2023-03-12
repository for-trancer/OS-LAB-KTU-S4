echo "Enter The Number : "
read n

if ((n<2))
then 
echo "Not Prime!"
exit 0
fi

for ((i=2;i<n;i++))
do
if((n%i==0))
then
echo "Not Prime!"
exit 0
fi
done

echo "Prime!" 
