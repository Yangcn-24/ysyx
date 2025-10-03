test_cases=(
    "print_a_message" "hello there"
    "uppercase" "hello there"
    "lowercase" "HELLO tHeRe"
    "fail_on_purpose" "i fail"
    "fail_on_purpose" ""
    "adfasfasdf" "asdfadff"
    "adfasfasdf" "asdfadfas"
)
for ((j=0; j < ${#test_cases[@]}; j+=2))
do
    command=${test_cases[j]}
    argument=\"${test_cases[j+1]}\"
    echo $command $argument
done
