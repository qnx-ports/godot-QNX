# QNX platform port

This folder contains the adaptations to run godot on QNX.
It is based on :
- the SDP7.1 (porting to SDP8 will be done later and should not be a problem) 
- the Godot release 4.4.


## Documentation

### Compiling for QNX

#### Requirements
Compiling for QNX, the following is required:
- [Python 3.8+](https://www.python.org/downloads/macos/).
- [SCons 4.0+](https://scons.org/pages/download.html) build system.
- [QNX SDP 7.1+](https://https://blackberry.qnx.com/) QNX Software Development Platform

For sound support, download:
- com.qnx.qnx800.target.sound.alsa from QNX software center

#### Setting up the build system
- Set the environment variables `QNX_HOST` and  `QNX_TARGET` to point to the appropriate locations in the QNX SDP.
    - The QNX SDP typically contains a `qnxsdp-env.sh` for setting this up. If available, run source on this script inside your QNX SDP installation:
    ```
    source qnxsdp-env.sh
    ```
#### Building the export templates
scons variables on QNX:
- plaform=qnx
- target=template_release | template_debug
- arch=x86_32 | x86_64 | arm32 | arm64
- alsa=true | false
```bash
# The command to build may look like this
scons platform=qnx target=template_release arch=x86_64 alsa=true
```