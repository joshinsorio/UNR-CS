import unittest
from setup import Setup
from player import Player

class testSetup(unittest.TestCase):
  def test_get_players(self):
    self.player1 = Player('Player 1', 'X')
    self.player2 = Player('Player 2', 'O')
    self.setup = Setup(self.player1, self.player2)
    players = self.setup.get_players()
    
    testresult = self.assertEqual(players[0], self.player1)
    
    if testresult == None:
      print('test test_get_players passed!')
    else:
      print('test test_get_players failed!')

  def test_choose_name_color(self):
    self.player1 = Player('Player 1', 'X')

    player = self.setup.choose_name_colour(self.player1, False)
    testresult1 = self.assertNotEqual(player.name, self.player1.name)
    testresult2 = self.assertNotEqual(player.colour, self.player1.colour)

    if testresult1 == None and testresult2 == None:
      print('test test_choose_name_color passed!')
    else:
      print('test test_choose_name_color failed!')