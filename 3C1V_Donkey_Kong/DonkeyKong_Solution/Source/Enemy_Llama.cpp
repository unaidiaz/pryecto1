#include "Enemy_Llama.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

Enemy_Llama::Enemy_Llama(int x, int y,int direccion) : Enemy(x, y)
{
	llama.PushBack({ 0,63,15,17 });
	llama.PushBack({ 17, 64, 14, 16 });
	llama.PushBack({ 34, 66, 16, 13 });
	llama.loop = true;
	llama.speed = 0.1f;
	dire = direccion;
	
	currentAnim = &llama;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::Enemigo, (Module*)App->enemies);
}

void Enemy_Llama::Update()
{


	if (estado == state::recto) {
		position.x = position.x + (dire);
		
		estado = state::libre;
	}
	else if (estado == state::bajando) {
		position.y = position.y + 2;
		prior = 0;
	}
	else if (estado == state::libre) {
		if (dire == 1) {
			dire = -1;
		}
		else {
			dire = 1;
		}
		estado = state::recto;
	}
	
	frames++;
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();	
}

