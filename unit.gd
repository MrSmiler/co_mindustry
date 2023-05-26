extends Node2D

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
var _mouse_inside: bool = false


func set_direction(direction: Vector2):
	$UnitTemplate.direction = direction

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
	$UnitTemplate.get_node("ShootingSound").play()

	
	
	
func _ready():
	add_to_group("damageable")
	add_to_group("unit")
	$UnitTemplate.speed = speed
	$UnitTemplate.mouse_entered.connect(_mouse_enterd)
	$UnitTemplate.mouse_exited.connect(_mouse_exited)
		
func _mouse_enterd():
	_mouse_inside = true

func _mouse_exited():
	_mouse_inside = false	

func _process(delta):
	if Input.is_action_just_pressed("swtich_player") and _mouse_inside:
		var player = get_tree().get_first_node_in_group("player")
		get_parent().remove_child(self)
		player.add_child(self)
