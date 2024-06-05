#pragma once

#include "Component.h"
#include "Scene.h"

// La classe EnemyAttack herite de la classe Component et represente les proprietes physiques d'un GameObject dans le jeu.
class Score : public Component
{
public:
	Score();
	~Score();

	int GetScore() { return score; }
	void SetScore(int _score) { score = _score; }

	void IncrementScore(int _score) { score += _score; }

	// Methode pour mettre a jour le composant Score.
	void Update(float _delta_time) override;

private:

	int score;
};