echo "Enter The String : "
read str

len=${#str}
rev=""

for((i=$len-1;i>=0;i--))
do
ch="${str:$i:1}"
rev="$rev$ch"
done 

if [ $rev == $str ]
then
echo "$str is Palindrome!"
else
echo "Not Palindrome!"
fi

