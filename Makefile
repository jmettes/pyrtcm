%.o: %.c
	cc -c -fPIC $< -o $@

libs/librtklib.a: libs/rtkcmn.o libs/rtcm.o
	ar -rcs $@ $^

pyrtcm.py pyrtcm_wrap.c:
	swig -python pyrtcm.i

pyrtcm_wrap.o: pyrtcm.py pyrtcm_wrap.c
	cc -c `python-config --cflags` -fPIC pyrtcm_wrap.c

_pyrtcm.so: libs/rtkcmn.o libs/rtcm.o pyrtcm.o pyrtcm_wrap.o
	cc -shared `python-config --ldflags` -fPIC pyrtcm.o pyrtcm_wrap.o -o _pyrtcm.so -Llibs -lrtklib

all: libs/rtkcmn.o libs/rtcm.o libs/librtklib.a pyrtcm.py pyrtcm_wrap.c pyrtcm.o pyrtcm_wrap.o _pyrtcm.so

clean:
	rm libs/rtkcmn.o libs/rtcm.o libs/librtklib.a pyrtcm.py pyrtcm_wrap.c pyrtcm.o pyrtcm_wrap.o pyrtcm.pyc _pyrtcm.so

.PHONY: clean all

