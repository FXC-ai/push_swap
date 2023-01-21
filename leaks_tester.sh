echo "LEAKS CHECK\n"

echo '\nLeaks pour test ./push_swap.c :'
leaks -atExit -- ./push_swap > output.log
cat output.log | grep 'leaks for'

echo '\nLeaks pour test ./push_swap.c 1 2 3 5 4 :'
leaks -atExit -- ./push_swap 1 2 3 5 4 > output.log
cat output.log | grep 'leaks for'

echo '\nLeaks pour test ./push_swap.c 1 1 3 5 4 :'
leaks -atExit -- ./push_swap 1 1 3 5 4 > output.log
cat output.log | grep 'leaks for'

echo '\nLeaks pour test ./push_swap.c 1 21474836478 3 5 4 :'
leaks -atExit -- ./push_swap 1 21474836478 3 5 4 > output.log
cat output.log | grep 'leaks for'

echo '\nLeaks pour test ./push_swap.c 1 214 one 3 5 4 :'
leaks -atExit -- ./push_swap 1 21474836478 3 5 4 > output.log
cat output.log | grep 'leaks for'

echo '\nLeaks pour test ./push_swap.c "" :'
leaks -atExit -- ./push_swap "" > output.log
cat output.log | grep 'leaks for'

echo '\nLeaks pour test ./push_swap.c "1 2 3 5 4" :'
leaks -atExit -- ./push_swap "1 2 3 5 4" > output.log
cat output.log | grep 'leaks for'

echo '\nLeaks pour test ./push_swap.c "1 1 3 5 4" :'
leaks -atExit -- ./push_swap "1 1 3 5 4" > output.log
cat output.log | grep 'leaks for'

echo '\nLeaks pour test ./push_swap.c "1 21474836478 3 5 4" :'
leaks -atExit -- ./push_swap "1 21474836478 3 5 4" > output.log
cat output.log | grep 'leaks for'

echo '\nLeaks pour test ./push_swap.c "1 214 one 3 5 4" :'
leaks -atExit -- ./push_swap "1 21474836478 3 5 4" > output.log
cat output.log | grep 'leaks for'

echo '\nLeaks pour test ARG="4 67 3 87 23"; leaks -atExit -- ./push_swap $ARG" :'
ARG="4 67 3 87 23"; leaks -atExit -- ./push_swap $ARG > output.log
cat output.log | grep 'leaks for'

rm output.log