echo "Running tests..."
echo

output=$(./assignment-1)
#expected_output="Hello, World!" #this needs to be changed to the actual value of the energy we want

if [ $? -eq 0 ] ; then
  echo "Pass: Program exited zero"
else
  echo "Fail: Program did not exit zero"
  exit 1
fi

#if [ "$output" == "$expected_output" ] ; then
#  echo "Pass: Output is correct"
#else
#  echo "Expected '$expected_output' but got: $output"
#  exit 1
#fi

echo
echo "Your code compiles!"

exit 0
