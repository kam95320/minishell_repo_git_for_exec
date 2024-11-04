CFLAGS = -I.
MAKEFLAGS += --silent
CC=cc -Wall -Wextra -Werror -g3 -lreadline

.PHONY: BUILD TEST RUN  BUILD_RUN  # Main piplines
.PHONY: RUNTEST  MERGETEST cleantest clean

build_folder = build
testbuild =  test/build
src_folder = src
outfile_name = minishell
outfile = $(build_folder)/$(outfile_name)

green=`tput setaf 2; tput bold`
mag = `tput setaf 5; `
reset=`tput sgr0`


SRC_GENERAL = ./src/*.c ./src/**/*.c  ./src/**/**/*.c ./src/**/**/**/*.c


BUILD: 
	mkdir -p  $(build_folder)
	$(CC) -o $(build_folder)/minishell $(SRC_GENERAL) 
	echo "$(green)Built and deploy at $ \(mag) $(build_folder)/$(outfile)$(reset)";


bonus : BONUS

MERGETEST:
	mkdir -p test_TEMP 
	mkdir -p $(testbuild) 
	cp -R src/* test_TEMP 
	cp  \-R ./.test/* test_TEMP
	rm test_TEMP/main.c

GCOV: MERGETEST  
	gcc -g3 -fprofile-arcs -ftest-coverage -O0 -o $(testbuild)/test.out test_TEMP/**/*.c test_TEMP/**/**/*.c test_TEMP/**/**/**/*.c test_TEMP/*.c
	./$(testbuild)/test.out 

RUNTEST: MERGETEST  
	gcc -g3 -o $(testbuild)/test.out test_TEMP/**/*.c test_TEMP/**/**/*.c test_TEMP/**/**/**/*.c test_TEMP/*.c
	./$(testbuild)/test.out 

TEST: MERGETEST RUNTEST cleantest

TEST_COVERAGE: MERGETEST GCOV

RUN:
	echo "$(green)Run $(mag) $(outfile)$(reset)"
	./$(outfile)

clean: 
	mkdir -p tmp_ && mv $(outfile) tmp_  
	rm -r $(build_folder)/*
	mv tmp_/* $(build_folder) && rm -r tmp_   

cleantest:
	rm -r test_TEMP

LEAK: TEST
	valgrind --leak-check=full --show-leak-kinds=all --verbose ./test/build/test.out

re: clean BUILD