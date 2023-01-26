
ARG="1 4 3 2" 
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG

ARG="1 2 4 3" 
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG

ARG="1 4 2 3" 
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG

ARG="1 3 2 4" 
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG

ARG="2 1 3 4" 
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG

ARG="2 1 3 4" 
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG

ARG="2 1 3 4" 
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG

ARG="3 4 1 2" 
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG

ARG="3 1 2 4" 
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG

ARG="3 1 4 2" 
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG

ARG="3 2 4 1" 
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG

ARG="4 1 3 2" 
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG

ARG="4 2 1 3" 
echo $ARG
./push_swap $ARG | ./checker_Mac $ARG

ARG="1 2 3 4" 
echo $ARG "(Already sorted)"
./push_swap $ARG | ./checker_Mac $ARG
