PYTHON	= python3
SRC	= spammodule.c
TARGET	= DUMMY

.PHONY:		all
all:		$(TARGET)

.PHONY:		$(TARGET)
$(TARGET):	$(SRC)
	$(PYTHON) setup.py build_ext -i	  

.PHONY:		run
run:		$(TARGET)
	$(PYTHON) main.py
	

.PHONY:		clean
clean:
	rm -rf build spam.cpython-38-x86_64-linux-gnu.so
