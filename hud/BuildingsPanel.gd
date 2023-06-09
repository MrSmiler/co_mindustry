extends Panel

@onready var _conveyor_belt_button = $HBoxContainer/Buildings/GridContainer/ConveyorBelt as Button

var _conveyor_belt_scene: PackedScene = preload("res://conveyor_belt.tscn")
var _drag_preview: DragPreview = null
var _draging: bool = false


func _ready():
	_conveyor_belt_button.pressed.connect(_conveyor_clicked)


func _conveyor_clicked():
	if not _draging:
		_draging = true
		var image = _conveyor_belt_button.icon.get_image()
		var texture = ImageTexture.create_from_image(image)
		_drag_preview = DragPreview.new()
		_drag_preview.texture = texture
		add_child(_drag_preview)
		

func _process(delta):
	if Input.is_action_just_pressed("right_click") and _draging:
		_drag_preview.queue_free()
		_draging = false
	
	if Input.is_action_pressed("left_click") and _draging:
		var conveyor_belt = _conveyor_belt_scene.instantiate()
		var map: Node = get_tree().get_first_node_in_group("map")
		var mouse_pos = map.get_global_mouse_position()
		# TODO: We have to check wether there is any belt in 
		# exact position on the middle of tile
		var building_position = map.map_to_local(map.local_to_map(mouse_pos))
		#print_debug(mouse_pos)
		conveyor_belt.global_position = building_position
		
		map.add_child(conveyor_belt)
		for belt in get_tree().get_nodes_in_group("conveyor_belt"):
			belt.get_node("AnimatedSprite2D").stop()
			belt.get_node("AnimatedSprite2D").play()
		
	
	

