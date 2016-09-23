# Generic Makefile
CXX = /usr/bin/g++
MAIN = main
OUTPUT_FILENAME = ApricotTest
CPP_FILES = apricotLine.cpp apricotMatrix.cpp apricotVector.cpp
H_FILES = apricotLine.h apricotMatrix.h apricotVector.h
CXXFLAGS = -Wall -std=c++11

# Type 'make' to create the executable
${MAIN}: ${MAIN}.cpp ${H_FILES} ${CPP_FILES}
	${CXX} ${CXXFLAGS} ${MAIN}.cpp ${CPP_FILES} -o ${OUTPUT_FILENAME}
	@echo 'Use ./${OUTPUT_FILENAME} to run'

#type 'style' to check your code style
#style: ../../helpful_files/cpplint.py ${FILE}
#	python $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${H_FILES} ${CPP_FILES}

# Clean-Up the executable
clean:
	rm -rf ${OUTPUT_FILENAME}
