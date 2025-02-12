TimeTagger
==========

Building on Linux with a Windows 32/64 bit system build target.


Dependencies (RPM) 
------------------
Dependencies (for RPM based systems) are stored in `requirements_rpm.txt` and can be installed using 

```shell
dnf install $(cat requirements_rpm.txt)
```

Source-tree
-----------
	config.mak			- configuration file for the build process
	backend				- the TimeTagger backend
		doc			- api documentation
	core				- vhdl core of the fpga
	examples			- programming examples
	doc				- latex manual
	timetaggerd			- the timetagger web server daemon
		httpd			- http library
	arm-linux			- linux arm build
	win32				- windows 32 build
		config.mak		- configuration file for the win32 build process
		build-depends		- files needed for cross compiling
		include			- include files for native windows build 
		lib			- libraries generated by vstudio
		vstudio			- native windows build environment
	win64				- windows 64 build
		config.mak		- configuration file for the win32 build process
		build-depends		- files needed for cross compiling
		include			- include files for native windows build 
		lib			- libraries generated by vstudio
	setup				- win 32 and win 64 installer.exe

Make targets:
-------------
    all:			- build backend, timetaggerd and documentation
    clean:			- cleanup sourcetree for clean build
    dist-clean		- tidy sourcetree for repository check-in (see Issues)
    dist:			- collect ditribution files
    install:		- install backend (linux only)

Make options
------------
    I586_LINUX		set, for linux build. on the root level, this should always be set.

    WITH_WIN32		set to use mingw win32 cross compile
    WITH_WIN64		set to use mingw win64 cross compile
    ARM_LINUX:		set for cross compile for ARM. **not tested** 
   
    WITH_PYTHON		set to build python bindings
    WITH_DOXYGEN		set to build documentation files
   
    THREAD_PTHREADS		set to use PTHREAD threading library
    THREAD_BOOST		set to use BOOST threading library

    WITH_EMBEDDED_DOCS 	set to embedd htms/css/image files into the timetaggerd binary

    SOURCE_ROOT		location of source tree for cross compiling 

Output
------
A packaged file in `timetagger/dist/TimeTagger.zip`. This file should (generally) be 
placed under `<Drive>:\\Program Files (x86)\SwabianInstruments\`.

Or optionally, a Windows executable located in `timetagger/setup/TimeTagger-x.x.exe`.
To build a Windows executable:
    Modify `timetagger/setup/timetagger.nsi` to correct Python version (default 2.7)
    Run `make all` in `timetagger/setup`

Python bindings
---------------
By default Python 2 will be used. However, Python 3.5 bindings are also supported. 
Uncomment `WITH_PYTHON35` in the relevant `config.mak` files to enable.


Issues 
------
Compilation tends to fail after running `dist-clean`. This is likely due to the 
system being unable to rebuild an index for the required build. Currently the recommended 
solution is to avoid using `make dist-clean` entirely. Use `make clean` instead.
