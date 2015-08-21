

cl:
	@echo "All source(h & c & cpp) line:"	
	@find ./ -type f -regex ".*\.\(cpp\|c\|h\)" -exec cat {} \; | wc -l

cf: 
	@echo "All source(h & c & cpp) file:"
	@find ./ -type f -regex ".*\.\(cpp\|c\|h\)" | wc -l

.PHONY: clean

clean:
	@find . -type f -name "*.~" -exec rm {} \;
	@find . -type f -name "a.out" -exec rm {} \;
