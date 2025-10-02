echo "Running unit tests:"
library="./build/libex29.so"
function=("print_a_message" "uppercase" "lowercase ")
for i in bin/*_tests
do
	for function in "${function[@]}"
	do
	    if test -f $i
	    then
		if $VALGRIND ./$i $library $function "hello there" 2>> tests/tests.log
		then
		    echo $i PASS
		else
		    echo "ERROR in test $i: here's tests/tests.log"
		    echo "------"
		    tail tests/tests.log
		    exit 1
		fi
	    fi
	done
done

echo ""
