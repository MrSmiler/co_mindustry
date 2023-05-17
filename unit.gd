extends CharacterBody2D

@export var BulletScene: PackedScene
const SPEED = 300
const bullet_speed = 500
var target = Vector2.ZERO

func _process(delta):
	if Input.is_action_just_pressed("shoot"):
		fire_bullet()

func fire_bullet():
	
	var velocity = Vector2.ZERO
	var bullet = BulletScene.instantiate()
	bullet.global_position = global_position
	var shoot_direction = global_position.direction_to(get_global_mouse_position())
	bullet.linear_velocity = shoot_direction * bullet_speed
	#bullet.position.y += fly_direction * (($CollisionShape2D.shape.size.y / 2) + 10)
	get_tree().get_root().add_child(bullet)
	$ShootingSound.play()


func _physics_process(delta):
	
	var direction = Input.get_vector("move_left", "move_right", "move_up", "move_down")
	velocity = direction * SPEED
	
	move_and_slide()
	look_at(direction + global_position)
