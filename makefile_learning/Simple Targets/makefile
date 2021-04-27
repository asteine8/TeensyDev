# Define all targets that are not files. If this is not done and a file with the same name is present, the file will be called rather than the target
.PHONY := all say_hello create_text_files clean

# Create Target 'all'. The FIRST target in a makefile is the one that is executed with no arguments
all: say_hello create_text_files

say_hello:
	@echo "Well, hello there"

create_text_files:
	@echo "Creating text files"
	@echo "asdkfhsdfkjg" > file1.txt
	@echo "asdkfhsdfkjg" > file2.txt
	@echo "asdkfhsdfkjg" > file3.txt

clean:
	@echo "Deleting all text files"
	@rm *.txt