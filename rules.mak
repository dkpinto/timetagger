ifdef TOOLCHAIN
	CXX=$(TOOLCHAIN)-g++
	CC=$(TOOLCHAIN)-gcc
	RANLIB=$(TOOLCHAIN)-ranlib
	AR=$(TOOLCHAIN)-ar
	STRIP=$(TOOLCHAIN)-strip
	
	NATIVE_CXX=g++
else
	CXX=g++
	CC=gcc
	RANLIB=ranlib
	AR=ar
	STRIP=strip

	NATIVE_CXX=g++
endif

CFLAGS+=-g -O3 -Wall -std=c++11 -DNDEBUG -D_hypot=hypot 


ifdef WIN32
	CFLAGS+=-DWIN32
	LFLAGS=-lwsock32 -lws2_32 -static -lpthread

	ifdef WITH_PYTHON 
		ifdef WITH_PYTHON35 
			CFLAGS += -I ../build-depends-3.5/include 
			CFLAGS += -I ../build-depends-3.5/include/python-3.5
		
			PYTHON_LIB=_TimeTagger.pyd
			LFLAGS += ../build-depends-3.5/lib/python35.dll -lws2_32 -static-libstdc++ -static-libgcc

		else
			CFLAGS += -I ../build-depends-2.7/include 
			CFLAGS += -I ../build-depends-2.7/include/python-2.7
		
			PYTHON_LIB=_TimeTagger.pyd
			LFLAGS += ../build-depends-2.7/lib/python27.dll -lws2_32 -static-libstdc++ -static-libgcc

		endif
	endif
endif

ifdef WIN64
	CFLAGS+=-DWIN32 -DMS_WIN64
	LFLAGS=-lws2_32 -static -lpthread

	ifdef WITH_PYTHON
		ifdef WITH_PYTHON35
			CFLAGS += -I ../build-depends-3.5/include 
			CFLAGS += -I ../build-depends-3.5/include/python-3.5

			PYTHON_LIB=_TimeTagger.pyd
			LFLAGS += ../build-depends-3.5/lib/python35.dll -lws2_32 -static-libstdc++ -static-libgcc

		else
			CFLAGS += -I ../build-depends-2.7/include 
			CFLAGS += -I ../build-depends-2.7/include/python-2.7
		
			PYTHON_LIB=_TimeTagger.pyd
			LFLAGS += ../build-depends-2.7/lib/python27.dll -lws2_32 -static-libstdc++ -static-libgcc

		endif
	endif
endif


ifdef LINUX
	CFLAGS+=-fPIC -DLINUX 
	LFLAGS+=-ldl -lpthread
	
	ifdef WITH_PYTHON
		CFLAGS += `python-config --includes` -DNPY_NO_DEPRECATED_API=NPY_1_7_API_VERSION
		PYTHON_LIB=_TimeTagger.so
	endif
	
endif

ifdef ANDROID

	CFLAGS += -I$(NDKHOME)/platforms/android-9/arch-arm/usr/include
	CFLAGS += -I$(NDKHOME)/sources/cxx-stl/stlport/stlport

	LFLAGS += -L$(NDKHOME)/platforms/android-9/arch-arm/usr/lib
	LFLAGS += $(NDKHOME)/sources/cxx-stl/stlport/libs/armeabi/libstlport_static.a
endif
