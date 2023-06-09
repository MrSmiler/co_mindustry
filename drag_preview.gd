extends Sprite2D
class_name DragPreview

func _ready():
	pass
	
func _process(delta):
	global_position = get_global_mouse_position()

