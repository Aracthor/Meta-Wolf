COMPIL_ERROR_FILE="compil_error.txt"

error_or_stop=0
keypressed=''

while [ $error_or_stop == 0 ]
do
    # Get window size
    width=$(tput cols)
    height=$(tput lines)

    # Start a compilation step using G++
    g++-7 -Wall -std=c++17 -o renderer main.cpp -DKEYBOARD_INPUT="\"$keypressed\"" -DWINDOW_WIDTH="$width" -DWINDOW_HEIGHT="$height" 2> "$COMPIL_ERROR_FILE"

    # Check for any compilation error
    if [ $? != 0 ]
    then
	cat $COMPIL_ERROR_FILE
	error_or_stop=1
    else
	# Clean the screen.
	clear

	# Obtain the rendering
	echo "R\"(" > game_state.txt
	game_output=$(./renderer 2>> game_state.txt)
	error_or_stop=$?
	echo ")\"" >> game_state.txt

	echo $game_output # Show the rendering to the player

        # Read one key pressed
	if [ $error_or_stop == 0 ]
	then
	    read -rsn1 keypressed
	fi
    fi
done
