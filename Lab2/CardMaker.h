#pragma once
#include "Card.h"
#include <vector>
#include "enums.h"

class CardMaker
{
public:
	static void GetCardsForAllSuits(std::vector<Card>& cards);
	static void GetCardsForSuit(const CardSuit& suit, std::vector<Card>& cards);
	static Card GetRandomCardForSuit(const CardSuit& suit);
	static void ShuffleCards(std::vector<Card>& cards);

private:

};

