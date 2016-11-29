# pyrtcm

Python wrappers for a subset (RTCM only) of [RTKLIB](https://github.com/tomojitakasu/RTKLIB) C library.

## Installation:

```bash
make all
```

## Usage:

```python
>>> import pyrtcm
>>> rtcm = rtklib.rtcm_t()
>>> pyrtcm.init_rtcm(rtcm)
1
>>> data = open('1004_msg.bin', 'rb').read()
>>> pyrtcm.load_data(data, rtcm)
>>> print(rtcm.msgtype)
RTCM3: type=1004 len=168
```
