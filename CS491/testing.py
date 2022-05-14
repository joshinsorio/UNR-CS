from testWin import testWin
from testBoard import testBoard
from testSetup import testSetup
from integrationTestConnectFour import testConnectFour

#################################################################################
#Unit Test
print("\n")
print("----------------------------------------------------------")
print("\t\t\t\t\t Unit Test \t\t\t\t\t\t")
print("----------------------------------------------------------")
testwin = testWin()
testwin.test_successful_horizontal_winning_move_is_found()
testwin.test_successful_vertical_winning_move_is_found()
testwin.test_successful_diagonal1_winning_move_is_found()
testwin.test_successful_diagonal2_winning_move_is_found()
testwin.test_is_win_not()

testboard = testBoard()
testboard.test_board_starts_empty()
testboard.test_get_cell()
testboard.test_is_board_full()
testboard.test_drop_disc()
testboard.test_discs_are_dropped_in_separate_columns()

testsetup = testSetup()
testsetup.test_get_players()
testsetup.test_choose_name_color()

#################################################################################
#Integration Test
print("\n")
print("----------------------------------------------------------")
print("\t\t\t\t\t Integration Test \t\t\t\t\t\t")
print("----------------------------------------------------------")
testconnectFour = testConnectFour()
testconnectFour.test_connect_four()
testconnectFour.test_different_discs_are_dropped_in_separate_columns()
testconnectFour.test_setup_players()
testconnectFour.test_draw_game()
testconnectFour.test_illegal_move()
