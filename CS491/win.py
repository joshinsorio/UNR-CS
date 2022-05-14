
class Win:
	@staticmethod	
	def is_win_horizontally(board, row, col):
		val = board[row][col]
		count = 1
		left_side = col-1
		right_side = col+1

		while (left_side >= 0 and board[row][left_side] == val):
			count += 1
			left_side -= 1

		while (right_side < len(board[0]) and board[row][right_side] == val):
			count += 1
			right_side += 1

		if count >= 4:
			return True

		return False

	@staticmethod	
	def is_win_vertically(board, row, col):
		val = board[row][col]
		count = 1
		up_side = row-1
		down_side = row+1

		while (up_side >= 0 and board[up_side][col] == val):
			count += 1
			up_side -= 1

		while (down_side < len(board) and board[down_side][col] == val):
			count += 1
			down_side += 1

		if count >= 4:
			return True

		return False

	#   ////
	#  ////
	# ////
	@staticmethod	
	def is_win_diagonally_1(board, row, col):
		val = board[row][col]
		count = 1
		down_side, left_side = row+1, col-1
		up_side, right_side = row-1, col+1

		while (down_side < len(board) and left_side >= 0 and board[down_side][left_side] == val):
			count += 1
			down_side += 1
			left_side -= 1
		
		while (up_side >= 0 and right_side < len(board[0]) and board[up_side][right_side] == val):
			count += 1
			up_side -= 1
			right_side += 1

		if count >= 4:
			return True

		return False

	#\\\\
	# \\\\
	#  \\\\
	@staticmethod	
	def is_win_diagonally_2(board, row, col):
		val = board[row][col]
		count = 1
		up_side, left_side = row-1, col-1
		down_side, right_side = row+1, col+1

		while (up_side >= 0 and left_side >= 0 and board[up_side][left_side] == val):
			count += 1
			up_side -= 1
			left_side -= 1

		while (down_side < len(board) and right_side < len(board[0]) and board[down_side][right_side] == val):
			count += 1
			right_side += 1
			down_side += 1

		if count >= 4:
			return True

		return False

	@staticmethod
	def is_win(board, row, col):
		if Win.is_win_horizontally(board, row, col): return True
		if Win.is_win_vertically(board, row, col): return True
		if Win.is_win_diagonally_1(board, row, col): return True
		if Win.is_win_diagonally_2(board, row, col): return True
		return False