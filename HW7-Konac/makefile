SRCS		= Tetris.java \
			Tetrominos.java \
			shapes.java


OBJS	= $(SRCS:%.java=%.class)

# FLAGS	= -Wall -Werror -Wextra


all: javadoc 1 2

$(OBJS): $(HEADERS)

compile:
	@echo "\nCompiling..."
	@javac LabelTest.java
	@java LabelTest


clean:
	@echo "\nRemoving compiled files...\n"
	@rm -f */*.class
	@rm -f */*.exe
	@rm -f */*.html
	@rm -f */*.css
	@rm -f */*.js
	@rm -f *.class
	@rm -f *.exe
	@rm -f *.html
	@rm -f *.css
	@rm -f *.js
	@rm -f element-list
	@rm -rf legal
	@rm -rf resources
	@rm -rf script-dir
#	@rm -f *.txt

re: clean compile

2: $(SRCS)
	@echo "\nRunning the Driver2....\n"
	@javac driver2.java 
	@java driver2

1: $(SRCS)
	@echo "\nRunning the Driver2....\n"
	@javac driver1.java 
	@java driver1

javadoc: $(SRCS) driver1.java driver2.java
	@javadoc driver1.java Tetris.java Tetrominos.java

