from player import Player
from win import Win

class Board:

	def __init__(self, players = (Player('Player 1', 'X'), Player('Player 2', 'O')), height = 5, width = 5):
		self.players = players
		self.height = height
		self.width = width
		self.board = [['-']*width for _ in range(height)]
		self._game_over = False
		self.column_counter = [0]*width
		self._turn = False #Player 1's turn

	def print_board(self):
		s = [[str(e) for e in row] for row in self.board]
		lens = [max(map(len, col)) for col in zip(*s)]
		fmt = '\t'.join('{{:{}}}'.format(x) for x in lens)
		table = [fmt.format(*row) for row in s]
		print('\n'+'\n'.join(table)+'\n')

	def get_cell(self, i, j):
		try:
			if (i < self.height and i >= 0 and j < self.width and j >= 0):
				return self.board[i][j]
		except ValueError:
			print('Out of Range!')

	def is_board_full(self):
		for i in range(self.width):
			if self.column_counter[i] != self.height:
				return False

		print('No more free spaces!\nGAME OVER!!!\n')
		return True

	def choose_column(self):
		# check if user input is valid
		while True:
				player_input = input("{}'s Move: ".format(self.players[self._turn].name))
				try:
					col = int(player_input)
					if (col >= self.width or col < 0):
						print('Out Of Bounds! Please choose a value between {} and {}!\n'.format(0, self.width-1))
					else:
						break
				except ValueError:
					print("{} was not a number, please use a valid input.\n".format(player_input))		
		return col

	def drop_disk(self, player, col):
		while True:
			if self.column_counter[col] >= self.height:
				print('No more space in current column!\nPlease choose another column\n')
				col = self.choose_column()
			else:
				break
		row = self.height-self.column_counter[col]-1
		self.board[row][col] = player.colour
		self.column_counter[col] += 1
		
		if Win.is_win(self.board, row, col):
			print('\nCongratulations {}!!!\nVictory is yours!!!\n'.format(player.name))
			self._game_over = True

	def play(self):
		while not self._game_over:
			# Ask the player whose turn it is to choose a column - which is checked and validated
			col = self.choose_column()

			# Insert Player 1's colour in the chosen column
			if not self._turn:
				self.drop_disk(self.players[0], col)

			# Insert Player 2's colour in the chosen column
			else:
				self.drop_disk(self.players[1], col)

			# alternate between players
			self._turn = not self._turn
			# print game status
			self.print_board()

			if self.is_board_full():
				self._game_over = True

	DIMENSIONS_LIMIT = 10

	@staticmethod
	def get_dimensions():
		while True:
			try:			
				height, width = map(int, input("Please choose the board dimensions (height and width): \n").replace(',', ' ').split())
				try:
					if (height <= 0 or height > Board.DIMENSIONS_LIMIT or width <= 0 or width > Board.DIMENSIONS_LIMIT):
						print('Out Of Bounds! Please choose values between {} and {}!\n'.format(1, Board.DIMENSIONS_LIMIT))
					else:
						break
				except ValueError:
						print("Was not a number, please use a valid input.\n")
			except ValueError:
				print("2 Dimensional Values are expected, please input 2 new valid values.\n")

		return height, width