

MAIN = Main

SOURCES := WindowManager.java Client.java
SOURCES += ${MAIN}.java

CLASSFILES = ${SOURCES:%.java=%.class}



all: ${MAIN}.class
	
${CLASSFILES}: %.class: %.java
	javac $^
	
run: ${MAIN}.class
	java ${MAIN}
	
clean:
	@#bit lazy, some files create more than one .class
	rm -f *.class 
