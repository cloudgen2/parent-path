#!/bin/sh

# @author Cloudgen Wong
# @date 2023-10-12
test_main() {

    TARGET="$1"

    # Generate test files under $HOME/

    echo "Get test cases from: '$2'"
    
    # Read test cases from file
    while IFS= read -r line; do
        ID=$(echo $line | cut -d'|' -f1)
        FILEPATH=$HOME/$(echo $line | cut -d'|' -f2)
        DOC_ROOT=$HOME/$(echo $line | cut -d'|' -f3)
        EXPECTED_RESULT=$(echo $line | cut -d'|' -f4)
        if [ ! -z "${EXPECTED_RESULT}" ]; then
            EXPECTED_RESULT="'$HOME/${EXPECTED_RESULT}'"
        else
            EXPECTED_RESULT="''"
        fi
        if [ ! -z "$ID" ]; then
            rm ${RESULT_FILE}
            touch ${RESULT_FILE}

            # Run the compiled binary with the test case
            /bin/sh -c "${TARGET} \"${FILEPATH}\" \"${DOC_ROOT}\" > ${RESULT_FILE}"

            # Compare the result with the expected result
            RESULT=$(cat "${RESULT_FILE}")
            if [ "${RESULT}" = "${EXPECTED_RESULT}" ]; then
                echo "${ID} Test passed: Parent path correctly calculated."
            else
                echo "${ID} Test failed: Parent path calculation incorrect."
                echo "  .. Command : ${TARGET} \"${FILEPATH}\" \"${DOC_ROOT}\" > ${RESULT_FILE}"
                echo "  .. Result  : ${RESULT}"
                echo "  .. Expected: ${EXPECTED_RESULT}"
                exit 1
            fi
        fi
    done < "$2"
    echo "All tests passed!"
}
# Starting
# Read Project settings
source ./project/project.ini

if [ -z "$1" ]; then 
  echo "run by using './build test'"
  echo "  or using 'tests/test.sh ${TARGET} tests/cases/test-cases.txt'"
else 
  # Run test and loading test cases
  if [ -f tests/setup.sh ]; then
    source tests/setup.sh
    test_main "$1" "$2"
    tests/clean.sh
  else
    echo "You are not in the right folder, test case cannot be found!"
  fi
fi