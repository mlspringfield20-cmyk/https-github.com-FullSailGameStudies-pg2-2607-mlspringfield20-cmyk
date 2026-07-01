#pragma once
#include <string>
#include "enums.h"


class Card
{
public:
	Card(CardSuit suit, std::string face)
	{
		_suit = suit;
		_face = face;
	}

	CardSuit Suit() const { return _suit; }
	void Suit(CardSuit suit) { _suit = suit; }

	std::string Face() const { return _face; }
	void Face(std::string face) { _face = face; }

	int Value() const;
	int Compare(Card& otherCard) const;

	void Print()const;

private:
	CardSuit _suit;
	std::string _face;
};
