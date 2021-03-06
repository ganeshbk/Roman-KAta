

You need the following programs installed on your system:
  -- Autoconf 2.59
  -- Automake 1.9.6
  -- Libtool 1.5.22
  -- Check 0.9.9

Somewhat earlier versions of these programs might work.

Then, do as follows:

$ autoreconf --install
$ ./configure
$ make
$ make check

Don't do "make install" unless you want to install the AddSubRomanNum example.

AddSubRomanNum.c and AddSubRomanNum.h are built as a library.  src/main.c:main() is a
client of libAddSubRomanNum.la, just as tests/check_AddSubRomanNum.c:main() is a client
of libAddSubRomanNum.la

To use the autotools example in another project, start with the following
files:

   example
   |--- configure.ac
   |--- Makefile.am
   |--- src
   |    |--- Makefile.am
   |--- tests
        |--- Makefile.am

Please send bug reports to check-devel AT lists.sourceforge.net.

========================
CMake:

You need the following programs installed on your system:
  -- CMake 2.8
  -- Check 0.9.9
  -- (pkg-config 0.26 is optional)

Somewhat earlier versions of these programs might work.

NOTE: If pkg-config is not installed on the system, and MSVC is being used,
the install location of Check must be inserted manually into the
tests/CMakeLists.txt file, by setting the variable CHECK_INSTALL_DIR
to the install location. Look at the tests/CMakeLists.txt file for
a commented out example.

Then, do as follows for a Unix-compatible shell:

$ cmake .
$ make
$ make test




or the following for MSVC:

$ cmake -G "NMake Makefiles" .
$ nmake
$ nmake test

Don't do "make install" or "nmake install" unless you want to install the AddSubRomanNum example.

AddSubRomanNum.c and AddSubRomanNum.h are built as a library.  src/main.c:main() is a
client of libAddSubRomanNum.la, just as tests/check_AddSubRomanNum.c:main() is a client
of libAddSubRomanNum.la

To use the CMake example in another project, start with the following files:

   example
   |--- CMakeFiles.txt
   |--- cmake
   |    |--- config.h.in
   |    |--- FindCheck.cmake
   |--- src
   |    |--- CMakeFiles.txt
   |--- tests
        |--- CMakeFiles.txt

