part1 = ["|","0","|","1","|","2","|"] 
part2 = ["|","3","|","4","|","5","|"] 
part3 = ["|","6","|","7","|","8","|"] 
listed_grid = [part1,part2,part3]

def print_board(listed_grid):
    for elem in listed_grid:
        for subelem in elem:
            print(subelem,end = " ")
        print("\n")


print_board(listed_grid)

X = "X"
O = "O"

for i in range(1,7,2):
    part1[i] = " "
    part2[i] = " "
    part3[i] = " "

new_listed_grid = [part1,part2,part3]

winner = ""

def tictactoe():
    moves_made = []
    count = 0
    while wins() == False and count < 9 : 
        player_x_move = int(input("Player X - Choose a position by entering a number(0-8)"))
        if player_x_move in moves_made:
            print("Illegal move. Player O wins by default")
            break
        else:
            count += 1
            moves_made.append(player_x_move)
            player_move(player_x_move,X)
            print_board(listed_grid)
            if wins() == False and count < 9:   
                player_o_move = int(input("Player O - Choose a position by entering a number(0-8)"))
                if player_o_move in moves_made:
                    "Illegal move. Player X wins by default"
                    return False
                else:
                    count += 1
                    moves_made.append(player_o_move)
                    player_move(player_o_move,O)
                    print_board(listed_grid)
    if count == 9 and wins() == False:
        print("It's a tie!")
    else:
        print(f"{winner} wins! Congratulations!")
    print_board(new_listed_grid)

def wins():
    global winner
    if (new_listed_grid[0][1] == new_listed_grid[0][3]) and (new_listed_grid[0][3] == new_listed_grid[0][5]) and (new_listed_grid[0][1] != " ") :
        winner = new_listed_grid[0][1]
        return True
    elif (new_listed_grid[1][1] == new_listed_grid[1][3]) and (new_listed_grid[1][3] == new_listed_grid[1][5]) and (new_listed_grid[1][1] != " "):
        winner = new_listed_grid[1][1]
        return True
    elif (new_listed_grid[2][1] == new_listed_grid[2][3]) and (new_listed_grid[2][3] == new_listed_grid[2][5]) and (new_listed_grid[2][1] != " "):
        winner = new_listed_grid[2][1]
        return True
    elif (new_listed_grid[0][1] == new_listed_grid[1][1]) and (new_listed_grid[1][1] == new_listed_grid[2][1]) and (new_listed_grid[0][1] != " "):
        winner = new_listed_grid[0][1]
        return True
    elif (new_listed_grid[0][3] == new_listed_grid[1][3]) and (new_listed_grid[1][3] == new_listed_grid[2][3]) and (new_listed_grid[0][3] != " "):
        winner = new_listed_grid[0][3]
        return True
    elif (new_listed_grid[0][5] == new_listed_grid[1][5]) and (new_listed_grid[1][5] == new_listed_grid[2][5]) and (new_listed_grid[0][5] != " "):
        winner = new_listed_grid[0][5]
        return True
    elif (new_listed_grid[0][1] == new_listed_grid[1][3]) and (new_listed_grid[1][3] == new_listed_grid[2][5]) and (new_listed_grid[0][1] != " "):
        winner = new_listed_grid[0][1]
        return True
    elif (new_listed_grid[0][5] == new_listed_grid[1][3]) and (new_listed_grid[1][3] == new_listed_grid[2][1]) and (new_listed_grid[0][5] != " "):
        winner = new_listed_grid[0][5]
        return True
    else:
        return False


def player_move(player_x_move,player):
    if player_x_move < 3:
        new_listed_grid[0][(player_x_move*2)+1] = player
    elif 2 < player_x_move < 6:
        new_listed_grid[1][((player_x_move-3)*2)+1] = player
    else:
        new_listed_grid[2][((player_x_move - 6)*2)+1] = player
        

tictactoe()