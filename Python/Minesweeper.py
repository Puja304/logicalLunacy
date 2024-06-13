#Minesweeper
#Step 1 - create a grid of 10,10 with labelled rows and columns that can be used by the user to tell us where they wanna dig. 
#Step 2 - plant a specific number of bombs randomly in this grid.
#Step 3 - get user input in case they directly dig a bomb
#Step 4 - if they don't directly dig a bomb, then expose areas around the digside so that the exposed area is adjacent to atleast one bombd at all times

import random

def grid_creator(grid_size):
    mega_matrix = []
    row1 = ["N"] + [(str(i)+"") for i in range(0,grid_size)]
    mega_matrix.append(row1)
    for j in range(0,grid_size):
        row_to_display = [str(j)] + [" " for k in range(0,grid_size)]
        mega_matrix.append(row_to_display)
    return mega_matrix

def bomb_placer(grid_size, bomb_number, mega_matrix):
    bomb_counter = []
    for bombs in range(bomb_number):
        def location_selector():
            row_num = random.randint(1,10)
            column_number = random.randint(1,10)
            location = [row_num,column_number]
            return location
        a_location = location_selector()
        while a_location in bomb_counter:
            a_location = location_selector()
        bomb_counter.append(a_location)
        mega_matrix[a_location[0]][a_location[1]] = "x"
    return mega_matrix_computer


def grid_printer(grid_size,mega_matrix):
    for rows in mega_matrix:
        for elements in rows:
                print(elements + " |", end = " ")
        print()
        print((grid_size*4+3) * "—" )


def adjacent_checker(grid_size, mega_matrx_computer):
    for each_row in range(len(mega_matrix_computer)):
        if each_row != 0:
            for each_element in range(grid_size+1):
                if each_element != 0:
                    if mega_matrix_computer[each_row][each_element] != "x":
                        counter = 0
                        if 1 <= (each_row + 1) <= 10:
                            if mega_matrix_computer[each_row+1][each_element] == "x":
                                counter += 1
                            else:
                                pass
                            if 1 <= (each_element + 1) <= 10:
                                if mega_matrix_computer[each_row+1][each_element+1] == "x":
                                    counter += 1
                                else:
                                    pass
                            else:
                                pass
                            if 1 <= (each_element - 1) <= 10:
                                if mega_matrix_computer[each_row+1][each_element-1] == "x":
                                    counter += 1
                                else:
                                    pass
                            else:
                                pass
                        else:
                            pass
                        if 1 <= (each_row - 1) <= 10:
                            if mega_matrix_computer[each_row -1][each_element] == "x":
                                counter += 1
                            else:
                                pass
                            if 1 <= (each_element + 1) <= 10:
                                if mega_matrix_computer[each_row -1][each_element + 1] == "x":
                                    counter += 1
                                else:
                                    pass
                            else:
                                pass
                            if 1 <= (each_element - 1) <= 10:
                                if mega_matrix_computer[each_row - 1][each_element -1] == "x":
                                    counter += 1
                                else:
                                    pass
                            else:
                                pass
                        else:
                            pass
                        if 1 <= (each_element + 1) <= 10:
                            if mega_matrix_computer[each_row][each_element + 1] == "x":
                                counter += 1
                            else:
                                pass
                        else:
                            pass
                        if 1 <= (each_element - 1) <= 10:
                            if mega_matrix_computer[each_row][each_element - 1] == "x":
                                counter += 1
                            else:
                                pass
                        else:
                            pass
                        mega_matrix_computer[each_row][each_element] = str(counter)
                    else:
                        pass
                else:
                    pass
    return mega_matrix_computer


def rightwards(coordinates,mega_matrix,change_matrix):
    global counter
    global counter_list
    counter_list = []
    counter = 0
    row_num = coordinates[0] 
    column_num = coordinates[1]
    selected_row = mega_matrix[row_num]
    if selected_row[column_num] == "x":
        change_matrix = change_matrix
    elif selected_row[column_num] != "x" and int(selected_row[column_num]) != 0:
        change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
        counter_list.append([row_num,column_num])
        change_matrix = change_matrix
    elif int(selected_row[column_num]) == 0:
        counter += 1
        counter_list.append([row_num,column_num])
        change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
        while int(selected_row[column_num]) == 0 and column_num + 1 < 11:
            column_num = column_num + 1
            if int(selected_row[column_num]) == 0:
                counter += 1
                counter_list.append([row_num,column_num])
                change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
            elif int(selected_row[column_num]) != 0 and selected_row[column_num] != "x":
                change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
                counter_list.append([row_num,column_num])
                break
            elif selected_row[column_num] == "x":
                break
    return change_matrix


