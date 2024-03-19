# Computer-Graphics
Codes for implementing features of computer graphics such as drawing shapes, transformation, different line drawing and polygon drawing algorithms and etc. using header files graphics.h 

1) For graphics.h setup in windows follow the documentations given below:- 

Configuration Steps in WINDOWS for 
Dev C++ :-  https://gamespec.tech/how-to-add-graphics-in-dev-c/
codeblocks:- https://www.codewithc.com/how-to-include-graphics-h-in-codeblocks/
vs code:-  https://code.droidbro.in/2022/04/graphicsh-solution-for-vs.html


2) For graphics.h setup in Ubantu follow the steps given below:- 

STEP 1: First install build-essential by typing
        sudo apt-get install build-essential
        
STEP 2: Install some additional packages by typing
        sudo apt-get install libsdl-image1.2 libsdl-image1.2-dev guile-1.8 \
        guile-1.8-dev libsdl1.2debian libart-2.0-dev libaudiofile-dev \
        libesd0-dev libdirectfb-dev libdirectfb-extra libfreetype6-dev \
        libxext-dev x11proto-xext-dev libfreetype6 libaa1 libaa1-dev \
        libslang2-dev libasound2 libasound2-dev
      
STEP 3: Download libgraph. Now extract the downloaded libgraph-1.0.2.tar.gz file.

STEP 4: Goto extracted folder and run following command
        cd libgraph-1.0.2
        ./configure
        make
        sudo make install
        sudo cp /usr/local/lib/libgraph.* /usr/lib
        ✓ Run the programs with following command:
        gcc *.c -lgraph
        ./a.out

✓ Explore functions of graphics.h library.
