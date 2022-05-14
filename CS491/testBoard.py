import unittest
from board import Board
from player import Player

class testBoard(unittest.TestCase):
  def test_board_starts_empty(self):
    self.board = Board()
    self.height = 5
    self.width = 5
    
    testresult = self.assertEqual(self.board.board, [['-']*self.width for _ in range(self.height)])
    
    if testresult == None:
      print('test test_board_starts_empty passed!')
    else:
      print('test test_board_starts_empty failed!')

  def test_get_cell(self):
    self.board = Board()
    self.height = 5
    self.width = 5
    
    testresult = self.assertEqual(self.board.get_cell(0,0), '-')
    
    if testresult == None:
      print('test test_get_cell passed!')
    else:
      print('test test_get_cell failed!')

  def test_is_board_full(self):
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

    testresult = self.assertEqual(self.board.is_board_full(), True)
    
    if testresult == None:
      print('test test_is_board_full passed!')
    else:
      print('test test_is_board_full failed!')

  def test_drop_disc(self):
    self.player = Player('Player 1', 'X')
    self.board = Board()
    self.height = 5
    self.width = 5

    self.board.drop_disk(self.player, 0)
    testresult = self.assertEqual(self.board.get_cell(4, 0), 'X')
    
    if testresult == None:
      print('test test_board_starts_empty passed!')
    else:
      print('test test_board_starts_empty failed!')
  
  def test_discs_are_dropped_in_separate_columns(self):
    self.player = Player('Player 1', 'X')
    self.board = Board()
    self.height = 5
    self.width = 5
  
    for i in range(self.width):
      self.board.drop_disk(self.player, i)

    testresult1 = self.assertEqual(self.board.get_cell(4, 0), 'X')
    testresult2 = self.assertEqual(self.board.get_cell(4, 1), 'X')
    testresult3 = self.assertEqual(self.board.get_cell(4, 2), 'X')
    testresult4 = self.assertEqual(self.board.get_cell(4, 3), 'X')
    testresult5 = self.assertEqual(self.board.get_cell(4, 4), 'X')

    if testresult1 == None and testresult2 == None and testresult3 == None and testresult4 == None and testresult5 == None:
      print('test test_discs_are_dropped_in_separate_columns passed!')
    else:
      print('test test_discs_are_dropped_in_separate_columns failed!')
