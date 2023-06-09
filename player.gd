extends Node2D

var current_unit = null
var camera_speed = 20
var attached_to_unit = false
var _target_unit: Unit

func _init():
	add_to_group("player")
	tree_entered.connect(_tree_enterd_handler)

func _tree_enterd_handler():
	_target_unit = get_parent() as Unit
	
	if _target_unit:
		attached_to_unit = true
		global_position = _target_unit.global_position
	else:
		assert(get_parent() as MainGame, "player is not attached to a unit")
		_target_unit = null
		attached_to_unit = false


func _process(delta):
	var direction = Input.get_vector("move_left", "move_right", "move_up", "move_down")
	if attached_to_unit:
		_target_unit.direction = direction
	else:
		global_position += direction * camera_speed
		
	if Input.is_action_just_pressed("left_click") and attached_to_unit:
		_target_unit.fire_bullet()
