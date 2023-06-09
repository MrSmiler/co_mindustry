extends TileMap


func _init():
	add_to_group("map")
# Called when the node enters the scene tree for the first time.
func _ready():
	var sid = get_cell_source_id(3, Vector2(1, 1))
	var aid = get_cell_alternative_tile(3, Vector2(1, 1))
	set_cell(3, Vector2(2,2), sid, Vector2.ZERO, aid)
	print_debug("sid: " + str(sid) + " aid: " + str(aid))
	

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
