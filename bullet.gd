extends RigidBody2D

@export var damage = 0

# Called when the node enters the scene tree for the first time.
func _ready():
	body_entered.connect(_bullet_hit)
	$HitExplosion.animation_finished.connect(_hit_animation_finished)
	$HitExplosion.hide()
	


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass


func _bullet_hit(node: Node):
	if node.is_in_group("damageable"):
		node.do_damage(damage)
		
	$Sprite2D.hide()
	$CollisionShape2D.set_deferred("disabled", true)
	$HitExplosion.visible = true
	$HitExplosion.play()
	
	
func _hit_animation_finished():
	queue_free()
	
