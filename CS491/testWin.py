import unittest

from board import Board
from player import Player
from win import Win

class testWin(unittest.TestCase):
  def test_successful_horizontal_winning_move_is_found(self):
    self.player = Player('Player 1', 'X')
    self.board = Board()
    self.height = 5
    self.width = 5

    for i in range(4):
      self.board.drop_disk(self.player, i)

    testresult = self.assertEqual(Win.is_win_horizontally(self.board.board, self.height-1, i), True)
    if testresult == None:
      print('test test_successful_horizontal_winning_move_is_found passed!')
    else:
      print('test test_successful_horizontal_winning_move_is_found failed!')

  def test_successful_vertical_winning_move_is_found(self):
    self.player = Player('Player 1', 'X')
    self.board = Board()
    self.height = 5
    self.width = 5

    for i in range(4):
      self.board.drop_disk(self.player, 0)

    testresult = self.assertEqual(Win.is_win_vertically(self.board.board, self.height-1-i, 0), True)
    
    if testresult == None:
      print('test test_successful_vertical_winning_move_is_found passed!')
    else:
      print('test test_successful_vertical_winning_move_is_found failed!')

  def test_successful_diagonal1_winning_move_is_found(self):
    self.player1 = Player('Player 1', 'X')
    self.player2 = Player('Player 2', 'O')
    self.board = Board()
    self.height = 5
    self.width = 5

    for i in range(3):
      self.board.drop_disk(self.player1, i)
      for j in range(i+1, 4):
        self.board.drop_disk(self.player2, j)

    self.board.drop_disk(self.player1, 3)
    testresult = self.assertEqual(Win.is_win_diagonally_1(self.board.board, self.height-1-i, i), True)
    
    if testresult == None:
      print('test test_successful_diagonal1_winning_move_is_found passed!')
    else:
      print('test test_successful_diagonal1_winning_move_is_found failed!')

  def test_successful_diagonal2_winning_move_is_found(self):
      self.player1 = Player('Player 1', 'X')
      self.player2 = Player('Player 2', 'O')
      self.board = Board()
      self.height = 5
      self.width = 5
  
      for i in range(3):
        for j in range(i,3):
          self.board.drop_disk(self.player2, i)
      for i in range(3):
        self.board.drop_disk(self.player1, i)
  
      self.board.drop_disk(self.player1, 3)
      testresult = self.assertEqual(Win.is_win_diagonally_2(self.board.board, self.height-1-i, i), True)
    
      if testresult == None:
        print('test test_successful_diagonal2_winning_move_is_found passed!')
      else:
        print('test test_successful_diagonal2_winning_move_is_found failed!')

  def test_is_win_not(self):
    self.player1 = Player('Player 1', 'X')
    self.player2 = Player('Player 2', 'O')
    self.board = Board()
    self.height = 5
    self.width = 5

    self.board.drop_disk(self.player1, 0)
    self.board.drop_disk(self.player2, 1)
    self.board.drop_disk(self.player1, 2)
    self.board.drop_disk(self.player2, 3)
    self.board.drop_disk(self.player1, 4)
    for i in range(3):
      self.board.drop_disk(self.player2, 0)
      self.board.drop_disk(self.player1, 1)
      self.board.drop_disk(self.player2, 2)
      self.board.drop_disk(self.player1, 3)
      self.board.drop_disk(self.player2, 4)
    self.board.drop_disk(self.player1, 0)
    self.board.drop_disk(self.player2, 1)
    self.board.drop_disk(self.player1, 2)
    self.board.drop_disk(self.player2, 3)
    self.board.drop_disk(self.player1, 4)
    
    testresult = self.assertNotEqual(Win.is_win(self.board.board, self.height-1-i, i), True)
  
    if testresult == None:
      print('test test_is_win_not passed!')
    else:
      print('test test_is_win_not failed!')
    