def leftwards(coordinates, mega_matrix, change_matrix):
    global counter
    global counter_list
    row_num = coordinates[0] 
    column_num = coordinates[1]
    selected_row = mega_matrix[row_num]
    if selected_row[column_num] == "x":
        change_matrix = change_matrix
    elif selected_row[column_num] != "x" and int(selected_row[column_num]) != 0:
        change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
        counter_list.append([row_num,column_num])
        change_matrix = change_matrix
    elif int(selected_row[column_num]) == 0:
        counter += 1
        counter_list.append([row_num,column_num])
        change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
        while int(selected_row[column_num]) == 0 and column_num - 1 > 0:
            column_num -= 1 
            if int(selected_row[column_num]) == 0:
                counter += 1
                counter_list.append([row_num,column_num])
                change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
            elif int(selected_row[column_num]) != 0 and selected_row[column_num] != "x":
                change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
                counter_list.append([row_num,column_num])
                break
            elif selected_row[column_num] == "x":
                break
    return change_matrix

def upwards(coordinates,mega_matrix,change_matrix):
    global counter_upper
    global counter_upper_list
    counter_upper_list = []
    counter_upper = 0
    row_num = coordinates[0] 
    column_num = coordinates[1]
    if mega_matrix[row_num][column_num] == "x":
        change_matrix = change_matrix
    elif mega_matrix[row_num][column_num] != "x" and int(mega_matrix[row_num][column_num]) != 0:
        change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
        counter_upper_list.append([row_num,column_num])
        change_matrix = change_matrix
    elif int(mega_matrix[row_num][column_num]) == 0:
        counter_upper += 1
        counter_upper_list.append([row_num,column_num])
        change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
        while int(mega_matrix[row_num][column_num]) == 0 and row_num - 1 > 0:
            row_num = row_num - 1
            if int(mega_matrix[row_num][column_num]) == 0:
                counter_upper += 1
                counter_upper_list.append([row_num,column_num])
                change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
            elif int(mega_matrix[row_num][column_num]) != 0 and mega_matrix[row_num][column_num] != "x":
                change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
                counter_upper_list.append([row_num,column_num])
                break
            elif mega_matrix[row_num][column_num] == "x":
                break
    return change_matrix 

def downwards(coordinates,mega_matrix,change_matrix):
    global counter_upper
    global counter_upper_list
    row_num = coordinates[0] 
    column_num = coordinates[1]
    if mega_matrix[row_num][column_num] == "x":
        change_matrix = change_matrix
    elif mega_matrix[row_num][column_num] != "x" and int(mega_matrix[row_num][column_num]) != 0:
        change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
        counter_upper_list.append([row_num,column_num])
        change_matrix = change_matrix
    elif int(mega_matrix[row_num][column_num]) == 0:
        counter_upper += 1
        counter_upper_list.append([row_num,column_num])
        change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
        while int(mega_matrix[row_num][column_num]) == 0 and row_num + 1 < 11:
            row_num = row_num + 1
            if int(mega_matrix[row_num][column_num]) == 0:
                counter_upper += 1
                counter_upper_list.append([row_num,column_num])
                change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
            elif int(mega_matrix[row_num][column_num]) != 0 and mega_matrix[row_num][column_num] != "x":
                change_matrix[row_num][column_num] = mega_matrix[row_num][column_num]
                counter_upper_list.append([row_num,column_num])
                break
            elif mega_matrix[row_num][column_num] == "x":
                break
    return change_matrix


