from board import Board
from setup import Setup
#################################################################################
#Connect Four Game
print("----------------------------------------------------------")
print("\t\t\t\t\t Connect Four \t\t\t\t\t\t")
print("----------------------------------------------------------")
if __name__ == '__main__':
	player_setup = Setup()
	
	# game loop
	play_again = 'yes'
	while play_again in Setup.ACCEPTABLE_ANSWERS:
		player_setup.run(True)
		height, width = Board.get_dimensions()
		connect_four_game = Board(player_setup.get_players(), height, width)
		connect_four_game.play()
		play_again = str(input("Would you like to play again?: \n")).strip().lower()
  
print('\nThanks for playing!')
print('Exiting...\n')
