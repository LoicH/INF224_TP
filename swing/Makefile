

MAIN = MainWindow

all: ${MAIN}.class
	
	
${MAIN}.class: ${MAIN}.java
	javac $^
	
run: ${MAIN}.class
	java ${MAIN}

run-only:
	java ${MAIN}