def row_checker(coordinates,mega_matrix,user_matrix):
    store_first_row = int(coordinates[0])
    first_row = int(coordinates[0])
    first_column = int(coordinates[1])
    rightwards(coordinates, mega_matrix, user_matrix)
    leftwards(coordinates,mega_matrix,user_matrix)
    while counter != 0 and (first_row + 1 < 11):
        first_row += 1
        while len(counter_list) > 2:
            rightwards([first_row,first_column], mega_matrix_computer,mega_matrix_user)
            leftwards([first_row,first_column], mega_matrix_computer,mega_matrix_user)
            for dugups in counter_list:
                upwards(dugups,mega_matrix_computer,mega_matrix_user)
                downwards(dugups,mega_matrix_computer,mega_matrix_user)
                for duguptwos in counter_upper_list:
                    rightwards(duguptwos,mega_matrix_computer,mega_matrix_user)
                    leftwards(duguptwos,mega_matrix_computer,mega_matrix_user)
                    for dugupfinals in counter_list:
                        upwards(dugupfinals,mega_matrix_computer,mega_matrix_user)
                        downwards(dugupfinals,mega_matrix_computer,mega_matrix_user)
                        for duguprealfinals in counter_upper_list:
                            rightwards(duguprealfinals,mega_matrix_computer,mega_matrix_user)
                            leftwards(duguprealfinals,mega_matrix_computer,mega_matrix_user)
    first_row = store_first_row
    rightwards(coordinates, mega_matrix, user_matrix)
    leftwards(coordinates,mega_matrix,user_matrix)
    while counter > 0 and (first_row - 1 > 0):
        first_row -= 1
        while len(counter_list) > 2:
            rightwards([first_row,first_column], mega_matrix_computer,mega_matrix_user)
            leftwards([first_row,first_column], mega_matrix_computer,mega_matrix_user)
            for dugups in counter_list:
                upwards(dugups,mega_matrix_computer,mega_matrix_user)
                downwards(dugups,mega_matrix_computer,mega_matrix_user)
                for duguptwos in counter_upper_list:
                    rightwards(duguptwos,mega_matrix_computer,mega_matrix_user)
                    leftwards(duguptwos,mega_matrix_computer,mega_matrix_user)
                    for dugupfinals in counter_list:
                        upwards(dugupfinals,mega_matrix_computer,mega_matrix_user)
                        downwards(dugupfinals,mega_matrix_computer,mega_matrix_user)
                        for duguprealfinals in counter_upper_list:
                            rightwards(duguprealfinals,mega_matrix_computer,mega_matrix_user)
                            leftwards(duguprealfinals,mega_matrix_computer,mega_matrix_user)


mega_matrix_computer = grid_creator(10)
mega_matrix_computer = bomb_placer(10,10,mega_matrix_computer)
mega_matrix_computer = adjacent_checker(10,mega_matrix_computer)
mega_matrix_user = grid_creator(10)
grid_printer(10,mega_matrix_user)
#grid_printer(10,mega_matrix_computer)

def comparer(user_matrix):
    value = False
    for rows in range(len(user_matrix)):
        for elements in range(len(user_matrix)):
            if mega_matrix_computer[rows][elements] != "x":
                if mega_matrix_computer[rows][elements] == user_matrix[rows][elements]:
                    value = True
                else:
                    value = False
                    return False
            else:
                pass
    return value 


while True:
    dig_site = list(input("Enter the location you want to dig in format 0,0 (rows,columns) where each row and columns: ").split(","))
    dig_site = [int(i) + 1 for i in dig_site]

    if dig_site[0] > 10 or dig_site[0] < 0 or dig_site[1] < 0 or dig_site[1] > 10:
        print("Invlaid Input")
        dig_site = list(input("Enter the location you want to dig in format 0,0 (rows,columns) where each row and columns: ").split(","))
        dig_site = [int(i) + 1 for i in dig_site]
    elif mega_matrix_computer[dig_site[0]][dig_site[1]] == "x":
        grid_printer(10,mega_matrix_computer)
        print("Game over")
        break
    else:
        row_checker(dig_site, mega_matrix_computer,mega_matrix_user)
        if comparer(mega_matrix_user) == True:
            print("You win!")
            grid_printer(10,mega_matrix_user)
            break
        else:
            grid_printer(10,mega_matrix_user)



