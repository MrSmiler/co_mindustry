extends CharacterBody2D

@export var speed = 300
@export var bullet_speed = 500
@export var damage = 20
@export var hitpoints: int = 100:
	get:
		return hitpoints
	set(value):
		hitpoints = value
		if (hitpoints <= 0):
			queue_free()

var _BulletScene = preload("res://bullet.tscn")
var _direction = Vector2.ZERO
var _mouse_inside: bool = false


func do_damage(amount: int):
	hitpoints -= amount

func fire_bullet():
	
	var velocity = Vector2.ZERO
	var shoot_direction = global_position.direction_to(get_global_mouse_position())
	
	var bullet = _BulletScene.instantiate()
	bullet.damage = damage
	#bullet.global_position = global_position + shoot_direction * 45
	bullet.global_position = global_position
	bullet.add_collision_exception_with(self)
	bullet.linear_velocity = shoot_direction * bullet_speed
	
	get_tree().get_first_node_in_group("game_render_layer").add_child(bullet)
	
	$ShootingSound.play()


func _init():
	child_entered_tree.connect(_node_enterd_tree)
	child_exiting_tree.connect(_node_exited_tree)
	mouse_entered.connect(_mouse_enterd)
	mouse_exited.connect(_mouse_exited)
	
	
func _ready():
	get_parent().add_to_group("damageable")
	get_parent().add_to_group("unit")

func _process(delta):
	if Input.is_action_just_pressed("swtich_player") and _mouse_inside:
		var main = get_tree().get_first_node_in_group("main")
		var player = get_tree().get_first_node_in_group("player")
		player.get_parent().remove_child(player)
		add_child(player)

func _node_enterd_tree(node: Node):
	if node.is_in_group("player"):
		node.player_move.connect(_set_direction)
		node.global_position = get_parent().global_position
		
func _node_exited_tree(node: Node):
	if node.is_in_group("player"):
		node.player_move.disconnect(_set_direction)
		_direction = Vector2.ZERO
		
func _mouse_enterd():
	_mouse_inside = true

func _mouse_exited():
	_mouse_inside = false	

func _set_direction(dir: Vector2):
	_direction = dir


func _physics_process(delta):
	
	velocity = _direction * speed
	
	var collision = move_and_collide(velocity * delta)
	look_at(_direction + global_position)

	

