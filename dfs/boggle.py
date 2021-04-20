FILE = 'dictionary.txt'

# global variables
dict_list = []
boggle_board = []
total = 0
found_lst = []

neighbors = [
    (-1, 0),  # 'up'         
    (1, 0),   # 'down'       
    (0, -1),  # 'left'       
    (0, 1),   # 'right'      
    (-1, -1), # 'up-left'    
    (-1, 1),  # 'up-right'   
    (1, -1),  # 'down-left'  
    (1, 1)    # 'down-right' 
]


def read_dictionary():
	"""
	This function reads file "dictionary.txt" stored in FILE
	and appends words in each line into a Python list
	"""
	with open(FILE, 'r') as f:
		for word in f:
			word = word.strip()
			dict_list.append(word)


def has_prefix(sub_s):
	"""
	:param sub_s: (str) A substring that is constructed by neighboring letters on a 4x4 square grid
	:return: (bool) If there is any words with prefix stored in sub_s
	"""
	for char in dict_list:
		if char.startswith(sub_s):
			return True
	return False


def read_input():
    """
    Read boggle inputs. 
    The input should be consisted of 4 rows, and each row contains 4 letters separated by spaces.
        [example] "a f t r"
    
    Input rows will be stored in `boggle_board` as a 2d array.
        [example]
            boggle_board = [
                ['f', 'y', 'c', 'l'],
                ['i', 'o', 'm', 'g'],
                ['o', 'r', 'i', 'l'],
                ['h', 'j', 'h', 'u'],
            ]
    """

    for i in range(1, 5):
        # get user input
        row = input(f"{i} row of letters: ")
        
        # split by spaces
        row = row.split(' ')
        
        # check input
        for letter in row:
            letter = letter.lower()
            if len(letter) != 1 or len(row) != 4 or not letter.isalpha():
                print("Illegal input")
                exit(0)
        
        # store in boggle_board
        boggle_board.append(row)

def traverse_boggle(coord, seq, visited):
    ''' Traverse the boggle board by DFS (Depth-first Search).

    Input
    -----
    coord: tuple[int, int]
        The current coordinate (row, col)
    seq: str
        The letter sequence collected by the current DFS path.
    visited: list[coord]
        Visited coordinates on the current path. Used to avoid repetition.
    '''
    global total
    global found_lst

    # get current row & column
    r, c = coord[0], coord[1]
    
    # get the letter of this block
    letter = boggle_board[r][c]
    
    # append the letter sequence
    seq += letter
    
    # check if the dictionary contains the sequence prefix
    if has_prefix(seq) == False:
        return
    
    # mark the current coordinate as visited
    visited.append(coord)
    
    # check if the letter sequence is a word
    if (len(seq) >= 4) and (seq in dict_list) and (seq not in found_lst):
        print(f'Found "{seq}"')
        total += 1
        found_lst.append(seq)
    
    '''
    Extend the sequence to neighbors
    '''
    for n in neighbors:
        new_coord = (r+n[0], c+n[1])
        
        # check if the new coordinate is valid
        if new_coord[0] < 0 or new_coord[0] > 3 or new_coord[1] < 0 or new_coord[1] > 3:
            continue

        if new_coord not in visited:
            traverse_boggle(new_coord, seq, visited.copy())

            # We use .copy() here since the list is mutable.
            # (each traversal path requires an independent 'visited' record)
            
    

def play_boggle():
    ''' Perform DFS (Depth-first Search) traversal for each letter on the boggle board.
    '''
    global total

    for row in range(len(boggle_board)):
        for col in range(len(boggle_board[row])):
            traverse_boggle((row, col), '', [])
    
    print(f"There are {total} words in total.")


def main():
    read_input()
    read_dictionary()
    play_boggle()

if __name__ == '__main__':
	main()