echo "PROCESS ERROR CHECK\n"

echo '\nTest ./push_swap.c :'
./push_swap

#echo '\nTest ./push_swap.c 1 2 3 5 4 :'
#./push_swap 1 2 3 5 4

echo '\nTest ./push_swap.c 1 1 3 5 4 :'
./push_swap 1 1 3 5 4

echo '\nTest ./push_swap.c 1 21474836478 3 5 4 :'
./push_swap 1 21474836478 3 5 4

echo '\nTest ./push_swap.c 1 214 one 3 5 4 :'
./push_swap 1 214 one 3 5 4

echo '\nTest ./push_swap.c "" :'
./push_swap ""

echo '\nTest ./push_swap.c 1 214 one 3 5 4 4 214748364788 :'
./push_swap 1 214 one 3 5 4 4 214748364788

#echo '\nTest ./push_swap.c "1 2 3 5 4" :'
#./push_swap "1 2 3 5 4"

echo '\nTest ./push_swap.c "1 1 3 5 4" :'
./push_swap "1 1 3 5 4"

echo '\nTest ./push_swap.c "1 21474836478 3 5 4" :'
./push_swap "1 21474836478 3 5 4"

echo '\nTest ./push_swap.c "1 214 one 3 5 4" :'
./push_swap "1 214 one 3 5 4"

echo '\nTest ./push_swap.c "1 214 one 3 5 4" :'
./push_swap "1 214 one 3 5 4"

echo '\nTest ./push_swap.c "1 214 one 3 5 4 4 214748364788" :'
./push_swap "1 214 one 3 5 4 4 214748364788"

echo '\nTest ARG="4 67 3 87 23";./push_swap $ARG" :'
ARG="4 67 3 87 23 0"; ./push_swap $ARG