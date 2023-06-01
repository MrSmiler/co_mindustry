extends StaticBody2D
class_name ConveyorBelt

var direction: Vector2 = Vector2(1,0)
var belt_speed: int = 5
var _item: Item = null
var _next_conveyor: ConveyorBelt = null

func accept_item(item: Item) -> void:
	_item = item

# Called when the node enters the scene tree for the first time.
func _ready():
	$AnimatedSprite2D.play()
	
	

func _process(delta):
	var velocity = belt_speed * direction
	if _item:
		_item.global_position += velocity * delta
		if _item_passed(_item):
			pass

func _item_passed(item: Item) -> bool:
	var max_x = global_position.x + ($CollisionShape2D.shape.size.x / 2)
	if (item.global_position.x + item.texture.get_width()/2) > max_x:
		return true
	return false
