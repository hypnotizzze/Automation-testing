# Automation-testing
A filter program (or "transformation program under test") is being developed for the input/output channel according to task 1.

In the case when it is specified that a string is specified before the dot, trim the string, discarding all characters after the dot, if there is no dot, then assume that the string is bounded by a dot.

A word is any sequence of characters limited to spaces, punctuation marks, the beginning or end of a line, unless otherwise specified.

1 or 2 argument lines are expected to be input, separated by a system line feed after each of them, and one result line is expected to be output, also ending with a line feed.

Task 1

A string of characters is given.

The value of the natural number N is entered in digits in the second line.

If N is greater than or equal to half the length of the string, output the string in reverse order from the last character to the first, otherwise swap the N first and N last characters of the given string, while maintaining the relative order (the first character changes to the Nth from the end, the last character – to the Nth from the beginning).

Based on the task, a set of tests is being developed for this program as a "black box" (functional testing), a number is required for each test.

Based on a set of tests, a testing program is developed that calls the transformation program under test, passes it the input data of each of the developed tests, receives the result of the program, based on comparing the result with the expected answer for this text, either the string "Test No. ..." (without quotes) or the string "Test No...." failed (according to the test numbers).

The testing program returns code 0 to the operating system in case of passing all the tests, 1 – in case of not passing part of the tests, 2 – in case of not passing all the tests.

Other error codes can be used to indicate situations where testing is impossible.

An interactive program of the information and reference system based on a binary file of records is being developed with the following features: file creation, viewing the contents of the file, adding, deleting and correcting data, as well as executing queries in accordance with the task, with a console text interface of the "menu" type based on direct input of single-character commands through the standard input stream and input The results are sent to the standard output stream, according to task 2.

In this case, it is allowed, along with the C90 standard, to use the GNU C90+ extensions.

Search for the required data by the key field.

All input/ output is only through input/output streams, the user interface without direct control of the cursor position (for the possibility of redirecting input/ output), while the data output should be visual for a person (a tabular view or a sequence of entries like "field name": "field value" - at the discretion of the student).

When working with strings, the character encoding system adopted in this OS by default for the Russian alphabet in the command interpreter should be used.

It is allowed to use development environments that ensure compatibility of the received source texts with these requirements.

Task 2

A file containing information about the departure of long-distance trains from the Moscow railway station is given: train number, destination station, departure time, travel time, availability of tickets.

Print the train numbers and the time of their departure to a certain city in each time interval.

Get information about the availability of train tickets with a certain number.

Based on the task, a set of tests is being developed for this program as a "black box" (functional testing) – in the form of scripts for the sequence of user input commands and the sequence of expected reactions of the program from start to completion.

A number is required for each test (scenario).

Based on a set of tests, a testing program is developed that calls the test, passes her the input data of each of the developed tests, receives the result of the program, based on comparing the result with the expected answer for this text, either the string "Test No. ..." (without quotes) or the string "Test No. ..." is output to the standard input stream failed.

The testing program returns code 0 to the operating system in case of passing all the tests, 1 – in case of not passing part of the tests, 2 – in case of not passing all the tests.

Other error codes can be used to indicate situations where testing is impossible.

With the help of the developed programs, perform automated testing of these programs before and after the recommended changes with automated preparation of testing reports.

1. Launch of automated testing of the initial version of the main transformation program using the appropriate testing program (the results are redirected to a text file).

2. Changes are made to the main transformation program (while preserving the original from paragraph 1), which should not affect the test results, and automated testing is repeated (the second text file with the results)

3. Changes are made to the main transformation program that has already been corrected once (while preserving the previous version from paragraph 2), which lead to not passing part of the tests, but with the correct completion of testing, and automated testing is repeated (the third text file with the results)

4. Changes are made to the main transformation program that has already been corrected once (while preserving the previous version from paragraph 3), which lead to an emergency termination of the transformation program under test (at what point in time – at your discretion), and automated testing is repeated (the fourth text file with possible results) – but the corresponding testing program itself must shut down the work correctly in this case as well (possibly by returning a different error code).

