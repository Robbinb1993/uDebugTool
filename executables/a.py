from sys import stdin

def validate_move(king, queen, queen_move):
	if not validate_position(queen_move):
		return False
	if not (queen_move//8 == queen//8 or queen_move%8 == queen%8):
		return False
	if queen == queen_move or king == queen_move:
		return False

	if (queen_move//8 == king//8 and queen//8 == king//8  and (queen-queen_move)//(queen-king) >= 1):
		return False
	if (queen_move%8 == king%8 and queen%8 == king%8 and (queen-queen_move)//(queen-king) >= 1):
		return False
	return True

def king_legal_moves(king):
	moves = []
	if not king%8 == 0:
		moves += [king-1]
	if not king%8 == 7:
		moves += [king+1]
	if not king//8 == 0:
		moves += [king-8]
	if not king//8 == 7:
		moves += [king+8]

	return moves

def allow_move(queen_move,king):
	if queen_move in king_legal_moves(king):
		return False
	return True

def can_king_move(king,queen_move):
	legal_moves = king_legal_moves(king)
	moves = len(legal_moves)
	for move in legal_moves:
		if (move//8 == queen_move//8 or move%8 == queen_move%8 or not validate_position(move)):
			moves -= 1
	return moves > 0

def validate_position(position):
	return position >= 0 and position <= 63

def main():
	lines = stdin.read().splitlines()
	for curr_Line in lines:
		curr_Line=curr_Line.split()
		king = int(curr_Line[0])
		queen = int(curr_Line[1])
		queen_move = int(curr_Line[2])
		if king == queen or not validate_position(king) or not validate_position(queen):
			print("Illegal state")
		elif not validate_move(king, queen, queen_move):
			print("Illegal move")
		elif not allow_move(queen_move,king):
			print("Move not allowed")
		elif can_king_move(king,queen_move):
			print("Continue")
		else:
			print("Stop")

	return 

main()