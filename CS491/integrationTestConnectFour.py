import unittest
from board import Board
from player import Player
from setup import Setup
from win import Win

class testConnectFour(unittest.TestCase):
  def test_connect_four(self):
    self.player = Player('Player 1', 'X')
    self.board = Board()
    self.height = 5
    self.width = 5

    for i in range(4):
      self.board.drop_disk(self.player, i)

    testresult = self.assertEqual(Win.is_win_horizontally(self.board.board, self.height-1, i), True)
    if testresult == None:
      print('test test_connect_four passed!')
    else:
      print('test test_connect_four failed!')

  def test_different_discs_are_dropped_in_separate_columns(self):
    self.player1 = Player('Player 1', 'X')
    self.player2 = Player('Player 2', 'O')
    self.board = Board()
    self.height = 5
    self.width = 5
  
    for i in range(3):
      self.board.drop_disk(self.player1, i)
    for i in range(2):
      self.board.drop_disk(self.player2, i+3)

    testresult1 = self.assertEqual(self.board.get_cell(4, 0), 'X')
    testresult2 = self.assertEqual(self.board.get_cell(4, 1), 'X')
    testresult3 = self.assertEqual(self.board.get_cell(4, 2), 'X')
    testresult4 = self.assertEqual(self.board.get_cell(4, 3), 'O')
    testresult5 = self.assertEqual(self.board.get_cell(4, 4), 'O')

    if testresult1 == None and testresult2 == None and testresult3 == None and testresult4 == None and testresult5 == None:
      print('test test_different_discs_are_dropped_in_separate_columns passed!')
    else:
      print('test test_different_discs_are_dropped_in_separate_columns failed!')

  def test_setup_players(self):
    self.player1 = Player('Player 1', 'X')
    self.player2 = Player('Player 2', 'O')
    self.setup = Setup()
    self.setup.run(False)

    players = self.setup.get_players()

    testresult1 = self.assertEqual(players[0].name, self.player1.name)
    testresult2 = self.assertEqual(players[1].name, self.player2.name)
    testresult3 = self.assertEqual(players[0].colour, self.player1.colour)
    testresult4 = self.assertEqual(players[1].colour, self.player2.colour)
        
    if testresult1 == None and testresult2 == None and testresult3 == None and testresult4 == None:
      print('test test_setup_players passed!')
    else:
      print('test test_setup_players failed!')

  def test_draw_game(self):
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
      print('test test_draw_game passed!')
    else:
      print('test test_draw_game failed!')

  def test_illegal_move(self):
    self.player = Player('Player 1', 'X')
    self.board = Board()
    self.height = 5
    self.width = 5

    for i in range(4):
      self.board.drop_disk(self.player, 0)
    self.board.drop_disk(self.player, 0)
    testresult = self.assertEqual(self.board.get_cell(5,0), None)
    
    if testresult == None:
      print('test test_legal_move passed!')
    else:
      print('test test_legal_move failed!')