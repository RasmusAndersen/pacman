Installation in Windows
------------

**NOTE: you need a very old version of QT5 to build on Windows. It is highly recommended that you use a Unix-based system instead.**
1) Install Dependencies:

Download and install [Cmake for Windows](https://cmake.org/download/) <br/>
Download and install [QT5 for Windows](https://www.qt.io/download-qt-for-application-development) (the open source version is free)  <br/>
Download and install [python3 for Windows](http://docs.python-guide.org/en/latest/starting/install3/win/)<br/>
2) Download the repository:

`git clone git@github.com:RasmusAndersen/pacman.git`

3) Build the Software:

Run Cmake, set the project (pacmanBT) root folder and the desired build folder (your choice). Configure and generate project solution for your favorite IDE (e.g. Visual Studio 13). Then open the solution from your IDE and build the project.

Run in Windows
------------

In a terminal, go to the build directory of the project and then run the following commands:

`cd bt_editor`

`./behavior_tree_editor.exe`

Alternatively, run the executable behavior_tree_editor.exe from File Explorer



Installation in Unix
------------
1) Install Dependencies:

`sudo apt-get install build-essential libgl1-mesa-dev python3-tk qtdeclarative5-dev`

2) Download the repository:

`git clone git@github.com:RasmusAndersen/pacman.git`

3) Build the Software:

Run in a terminal the following commands:

`cd pacman` <br/>
`mkdir -p build` <br/>
`cd build` <br/>
`cmake ..` <br/>
`make`

Run in Unix
------------

Run in a terminal the following commands:

`./behavior_tree_editor`


1. Right Click in the editor to add a node. 
2. Press Play to run the BT.

NOTE: A BT must have the root node. It cannot have loose nodes (non-connected nodes).

Add the following parameters to `./behavior_tree_editor` to change the ghost behaviour and environment layout:

- '-l', '--layout': the LAYOUT_FILE from which to load the map layout, **default=mediumClassic**
    - smallClassic
    - mediumClassic
    - trickyClassic
    - bigTrickyClassic
- '-g', '--ghosts': the ghost agent TYPE in the ghostAgents module to use, **default=RandomGhost**
    - RandomGhost: ghosts moves randomly in all direction
    - ImperfectGhost: ghosts moves randomly, but will slowly converge on your position
    - ChasingGhost: ghosts will move towards you and occasionally move in a random direction
    - PerfectGhost: ghosts will constantly move towards you
- '-k', '--numghosts': The maximum number of ghosts to use, **default=4**
- '-f', '--fixRandomSeed': Fixes the random seed to always play the same game, **default=False**


Run in a Docker container
------------
**NOTE: Docker containers are not intended to run programs with UIs, so you will have to figure out how start the container with UI based on your system.**

Build the docker container

`docker build -t pacman:latest .*`

Run the container

`docker run --rm pacman`
