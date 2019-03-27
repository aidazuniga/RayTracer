#include "Exercise.h"

struct Projectile {
	Tuple position;
	Tuple velocity;

};

struct Environment {
	Tuple gravity;
	Tuple wind;
};

struct Projectile tick(struct Environment env, struct Projectile proj) {
	Tuple position = addTuples(proj.position, proj.velocity);
	Tuple velocity = addTuples(env.gravity, env.wind);
	velocity = addTuples(velocity, proj.velocity);

	return {position, velocity};
}

// -------------------------

void chapterOne(){
	std::cout << "Chapter 1 Exercise" << std::endl;

	Tuple pPos = createPoint(0, 1, 0);
	Tuple pVel = normalizeTuple(createVector(1, 1, 0));
	pVel = scalarMultiplyTuple(pVel, 1);	// play around with velocity
	struct Projectile p = {pPos, pVel};

	Tuple eGrav = createVector(0, -0.1, 0);
	Tuple eWind = createVector(-0.01, 0, 0);
	struct Environment e = {eGrav, eWind};

	int numTicks = 0;
	while(p.position.getY() > 0) {
		numTicks += 1;
		p = tick(e, p);
		std::cout << "projectile position: " << p.position.getX() << ", ";
		std::cout << p.position.getY() << std::endl;
	}
	std::cout << "numTicks: " << numTicks << std::endl;
}

void chapterTwo(){
	std::cout << "Chapter 2 Exercise" << std::endl;
}