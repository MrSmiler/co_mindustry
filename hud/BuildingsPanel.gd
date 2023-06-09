extends Panel

var _conveyor_belt_scene: PackedScene = preload("res://conveyor_belt.tscn")
@onready var _conveyor_belt_button = $HBoxContainer/Buildings/GridContainer/ConveyorBelt as Button

func _ready():
	_conveyor_belt_button.pressed.connect(_conveyor_clicked)


func _conveyor_clicked():
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
