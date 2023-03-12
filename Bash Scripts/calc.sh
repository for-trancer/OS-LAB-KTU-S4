echo "Select The Operation 1)Addition 2)Subtraction 3)Division 4)Multiplication"
read mode
echo "Enter The Operands :"
read a
read b

case $mode
in
1) ((result=a+b))
;;
2) ((result=a-b))
;;
3) ((result=a/b))
;;
4) ((result=a*b))
;;

esac

echo "Result : $result"
