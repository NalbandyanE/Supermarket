#ifndef PRICE_CALCULATOR_H
#define PRICE_CALCULATOR_H

#include "product.h"

class PriceCalculator {
public:
	static double calculate(const Product&);
private:
	static double calculateSimplePrice(const Product&);
	static double calculateThreeForDollarPrice(const Product&);
	static double calculatePricePerWeight(const Product&);
	static double calculateBuyTwoGetOnePrice(const Product&);
};

#endif