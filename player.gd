extends Node2D

var current_unit = null
var camera_speed = 20

func _init():
	add_to_group("player")
	child_entered_tree.connect(_child_enterd_tree)
	#child_exiting_tree.connect(_child_exited_tree)
	
func _ready():
	if get_parent().is_in_group("unit"):
		global_position = get_parent().global_position


func _child_enterd_tree(node: Node):
	if not current_unit:
		remove_child(current_unit)
		var main = get_tree().get_first_node_in_group("main")
		main.add_child(current_unit)
	current_unit = node
	global_position = current_unit.global_position


func _process(delta):
	var direction = Input.get_vector("move_left", "move_right", "move_up", "move_down")
	
	if not current_unit:
		current_unit.set_direction(direction)
	
	else:
		global_position += direction * camera_speed
		
	if Input.is_action_just_pressed("shoot") and current_unit:
		current_unit.fire_bullet()
	

