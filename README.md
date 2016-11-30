# pyrtcm

Python wrappers (using swig) for a subset (RTCM only) of [RTKLIB](https://github.com/tomojitakasu/RTKLIB) C library.

## Installation:

```bash
sudo yum install swig
make all
```

## Usage:

```python
>>> import pyrtcm
>>> rtcm = pyrtcm.rtcm_t()
>>> pyrtcm.init_rtcm(rtcm)
1
>>> data = open('1004_msg.bin', 'rb').read()
>>> pyrtcm.load_data(data, rtcm)
>>> print(rtcm.msgtype)
RTCM3: type=1004 len=168
```
