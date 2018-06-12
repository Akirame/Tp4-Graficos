#include "HighScore.h"



HighScore::HighScore(int _length)
{
	lenght = _length;
	scoreList = new list<Score*>();
}


HighScore::~HighScore()
{
	delete scoreList;
}

void HighScore::AddScore(string _name, int _score)
{
	Score* add = new Score(_name, _score);
	scoreList->push_back(add);
	scoreList->sort();

	if (scoreList->size() >= lenght)
		scoreList->pop_back();
}

void HighScore::ShowScores()
{
	cout << "**************************************" << endl;
	cout << "**************HIGHSCORES**************" << endl;
	cout << "**************************************" << endl;

	list<Score*>::iterator it;
	int cont = 1;
	for (it = scoreList->begin(); it != scoreList->end(); it++)
	{
		Score* s = *it;
		cout << "N° "<< cont << s->GetName().c_str() << "    " << s->GetScore();
		cont++;
	}

	cout << "**************************************" << endl;
	cout << "**************************************" << endl;
	cout << "**************************************" << endl;
}


