# Tetris

# Epitech project
<a href="http://www.casimages.com/i/160325020747210105.png.html" target="_blank" title="Capture du 2016-03-25 13:56:48"><img src="http://nsa37.casimages.com/img/2016/03/25/160325020747210105.png" border="0" alt="Capture du 2016-03-25 13:56:48" /></a>

Project in 1 months, in a pair.

Tetris is a programming game created by R.S and me.
The goal is to create the GameBoy version of the game.<br />
<b>Grade</b> : 20/20

# Compile the project

    $ git clone https://github.com/NicolasC27/tetris.git
    $ cd tetris
    $ make
    $ ./tetris

# Commands program

    Usage: ./tetris [options]
    Options:
    --help               Display this help
    -l --level={num}     Start Tetris at level num
    -kl --key-left={K}   Move tetrimino on LEFT with key K
    -kr --key-right={K}  Move tetrimino on RIGHT with key K
    -kt --key-turn={K}   Turn tetrimino with key K
    -kd --key-drop={K}   Set default DROP on key K
    -kq --key-quit={K}   Quit program when press key K
    -kp --key-pause={K}  Pause and restart game when press key K
    --map-size={row,col} Set game size at row, col
    -w --without-next    Hide next tetrimino
    -d --debug           Debug mode

# Customs shapes

You can custom the shapes of tetriminos in the folder "tetriminos". <br />
You can see several examples that I created in the files. <br />
