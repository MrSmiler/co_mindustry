extends Camera2D


# Lower cap for the `_zoom_level`.
@export var min_zoom := 0.5
# Upper cap for the `_zoom_level`.
@export var max_zoom := 2.0
# Controls how much we increase or decrease the `_zoom_level` on every turn of the scroll wheel.
@export var zoom_factor := 0.1
# Duration of the zoom's tween animation.
@export var zoom_duration := 0.2

var _zoom_level = 1.0

var tween

func _unhandled_input(event):
	if event.is_action_pressed("zoom_in"):
		_set_zoom_level(_zoom_level + zoom_factor)
	if event.is_action_pressed("zoom_out"):
		_set_zoom_level(_zoom_level - zoom_factor)
		
	
	
# Called when the node enters the scene tree for the first time.


	
func _set_zoom_level(value: float) -> void:
	tween = create_tween()
	# We limit the value between `min_zoom` and `max_zoom`
	_zoom_level = clamp(value, min_zoom, max_zoom)
	# Then, we ask the tween node to animate the camera's `zoom` property from its current value
	# to the target zoom level.
	tween.tween_property(
		self,
		"zoom",
		Vector2(_zoom_level, _zoom_level),
		zoom_duration
	)
