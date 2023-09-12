OS 				:= $(shell uname -s)
CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra -pedantic -Iinclude/
DEBUG 			= -g
LDFLAGS 		:= $(if $(filter Linux, $(OS)),$(shell pkg-config --libs check),-lcheck)

project_name 	= template_func
func_dir 		= include
test_dir 		= .

lib_name 		:= $(addsuffix .a, $(project_name))
test_lib_name	:= $(addprefix  $(test_dir)/, $(addsuffix _test.a, $(project_name)))
dirs_for_obj	:= $(func_dir) $(test_dir)
obj_list 		:= $(patsubst %.c, %.o, $(wildcard $(addsuffix /*.c, $(dirs_for_obj))))

all: $(lib_name)

# Временной решение для такого чтобы подряд тестить функции на valgrind
.PHONY: test
test: $(test_lib_name) $(lib_name) 
	$(CC) -o $@ -pipe -L. $(addprefix -l:, $^) $(LDFLAGS)
	@$(if $(filter valgrind, $(val)), $(val) --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all --track-origins=yes -s) ./$@

$(lib_name): $(filter $(func_dir)/%.o, $(obj_list))
	ar crs $@ $^

$(test_lib_name): $(filter $(test_dir)/%.o, $(obj_list))
	ar csr $@ $?

%.o: %.c
	$(CC) $(CFLAGS) $(if $(filter $(func_dir)/%.c, $^),$(GCOVFLAGS)) $(DEBUG) -c $^ -o $@

valgrind: val = valgrind
valgrind: test

.PHONY: clang-i
clang-i:
	find . -iname '*.h' -o -iname '*.c' | xargs clang-format -i -style=file:materials/linters/.clang-format

.PHONY: clean
clean:
	@rm -rf $(lib_name) $(test_lib_name) test
	@rm -rf $(report_dir)
	@rm -rf $(obj_list) $(addsuffix /*.gcda, $(func_dir)) $(addsuffix /*.gcno, $(func_dir))

.PHONY: clean_gcov
clean_gcov:
	@rm -rf $(report_dir) 
	@rm -rf $(filter $(func_dir)/%.o, $(obj_list)) $(addsuffix /*.gcda, $(func_dir)) $(addsuffix /*.gcno, $(func_dir))

.DEFAULT_GOAL := man
man:
	@fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'

##
##		Pproject's Makefile manual
##
##Usage: make [TARGET]
##Runs GNU Make with the selected TARGET
##Example: make all
##
##Tasrgets:
##Required targets:
##	clean		clean up the created files 
##	test		testing template function	
##	s21_string.a	compiling static lib
##
##Supporting targets:
##	clang-i		style check
##
##Report bugs to: vldhamrik@gmail.com
##Home page: https://github.com/Bloodislav/Template_func_ANSI_C