5. If clauses 1-4 are passed, then the result of automated testing of the main transformation program will be four versions of the source texts of the transformation program under test, the source texts of the corresponding testing program, four files with test results and four descriptions of the testing process indicating the version of the tested program used, the return code of the testing program and the overall test result ("report about automated testing").



1. Launch of automated testing of the initial version of the main reacting program using the appropriate testing program (the results are redirected to a text file).

2. Changes are made to the main reacting program (while preserving the original from paragraph 1), which should not affect the test results, and automated testing is repeated (the second text file with the results).

3. Changes are made to the main reacting program that has already been corrected once (while preserving the previous version from paragraph 2), which lead to not passing part of the tests, but with the correct completion of testing, and automated testing is repeated (the third text file with the results).

4. Changes are made to the main reacting program that has already been corrected once (while preserving the previous version from paragraph 3), which lead to an emergency termination of the tested reacting program (at what point in time – at the discretion of the student), and automated testing is repeated (the fourth text file with possible results) – but the corresponding testing program itself it should shut down the work correctly in this case as well (possibly by returning a different error code).

5. If clauses 1-4 are passed, then the result of automated testing of the main reacting program will be four versions of the source texts of the tested reacting program, the source texts of the corresponding testing program, four files with test results and four descriptions of the testing process indicating the version of the tested program used, the return code of the testing program and the overall test result ("report about automated testing").

Description of the program for testing the transformation program

A program for testing a transformational program takes an integer value as an argument.

If the argument has a value greater than or equal to one, then the program outputs data for testing according to the transmitted number, if the value is negative, then the program accepts the result of the transformation program for error analysis.

The program also tracks the error file to check for emergency closure of the transformation program.

To organize testing, a bash program is used, which organizes I/O redirection between the testing and the program under test.

To start automatic testing, you need to run the program in the console ./first.

After starting the program ./first_1, the result of the work is written to the res1 file

After refactoring the functions of the transformation program under test, the program ./first_2 is started, the result of the work is written to the res1 file.

The contents of the res 2 file contain the same results as the res 1 file.

After changing the string transformation function (skipping the number 0) in the transformation program under test, the program is started ./first_3, the result of the work is written to the res3 file.

A change is made to the transformation program under test, which multiplies the index of the character-by-character string check, which leads to access to an unknown memory area, the program is started ./first_4, the result of the work is written to the res3 file.

Description of the program for testing a responsive program

A program for testing a responsive program takes an integer value as an argument.

If the argument has a value greater than or equal to one, then the program outputs data for testing according to the transmitted number, if the value is negative, then the program accepts the result of the transformation program for error analysis.

The program also tracks the error file to check for emergency closure of the transformation program.

To organize testing, a bash program is used, which organizes I/O redirection between the testing and the program under test.

To start automatic testing, you need to run the program in the console ./second.

After launching the program ./second_1, the result of the work is written to the res1 1 file.

After refactoring the functions of the reacting program under test, the program is started./second_2, the result of the work is written to the res2 file.

The contents of the res 2 file contain the same results as the res 1 file.

After changing the function of adding flight information in the test responsive program, the program starts./second_3, the result of the work is written to the res3 file.

A change is made to the reacting program under test, which multiplies the index of the matrix of deleting an element from the file, which leads to access to an unknown memory area, and the program is started./second_4, the result of the work is written to the res4 file.

Appendix A

The Test1 folder contains the data necessary for task 1.

file_err is an error file where the error number is stored, in case of an emergency termination of the program under test.

Programs first, first_1, first_2, first_3, first_4 are bash programs that build the tested and testing program, as well as perform automated testing.

main.c, main_1.c, main_2.c, main_3.c, main_4.c are the source codes of the program under test.

The nabor file is the data needed for tests, tester.c is the source code of the testing program.


The Test2 folder contains the data necessary for task 2.

file_err is an error file where the error number is stored, in case of an emergency termination of the program under test.

Programs second, second_1, second_2, second_3, second_4 are bash programs that build the tested and testing program, as well as perform automated testing.

bd.c, bd_1.c, bd_2.c, bd_3.c, bd_4.c are the source codes of the program under test.

The files baza1, baza2, baza3 are the data needed for the tests.

Files otv1, otv2, otv3 are files of the expected results of the program.

