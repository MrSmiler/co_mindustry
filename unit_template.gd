extends CharacterBody2D

var direction = Vector2.ZERO
var speed = 0




func _physics_process(delta):
	
	velocity = direction * speed
	
	var collision = move_and_collide(velocity * delta)
	look_at(direction + global_position)

	

