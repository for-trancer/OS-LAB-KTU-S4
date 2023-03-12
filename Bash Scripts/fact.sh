echo "Enter the Number : "
read n
fact=1
while ((n>0))
do
((fact=fact*n))
((n--))
done

echo "Factorial : $fact"
