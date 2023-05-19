extends Node2D

signal player_move(direction: Vector2)

func _init():
	tree_entered.connect(_tree_enterd)
	add_to_group("player")

func _tree_enterd():
	if not get_parent().is_in_group("main"):
		var p = get_parent().global_position
		global_position = p

func _ready():
	pass

func _process(delta):
	var direction = Input.get_vector("move_left", "move_right", "move_up", "move_down")
	
	player_move.emit(direction)
		
	if Input.is_action_just_pressed("shoot"):
		if get_parent().is_in_group("unit"):
			get_parent().fire_bullet()
	

