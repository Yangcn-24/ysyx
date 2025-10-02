echo "Running unit tests:"
library="./build/libex29.so"
test_cases=(
    "print_a_message" "hello there"
    "uppercase" "hello there"
    "lowercase" "HELLO tHeRe"
    "fail_on_purpose" "i fail"
    "fail_on_purpose" ""
    "adfasfasdf" "asdfadff"
    "adfasfasdf" "asdfadfas"
)
for i in bin/*_tests
do
    if test -f $i
    then
    	for ((j=0; j < ${#test_cases[@]}; j+=2))
    	do
    		command=${test_cases[j]}
    		argument=${test_cases[j+1]}
    		echo ./$i $library $command $argument
		if $VALGRIND ./$i $library $command "$argument" 2>> tests/tests.log
		then
		    echo $i PASS
		else
		    echo "ERROR in test $i: here's tests/tests.log"
		    echo "------"
		    tail tests/tests.log
		    exit 1
		fi
	done
    fi
done

echo ""
