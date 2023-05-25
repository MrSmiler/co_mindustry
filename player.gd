extends Node2D

signal player_move(direction: Vector2)

func _init():
	add_to_group("player")

func _ready():
	pass

func _process(delta):
	var direction = Input.get_vector("move_left", "move_right", "move_up", "move_down")
	
	player_move.emit(direction)
		
	if Input.is_action_just_pressed("shoot"):
		pass
	

