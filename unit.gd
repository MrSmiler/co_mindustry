extends CharacterBody2D

@export var BulletScene: PackedScene
const SPEED = 300
const bullet_speed = 500
var target = Vector2.ZERO
var direction = Vector2.ZERO
var _mouse_inside: bool = false

func _init():
	child_entered_tree.connect(_node_enterd_tree)
	child_exiting_tree.connect(_node_exited_tree)
	mouse_entered.connect(_mouse_enterd)
	mouse_exited.connect(_mouse_exited)
	add_to_group("unit")

func _process(delta):
	if Input.is_action_just_pressed("swtich_player") and _mouse_inside:
		var main = get_tree().get_first_node_in_group("main")
		var player = get_tree().get_first_node_in_group("player")
		player.get_parent().remove_child(player)
		add_child(player)

func _node_enterd_tree(node: Node):
	if node.is_in_group("player"):
		node.player_move.connect(_set_direction)
		
func _node_exited_tree(node: Node):
	if node.is_in_group("player"):
		node.player_move.disconnect(_set_direction)
		direction = Vector2.ZERO
		
func _mouse_enterd():
	print_debug("mouse enterd")
	_mouse_inside = true

func _mouse_exited():
	print_debug("mouse exited")
	_mouse_inside = false	

func _set_direction(dir: Vector2):
	direction = dir

func fire_bullet():
	
	var velocity = Vector2.ZERO
	var bullet = BulletScene.instantiate()
	var shoot_direction = global_position.direction_to(get_global_mouse_position())
	bullet.global_position = global_position + shoot_direction * 45
	
	bullet.linear_velocity = shoot_direction * bullet_speed
	#bullet.position.y += fly_direction * (($CollisionShape2D.shape.size.y / 2) + 10)
	get_tree().get_first_node_in_group("game_render_layer").add_child(bullet)
	
	$ShootingSound.play()


func _physics_process(delta):
	
	velocity = direction * SPEED
	
	var collision = move_and_collide(velocity * delta)
	if collision:
		print_debug("I collided with ", collision.get_collider().name)
	look_at(direction + global_position)

	

