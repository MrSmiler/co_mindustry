extends Node
var direction
var player
var camera_speed = 20

func _init():
	add_to_group("main")
	child_entered_tree.connect(_node_enterd_tree)
	child_exiting_tree.connect(_node_exited_tree)

func _node_enterd_tree(node: Node):
	if node.is_in_group("player"):
		player = node
		player.player_move.connect(_set_direction)
		print_debug("player added to main scene")

func _node_exited_tree(node: Node):
	if node.is_in_group("player"):
		player.player_move.disconnect(_set_direction)
		print_debug("player added to main scene")
	
		
func _set_direction(dir: Vector2):
	player.get_node("Camera").position += dir * camera_speed
